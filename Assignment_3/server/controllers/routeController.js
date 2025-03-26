const Route = require('../models/route');
const axios = require('axios');

exports.fetchAndSaveRoutes = async (req, res) => {
  try {
    const { data } = await axios.get(`https://ctabustracker.com/bustime/api/v3/getroutes`, {
      params: { key: process.env.CTA_API_KEY, format: 'json' }
    });

    const routes = data['bustime-response'].routes || [];
    await Route.deleteMany();
    await Route.insertMany(routes);

    res.json({ message: 'Routes fetched & saved', count: routes.length });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

exports.getRoutes = async (req, res) => {
  const routes = await Route.find();
  res.json(routes);
};

exports.updateRoute = async (req, res) => {
  const updated = await Route.findOneAndUpdate({ rt: req.params.rt }, req.body, { new: true });
  res.json(updated);
};

exports.deleteRoute = async (req, res) => {
  await Route.findOneAndDelete({ rt: req.params.rt });
  res.json({ message: 'Route deleted successfully' });
};
