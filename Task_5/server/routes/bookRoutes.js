const express = require('express');
const router = express.Router();
const Book = require('../models/Book');

// Get all books
router.get('/', async (req, res) => {
  try {
    const books = await Book.find();
    res.json(books);
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});

// Get a single book
router.get('/:id', async (req, res) => {
  try {
    const book = await Book.findById(req.params.id);
    if (!book) return res.status(404).json({ message: 'Book not found' });
    res.json(book);
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});

// Add a new book
router.post('/', async (req, res) => {
  try {
    const { title, author, description, image } = req.body;
    const newBook = new Book({ title, author, description, image, reviews: [] });
    const savedBook = await newBook.save();
    res.status(201).json(savedBook);
  } catch (error) {
    res.status(400).json({ message: error.message });
  }
});

// Add a review to a book
router.post('/:id/reviews', async (req, res) => {
  try {
    const { text, rating } = req.body;
    const book = await Book.findById(req.params.id);
    if (!book) return res.status(404).json({ message: 'Book not found' });

    const newReview = { text, rating, date: new Date() };
    book.reviews.push(newReview);
    await book.save();

    res.json(book);
  } catch (error) {
    res.status(400).json({ message: error.message });
  }
});

module.exports = router;
