import { useState, useEffect } from 'react';
import './App.css';

function App() {
  const [routes, setRoutes] = useState([]);
  const [selectedRoute, setSelectedRoute] = useState('');
  const [vehicles, setVehicles] = useState([]);
  const [stops, setStops] = useState([]);
  const [directions, setDirections] = useState([]);
  const [selectedDirection, setSelectedDirection] = useState('');
  const [systemTime, setSystemTime] = useState(null);
  const [patterns, setPatterns] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const API_KEY = 'ujAhaYu9dy6TAF2VgMLWK5nnV';
  const BASE_URL = 'https://ctabustracker.com/bustime/api/v2';

  useEffect(() => {
    fetchRoutes();
  }, []);

  useEffect(() => {
    if (selectedRoute) {
      fetchDirections(selectedRoute);
      fetchVehicles(selectedRoute);
    }
  }, [selectedRoute]);

  useEffect(() => {
    if (selectedRoute && selectedDirection) {
      fetchStops(selectedRoute, selectedDirection);
    }
  }, [selectedRoute, selectedDirection]);

  const fetchSystemTime = async () => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch(`${BASE_URL}/gettime?key=${API_KEY}&format=json`);
      const data = await response.json();
      setSystemTime(data['bustime-response'].tm);
    } catch (error) {
      setError('Error fetching system time');
      console.error('Error fetching system time:', error);
    }
    setLoading(false);
  };

  const fetchRoutes = async () => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch(`${BASE_URL}/getroutes?key=${API_KEY}&format=json`);
      const data = await response.json();
      setRoutes(data['bustime-response'].routes || []);
    } catch (error) {
      setError('Error fetching routes');
      console.error('Error fetching routes:', error);
    }
    setLoading(false);
  };

  const fetchDirections = async (route) => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch(`${BASE_URL}/getdirections?key=${API_KEY}&rt=${route}&format=json`);
      const data = await response.json();
      setDirections(data['bustime-response'].directions || []);
    } catch (error) {
      setError('Error fetching directions');
      console.error('Error fetching directions:', error);
    }
    setLoading(false);
  };

  const fetchVehicles = async (route) => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch(`${BASE_URL}/getvehicles?key=${API_KEY}&rt=${route}&format=json`);
      const data = await response.json();
      setVehicles(data['bustime-response'].vehicles || []);
    } catch (error) {
      setError('Error fetching vehicles');
      console.error('Error fetching vehicles:', error);
    }
    setLoading(false);
  };

  const fetchStops = async (route, direction) => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch(`${BASE_URL}/getstops?key=${API_KEY}&rt=${route}&dir=${direction}&format=json`);
      const data = await response.json();
      setStops(data['bustime-response'].stops || []);
    } catch (error) {
      setError('Error fetching stops');
      console.error('Error fetching stops:', error);
    }
    setLoading(false);
  };

  const fetchPatterns = async () => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch(`${BASE_URL}/getpatterns?key=${API_KEY}&rt=20&pid=954&format=json`);
      const data = await response.json();
      setPatterns(data['bustime-response'].ptr || []);
    } catch (error) {
      setError('Error fetching patterns');
      console.error('Error fetching patterns:', error);
    }
    setLoading(false);
  };

  return (
    <div className="app">
      <header className="header">
        <h1>CTA Bus Tracker</h1>
      </header>

      <main className="main">
        <section className="api-buttons">
          <h2>API Actions</h2>
          <div className="button-grid">
            <button onClick={fetchSystemTime} disabled={loading}>Get System Time</button>
            <button onClick={() => fetchVehicles('20')} disabled={loading}>Get Vehicles (Route 20)</button>
            <button onClick={fetchRoutes} disabled={loading}>Get Routes</button>
            <button onClick={() => fetchDirections('20')} disabled={loading}>Get Directions (Route 20)</button>
            <button onClick={() => fetchStops('7', 'Eastbound')} disabled={loading}>Get Stops (Route 7 Eastbound)</button>
            <button onClick={fetchPatterns} disabled={loading}>Get Patterns (Route 20)</button>
          </div>

          {loading && <div className="loading">Loading...</div>}
          {error && <div className="error">{error}</div>}
          
          {systemTime && (
            <div className="result-card">
              <h3>System Time</h3>
              <p>{systemTime}</p>
            </div>
          )}
        </section>

        {selectedRoute && (
          <section className="direction-selector">
            <h2>Select Direction</h2>
            <select
              value={selectedDirection}
              onChange={(e) => setSelectedDirection(e.target.value)}
            >
              <option value="">Select a direction...</option>
              {directions.map(direction => (
                <option key={direction.dir} value={direction.dir}>
                  {direction.dir}
                </option>
              ))}
            </select>
          </section>
        )}

        {vehicles.length > 0 && (
          <section className="vehicles">
            <h2>Active Vehicles</h2>
            <div className="vehicles-grid">
              {vehicles.map(vehicle => (
                <div key={vehicle.vid} className="vehicle-card">
                  <h3>Bus #{vehicle.vid}</h3>
                  <p>Destination: {vehicle.des}</p>
                  <p>Speed: {vehicle.spd} mph</p>
                  <p>Delayed: {vehicle.dly ? 'Yes' : 'No'}</p>
                </div>
              ))}
            </div>
          </section>
        )}

        {stops.length > 0 && (
          <section className="stops">
            <h2>Bus Stops</h2>
            <div className="stops-grid">
              {stops.map(stop => (
                <div key={stop.stpid} className="stop-card">
                  <h3>{stop.stpnm}</h3>
                  <p>Stop ID: {stop.stpid}</p>
                </div>
              ))}
            </div>
          </section>
        )}

        {patterns.length > 0 && (
          <section className="patterns">
            <h2>Route Patterns</h2>
            <div className="patterns-grid">
              {patterns.map(pattern => (
                <div key={pattern.pid} className="pattern-card">
                  <h3>Pattern #{pattern.pid}</h3>
                  <p>Length: {pattern.ln}</p>
                  <p>Direction: {pattern.rtdir}</p>
                </div>
              ))}
            </div>
          </section>
        )}
      </main>
    </div>
  );
}

export default App;