const router = require('express').Router();
const controller = require('../controllers/directionController');

router.get('/fetch/:rt', controller.fetchAndSaveDirections);
router.get('/', controller.getDirections);
router.put('/:id', controller.updateDirection);
router.delete('/:id', controller.deleteDirection);

module.exports = router;
