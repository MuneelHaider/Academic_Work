const router = require('express').Router();
const controller = require('../controllers/vehicleController');

router.get('/fetch/:vid', controller.fetchAndSaveVehicles);
router.get('/', controller.getVehicles);
router.put('/:vid', controller.updateVehicle);
router.delete('/:vid', controller.deleteVehicle);

module.exports = router;
