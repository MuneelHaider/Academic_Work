const Direction = require('../models/direction');
const axios = require('axios');

exports.fetchAndSaveDirections = async (req, res) => {
  try {
    const { rt } = req.params;
    const { data } = await axios.get(`https://ctabustracker.com/bustime/api/v3/getdirections`, {
      params: { key: process.env.CTA_API_KEY, rt, format: 'json' }
    });

    const directions = data['bustime-response'].directions || [];
    await Direction.deleteMany();
    await Direction.insertMany(directions);

    res.json({ message: 'Directions fetched & saved', count: directions.length });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

exports.getDirections = async (req, res) => {
  const directions = await Direction.find();
  res.json(directions);
};

exports.updateDirection = async (req, res) => {
  const updated = await Direction.findOneAndUpdate({ id: req.params.id }, req.body, { new: true });
  res.json(updated);
};

exports.deleteDirection = async (req, res) => {
  await Direction.findOneAndDelete({ id: req.params.id });
  res.json({ message: 'Direction deleted successfully' });
};
