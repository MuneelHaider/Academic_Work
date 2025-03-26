const Pattern = require('../models/pattern');
const axios = require('axios');

exports.fetchAndSavePatterns = async (req, res) => {
  try {
    const { rt, pid } = req.params;
    const { data } = await axios.get(`https://ctabustracker.com/bustime/api/v3/getpatterns`, {
      params: { key: process.env.CTA_API_KEY, rt, pid, format: 'json' }
    });

    const patterns = data['bustime-response'].ptr || [];
    await Pattern.deleteMany();
    await Pattern.insertMany(patterns);

    res.json({ message: 'Patterns fetched & saved', count: patterns.length });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

exports.getPatterns = async (req, res) => {
  const patterns = await Pattern.find();
  res.json(patterns);
};

exports.updatePattern = async (req, res) => {
  const updated = await Pattern.findOneAndUpdate({ pid: req.params.pid }, req.body, { new: true });
  res.json(updated);
};

exports.deletePattern = async (req, res) => {
  await Pattern.findOneAndDelete({ pid: req.params.pid });
  res.json({ message: 'Pattern deleted successfully' });
};
