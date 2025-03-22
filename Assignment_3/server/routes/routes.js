const router = require('express').Router();
const controller = require('../controllers/routeController');

router.get('/fetch', controller.fetchAndSaveRoutes);
router.get('/', controller.getRoutes);
router.put('/:rt', controller.updateRoute);
router.delete('/:rt', controller.deleteRoute);

module.exports = router;
