const express = require('express');
const mongoose = require('mongoose');
const dotenv = require('dotenv');
const cors = require('cors');
const vehicleRoutes = require('./routes/vehicles');
const routeRoutes = require('./routes/routes');
const directionRoutes = require('./routes/directions');
const stopRoutes = require('./routes/stops');
const patternRoutes = require('./routes/patterns');

dotenv.config();

const app = express();
app.use(express.json());
app.use(cors());

mongoose.connect(process.env.MONGO_URI, {
    useNewUrlParser: true,
    useUnifiedTopology: true
}).then(() => console.log('MongoDB Connected'))
  .catch(err => console.log(err));

app.use('/api/vehicles', vehicleRoutes);
app.use('/api/routes', routeRoutes);
app.use('/api/directions', directionRoutes);
app.use('/api/stops', stopRoutes);
app.use('/api/patterns', patternRoutes);

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
