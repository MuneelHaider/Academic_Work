const Direction = require('../models/direction');
const axios = require('axios');

exports.fetchAndSaveDirections = async (req, res) => {
  const { rt } = req.params;
  const response = await axios.get(`http://ctabustracker.com/bustime/api/v3/getdirections?key=ujAhaYu9dy6TAF2VgMLWK5nnV&rt=${rt}&format=json`);
  const directions = response.data['bustime-response'].directions;

  await Direction.deleteMany({});
  await Direction.insertMany(directions || []);

  res.json({ message: 'Directions fetched & saved', data: directions });
};

exports.getDirections = async (req, res) => res.json(await Direction.find());

exports.updateDirection = async (req, res) => res.json(
  await Direction.findOneAndUpdate({ id: req.params.id }, req.body, { new: true })
);

exports.deleteDirection = async (req, res) => {
  await Direction.findOneAndDelete({ id: req.params.id });
  res.json({ message: 'Deleted successfully' });
};
