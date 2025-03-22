const mongoose = require('mongoose');

const patternSchema = new mongoose.Schema({
    pid: Number,
    ln: Number,
    rtdir: String,
    pt: Array
});

module.exports = mongoose.model('Pattern', patternSchema);
