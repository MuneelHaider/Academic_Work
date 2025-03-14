import React, { useState } from 'react';

function BookDetails({ book, onClose, onAddReview }) {
  const [review, setReview] = useState('');
  const [rating, setRating] = useState(5);

  const handleSubmitReview = (e) => {
    e.preventDefault();
    onAddReview(book._id, {
      text: review,
      rating: rating,
      date: new Date().toISOString()
    });
    setReview('');
    setRating(5);
  };

  return (
    <div className="modal-overlay" onClick={onClose}>
      <div className="modal-content book-details" onClick={e => e.stopPropagation()}>
        <div className="book-details-image">
          <img src={book.image} alt={book.title} />
        </div>
        <div className="book-details-info">
          <h2>{book.title}</h2>
          <h3>{book.author}</h3>
          <p>{book.description}</p>
          
          <div className="reviews-section">
            <h4>Reviews ({book.reviews.length})</h4>
            <div className="reviews-list">
              {book.reviews.map(review => (
                <div key={review._id} className="review-item">
                  <div className="review-rating">
                    {'★'.repeat(review.rating)}{'☆'.repeat(5-review.rating)}
                  </div>
                  <p>{review.text}</p>
                  <small>{new Date(review.date).toLocaleDateString()}</small>
                </div>
              ))}
            </div>

            <form onSubmit={handleSubmitReview} className="review-form">
              <h4>Write a Review</h4>
              <div className="form-group">
                <label htmlFor="rating">Rating</label>
                <select
                  id="rating"
                  value={rating}
                  onChange={(e) => setRating(Number(e.target.value))}
                  className="rating-select"
                >
                  {[1,2,3,4,5].map(num => (
                    <option key={num} value={num}>{num} ★</option>
                  ))}
                </select>
              </div>
              <div className="form-group">
                <label htmlFor="review">Your Review</label>
                <textarea
                  id="review"
                  value={review}
                  onChange={(e) => setReview(e.target.value)}
                  required
                />
              </div>
              <button type="submit" className="submit-btn">Submit Review</button>
            </form>
          </div>
        </div>
        <button className="close-btn" onClick={onClose}>×</button>
      </div>
    </div>
  );
}

export default BookDetails;
