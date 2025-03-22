const mongoose = require('mongoose');

const directionSchema = new mongoose.Schema({
    id: String,
    name: String
});

module.exports = mongoose.model('Direction', directionSchema);
