import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './App.css';
import AddBookForm from './components/AddBookForm';
import BookDetails from './components/BookDetails';

function App() {
  const [books, setBooks] = useState([]);
  const [showAddBook, setShowAddBook] = useState(false);
  const [selectedBook, setSelectedBook] = useState(null);

  useEffect(() => {
    fetchBooks();
  }, []);

  const fetchBooks = async () => {
    try {
      const response = await axios.get('http://localhost:5000/api/books');
      setBooks(response.data);
    } catch (error) {
      console.error('Error fetching books:', error);
    }
  };

  const handleAddBook = async (newBook) => {
    try {
      const response = await axios.post('http://localhost:5000/api/books', newBook);
      setBooks([...books, response.data]);
      setShowAddBook(false);
    } catch (error) {
      console.error('Error adding book:', error);
    }
  };

  const handleAddReview = async (bookId, review) => {
    try {
      const response = await axios.post(`http://localhost:5000/api/books/${bookId}/reviews`, review);
      setBooks(books.map(book => book._id === bookId ? response.data : book));
    } catch (error) {
      console.error('Error adding review:', error);
    }
  };

  return (
    <div className="app">
      <header className="header">
        <div className="header-content">
          <h1>Book Reviews</h1>
          <button className="add-book-btn" onClick={() => setShowAddBook(true)}>
            Add Book
          </button>
        </div>
      </header>
      <main className="book-grid">
        {books.map(book => (
          <div 
            key={book._id} 
            className="book-card"
            onClick={() => setSelectedBook(book)}
          >
            <div className="book-image">
              <img src={book.image} alt={book.title} />
            </div>
            <div className="book-info">
              <h2>{book.title}</h2>
              <h3>{book.author}</h3>
              <p>{book.description}</p>
              <div className="review-count">
                {book.reviews.length} reviews
              </div>
            </div>
          </div>
        ))}
      </main>

      {showAddBook && (
        <AddBookForm 
          onSubmit={handleAddBook}
          onClose={() => setShowAddBook(false)}
        />
      )}

      {selectedBook && (
        <BookDetails 
          book={selectedBook}
          onClose={() => setSelectedBook(null)}
          onAddReview={handleAddReview}
        />
      )}
    </div>
  );
}

export default App;
