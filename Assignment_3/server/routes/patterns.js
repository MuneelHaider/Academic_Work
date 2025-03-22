const router = require('express').Router();
const controller = require('../controllers/patternController');

router.get('/fetch/:rt/:pid', controller.fetchAndSavePatterns);
router.get('/', controller.getPatterns);
router.put('/:pid', controller.updatePattern);
router.delete('/:pid', controller.deletePattern);

module.exports = router;
