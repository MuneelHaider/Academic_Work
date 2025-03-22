const router = require('express').Router();
const controller = require('../controllers/stopController');

router.get('/fetch/:rt/:dir', controller.fetchAndSaveStops);
router.get('/', controller.getStops);
router.put('/:stpid', controller.updateStop);
router.delete('/:stpid', controller.deleteStop);

module.exports = router;
