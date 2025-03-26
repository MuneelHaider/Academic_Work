const Stop = require('../models/stop');
const axios = require('axios');

exports.fetchAndSaveStops = async (req, res) => {
  try {
    const { rt, dir } = req.params;
    const { data } = await axios.get(`https://ctabustracker.com/bustime/api/v3/getstops`, {
      params: { key: process.env.CTA_API_KEY, rt, dir, format: 'json' }
    });

    const stops = data['bustime-response'].stops || [];
    await Stop.deleteMany();
    await Stop.insertMany(stops);

    res.json({ message: 'Stops fetched & saved', count: stops.length });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

exports.getStops = async (req, res) => {
  const stops = await Stop.find();
  res.json(stops);
};

exports.updateStop = async (req, res) => {
  const updated = await Stop.findOneAndUpdate({ stpid: req.params.stpid }, req.body, { new: true });
  res.json(updated);
};

exports.deleteStop = async (req, res) => {
  await Stop.findOneAndDelete({ stpid: req.params.stpid });
  res.json({ message: 'Stop deleted successfully' });
};
