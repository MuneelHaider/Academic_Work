const Route = require('../models/route');
const axios = require('axios');

exports.fetchAndSaveRoutes = async (req, res) => {
  const response = await axios.get(`http://ctabustracker.com/bustime/api/v3/getroutes?key=ujAhaYu9dy6TAF2VgMLWK5nnV&format=json`);
  const routes = response.data['bustime-response'].routes;

  await Route.deleteMany({});
  await Route.insertMany(routes || []);

  res.json({ message: 'Routes fetched & saved', data: routes });
};

exports.getRoutes = async (req, res) => res.json(await Route.find());

exports.updateRoute = async (req, res) => res.json(
  await Route.findOneAndUpdate({ rt: req.params.rt }, req.body, { new: true })
);

exports.deleteRoute = async (req, res) => {
  await Route.findOneAndDelete({ rt: req.params.rt });
  res.json({ message: 'Deleted successfully' });
};
