const mongoose = require('mongoose');

const stopSchema = new mongoose.Schema({
    stpid: String,
    stpnm: String,
    lat: Number,
    lon: Number
});

module.exports = mongoose.model('Stop', stopSchema);
