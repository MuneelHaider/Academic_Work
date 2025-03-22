const Vehicle = require('../models/vehicle');
const axios = require('axios');

exports.fetchAndSaveVehicles = async (req, res) => {
  const { vid } = req.params;
  const response = await axios.get(`https://ctabustracker.com/bustime/api/v3/getvehicles?key=mMyphiiTdRckeGxemRLzJUFCZ&vid=${vid}&format=json`);
  const vehicles = response.data['bustime-response'].vehicle;

  await Vehicle.deleteMany({});
  await Vehicle.insertMany(vehicles || []);

  res.json({ message: 'Vehicles fetched & saved', data: vehicles });
};

exports.getVehicles = async (req, res) => res.json(await Vehicle.find());

exports.updateVehicle = async (req, res) => res.json(
  await Vehicle.findOneAndUpdate({ vid: req.params.vid }, req.body, { new: true })
);

exports.deleteVehicle = async (req, res) => {
  await Vehicle.findOneAndDelete({ vid: req.params.vid });
  res.json({ message: 'Deleted successfully' });
};
