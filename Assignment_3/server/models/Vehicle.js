const mongoose = require('mongoose');

const vehicleSchema = new mongoose.Schema({
    vid: String,
    tmstmp: String,
    lat: Number,
    lon: Number,
    hdg: Number,
    pid: Number,
    rt: String,
    des: String,
    pdist: Number,
    spd: Number,
    tatripid: String,
    origtatripno: String,
    dly: Boolean
});

module.exports = mongoose.model('Vehicle', vehicleSchema);
