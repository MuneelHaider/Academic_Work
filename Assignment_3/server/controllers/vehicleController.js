const Vehicle = require('../models/vehicle');
const axios = require('axios');

exports.fetchAndSaveVehicles = async (req, res) => {
  try {
    const { vid } = req.params;
    const { data } = await axios.get(`https://ctabustracker.com/bustime/api/v3/getvehicles`, {
      params: { key: process.env.CTA_API_KEY, vid, format: 'json' }
    });

    const vehicles = data['bustime-response'].vehicle || [];
    await Vehicle.deleteMany();
    await Vehicle.insertMany(vehicles);

    res.json({ message: 'Vehicles fetched & saved', count: vehicles.length });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

exports.getVehicles = async (req, res) => {
  const vehicles = await Vehicle.find();
  res.json(vehicles);
};

exports.updateVehicle = async (req, res) => {
  const updated = await Vehicle.findOneAndUpdate({ vid: req.params.vid }, req.body, { new: true });
  res.json(updated);
};

exports.deleteVehicle = async (req, res) => {
  await Vehicle.findOneAndDelete({ vid: req.params.vid });
  res.json({ message: 'Vehicle deleted successfully' });
};
