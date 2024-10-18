CREATE TABLE `booking` (
    `booking_id` INT PRIMARY KEY,
    `seeker_username` VARCHAR(20),
    `provider_username` VARCHAR(20),
    `booking_date` DATETIME NOT NULL,
    `service_type_id` INT, 
    `status` ENUM('Pending', 'Completed', 'Cancelled') NOT NULL DEFAULT 'Pending',
    `description` TEXT,
	`image` VARCHAR(255),
    FOREIGN KEY (`seeker_username`) REFERENCES `serviceseeker`(`username`) ON DELETE SET NULL,
    FOREIGN KEY (`provider_username`) REFERENCES `serviceprovider`(`username`) ON DELETE SET NULL,
    FOREIGN KEY (`service_type_id`) REFERENCES `categories`(`id`) ON DELETE CASCADE
);

-- Date format: year, month, day
INSERT INTO booking (booking_id, seeker_username, provider_username, booking_date, service_type_id, status, description, image)
VALUES
(1, 'aiden_walker', 'john_smith', '2023-01-11 10:00:00', 1, 'Completed', 'Meeting for consultation.', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Issues/Plumbing.png'),
(2, 'aiden_walker', 'emily_johnson', '2023-01-11 13:00:00', 2, 'Completed', 'Fitness training session.', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Issues/Electric.png'),
(3, 'ava_thompson', 'samantha_davis', '2023-12-08 09:30:00', 3, 'Pending', 'Appointment canceled by seeker.', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Issues/Roofing.png'),
(4, 'aiden_walker', 'samantha_davis', '2023-02-11 11:00:00', 1, 'Cancelled', 'Regular checkup and service.', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Issues/Plumbing_2.png'),
(5, 'ava_thompson', 'samantha_davis', '2023-02-11 11:00:00', 1, 'Completed', 'Regular checkup and service.', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Issues/Plumbing_2.png'),
(6, 'ava_thompson', 'samantha_davis', '2023-12-06 11:00:00', 1, 'Completed', 'Regular checkup and service.', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Issues/Plumbing_2.png');


-- A query that returns the unavailable slots of a service provider
SELECT TIME(booking_date) as slot_time FROM booking WHERE provider_username = "samantha_davis" AND DATE(booking_date) = '2023-12-01';

-- A query that returns all the bookings done, limit 10
SELECT DATE(booking_date) as dateOnly, status, COUNT(booking_id) FROM booking GROUP BY dateOnly, status ORDER BY dateOnly DESC LIMIT 10;

-- A query that counts the number of bookings done each day, limit 10
SELECT DATE(booking_date), COUNT(booking_id)
FROM booking
GROUP BY DATE(booking_date)
ORDER BY DATE(booking_date) DESC LIMIT 10;

-- A query that counts the number of Bookings placed today
SELECT COUNT(*) FROM booking WHERE DATE(booking_date) = CURDATE();


-- A query that Counts the Bookings based on status of a specific service provider
SELECT status, COUNT(*) AS count FROM booking WHERE provider_username = 'samantha_davis' GROUP BY status;



CREATE TABLE `payment` (
    `payment_id` INT AUTO_INCREMENT PRIMARY KEY,
    `booking_id` INT,
    `amount` DECIMAL(10, 2) NOT NULL,
    `payment_date` DATETIME NOT NULL,
    `payment_method` ENUM('Card', 'Cash') NOT NULL,
    FOREIGN KEY (`booking_id`) REFERENCES `booking`(`booking_id`) ON DELETE CASCADE
);


INSERT INTO payment (booking_id, amount, payment_date, payment_method)
VALUES
(1, 100.00, '2023-01-11 12:00:00', 'Card'),
(2, 150.00, '2023-01-11 13:00:00', 'Card'),
(5, 150.00, '2023-02-11 13:00:00', 'Card');


-- A query that sums the amount made by bookings done each day, limit 10
SELECT DATE(booking_date), SUM(p.amount) 
FROM booking b INNER JOIN payment p
ON b.booking_id = p.booking_id
GROUP BY DATE(b.booking_date)
ORDER BY DATE(b.booking_date) DESC LIMIT 10;


CREATE TABLE `review` (
    `review_id` INT AUTO_INCREMENT PRIMARY KEY,
    `booking_id` INT,
    `rating` DECIMAL(2, 1) CHECK (rating >= 0.0 AND rating <= 5.0),
    FOREIGN KEY (`booking_id`) REFERENCES `booking`(`booking_id`) ON DELETE CASCADE
);


INSERT INTO review (booking_id, rating)
VALUES
(1, 4.5),
(2, 4.2),
(5, 4.1),
(6, 4.4);



-- A query that displays the rating given by service seekers to the service providers
SELECT 
    ss.name AS service_seeker_name, 
    sp.name AS service_provider_name, 
    r.rating AS rating_given
FROM booking b JOIN serviceseeker ss ON b.seeker_username = ss.username
JOIN serviceprovider sp ON b.provider_username = sp.username
JOIN review r ON b.booking_id = r.booking_id;


-- A query that displays the total no. of ratings received by service providers
-- LEFT JOIN is used to include all service providers, even those who haven't received any ratings.
SELECT 
    sp.username, 
    COUNT(r.review_id) AS number_of_ratings
FROM serviceprovider sp LEFT JOIN booking b ON sp.username = b.provider_username
LEFT JOIN review r ON b.booking_id = r.booking_id
GROUP BY 
    sp.username, sp.name;


