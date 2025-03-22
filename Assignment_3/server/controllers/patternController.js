const Pattern = require('../models/pattern');
const axios = require('axios');

exports.fetchAndSavePatterns = async (req, res) => {
  const { rt, pid } = req.params;
  const response = await axios.get(`https://ctabustracker.com/bustime/api/v3/getpatterns?key=ujAhaYu9dy6TAF2VgMLWK5nnV&rt=${rt}&pid=${pid}&format=json`);
  const patterns = response.data['bustime-response'].ptr;

  await Pattern.deleteMany({});
  await Pattern.insertMany(patterns || []);

  res.json({ message: 'Patterns fetched & saved', data: patterns });
};

exports.getPatterns = async (req, res) => res.json(await Pattern.find());

exports.updatePattern = async (req, res) => res.json(
  await Pattern.findOneAndUpdate({ pid: req.params.pid }, req.body, { new: true })
);

exports.deletePattern = async (req, res) => {
  await Pattern.findOneAndDelete({ pid: req.params.pid });
  res.json({ message: 'Deleted successfully' });
};
