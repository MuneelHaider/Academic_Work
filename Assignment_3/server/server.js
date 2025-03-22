const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
const dotenv = require('dotenv');

dotenv.config();

const app = express();

app.use(express.json());
app.use(cors());

mongoose.connect(process.env.MONGO_URI)
  .then(() => console.log('MongoDB Connected'))
  .catch(err => console.log(err));

app.use('/api/vehicles', require('./routes/vehicles'));
app.use('/api/routes', require('./routes/routes'));
app.use('/api/directions', require('./routes/directions'));
app.use('/api/stops', require('./routes/stops'));
app.use('/api/patterns', require('./routes/patterns'));

app.listen(process.env.PORT || 5000, () => console.log('Server started'));
