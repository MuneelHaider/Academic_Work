const Stop = require('../models/stop');
const axios = require('axios');

exports.fetchAndSaveStops = async (req, res) => {
  const { rt, dir } = req.params;
  const response = await axios.get(`https://ctabustracker.com/bustime/api/v3/getstops?key=ujAhaYu9dy6TAF2VgMLWK5nnV&rt=${rt}&dir=${dir}&format=json`);
  const stops = response.data['bustime-response'].stops;

  await Stop.deleteMany({});
  await Stop.insertMany(stops || []);

  res.json({ message: 'Stops fetched & saved', data: stops });
};

exports.getStops = async (req, res) => res.json(await Stop.find());

exports.updateStop = async (req, res) => res.json(
  await Stop.findOneAndUpdate({ stpid: req.params.stpid }, req.body, { new: true })
);

exports.deleteStop = async (req, res) => {
  await Stop.findOneAndDelete({ stpid: req.params.stpid });
  res.json({ message: 'Deleted successfully' });
};
