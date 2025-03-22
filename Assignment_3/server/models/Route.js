const mongoose = require('mongoose');

const routeSchema = new mongoose.Schema({
    rt: String,
    rtnm: String,
    rtclr: String,
    rtdd: String
});

module.exports = mongoose.model('Route', routeSchema);
