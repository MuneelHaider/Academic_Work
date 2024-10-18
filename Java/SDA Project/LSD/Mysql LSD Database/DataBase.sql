CREATE DATABASE LSD;

USE LSD;

-- Serviceseeker Table
CREATE TABLE `serviceseeker` (
  `username` VARCHAR(20) PRIMARY KEY,
  `name` VARCHAR(50) NOT NULL,
  `date_of_birth` VARCHAR(10) NOT NULL,
  `gender` ENUM('Male', 'Female') NOT NULL,
  `email` VARCHAR(50) NOT NULL,
  `phone` VARCHAR(10) NOT NULL,
  `cnic` VARCHAR(13) NOT NULL UNIQUE,
  `address` VARCHAR(100) NOT NULL,
  `zipcode` VARCHAR(5) NOT NULL,
  `joining_date` VARCHAR(10) NOT NULL,
  `image` VARCHAR(255),
  FOREIGN KEY (`cnic`) REFERENCES `evc`(`cnic`)
);

-- Inserting into serviceseeker table
INSERT INTO serviceseeker (username, name, date_of_birth, gender, email, phone, cnic, address, zipcode, joining_date, image)
VALUES
('emma_thompson', 'Emma Thompson', '1992-03-18', 'Female', 'emma.thompson@example.com', '1234567890', '1234567890123', '123 Oak St, Town', '54321', '2019-05-15', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Emma Thompson.png'),
('lily_johnson', 'Lily Johnson', '1988-11-25', 'Female', 'lily.johnson@example.com', '9876543210', '9876543210123', '456 Maple St, City', '67890', '2019-05-15', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Lily Johnson.png'),
('isabella_rodriguez', 'Isabella Rodriguez', '1995-07-12', 'Female', 'isabella.rodriguez@example.com', '5551234567', '5551234567123', '789 Pine St, Village', '13579', '2019-05-15', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Isabella Rodriguez.png'),
('logan_mitchell', 'Logan Mitchell', '1998-01-30', 'Male', 'logan.mitchell@example.com', '7890123456', '7890123456123', '101 Cedar St, City', '24680', '2019-05-15', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Logan Mitchell.png'),
('caleb_williams', 'Caleb Williams', '1993-09-08', 'Male', 'caleb.williams@example.com', '5678901234', '5678901234123', '202 Elm St, Town', '97531', '2020-05-15', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Caleb Williams.png'),
('eren_yeager', 'Eren Yeager', '1996-12-05', 'Male', 'eren.yearger@example.com', '1230987654', '1230987654123', '303 Birch St, Village', '86420', '2021-05-15', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Eren Yeager.png'),
('aiden_walker', 'Aiden Walker', '1991-06-22', 'Male', 'aiden.walker@example.com', '8765432109', '8765432109123', '404 Pine St, City', '12345', '2023-09-11', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Aiden Walker.png'),
('lucas_bennett', 'Lucas Bennett', '1989-04-14', 'Male', 'lucas.bennett@example.com', '2345678901', '2345678901123', '505 Oak St, Town', '54321', '2023-01-05', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Lucas Bennett.png'),
('ava_thompson', 'Ava Thompson', '1994-10-03', 'Female', 'ava.thompson@example.com', '6789012345', '6789012345123', '606 Maple St, City', '67890', '2023-02-25', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Seekers/Ava Thompson.png');

-- Trigger to delete all the pending and cancelled bookings of a service seeker, if the service seeker is deleted from the database
DELIMITER //
CREATE TRIGGER BeforeServiceSeekerDelete
BEFORE DELETE ON serviceseeker
FOR EACH ROW
BEGIN
    DELETE FROM booking
    WHERE seeker_username = OLD.username AND status IN('Pending', 'Cancelled');
END;
//
DELIMITER ;

DROP TRIGGER IF EXISTS BeforeServiceSeekerDelete;

-- A query to find the number of service seekers who joined each year, limit to last 10y
SELECT YEAR(joining_date), COUNT(username) 
FROM serviceseeker
GROUP BY YEAR(joining_date)
ORDER BY YEAR(joining_date) DESC LIMIT 10;


CREATE TABLE `logincredentials` (
  `username` VARCHAR(20) PRIMARY KEY,
  `password` VARCHAR(30) NOT NULL,
  FOREIGN KEY (`username`) REFERENCES `serviceseeker`(`username`) ON DELETE CASCADE
);

-- Inserting into logincredentials table
-- regular users
INSERT INTO logincredentials (username, password) VALUES ('emma_thompson', 'password123');
INSERT INTO logincredentials (username, password) VALUES ('lily_johnson', 'password456');
INSERT INTO logincredentials (username, password) VALUES ('isabella_rodriguez', 'password789');
INSERT INTO logincredentials (username, password) VALUES ('logan_mitchell', 'password101');
INSERT INTO logincredentials (username, password) VALUES ('caleb_williams', 'password202');
INSERT INTO logincredentials (username, password) VALUES ('eren_yeager', 'password303');
INSERT INTO logincredentials (username, password) VALUES ('aiden_walker', 'password404');
INSERT INTO logincredentials (username, password) VALUES ('lucas_bennett', 'password505');
INSERT INTO logincredentials (username, password) VALUES ('ava_thompson', 'password606');

select * from logincredentials;
drop table logincredentials;


CREATE TABLE `suggestions` (
    `suggestion_id` INT PRIMARY KEY AUTO_INCREMENT,
    `seeker_username` VARCHAR(50),
    `comment` TEXT,
    `comment_date` DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (`seeker_username`) REFERENCES serviceseeker(`username`) ON DELETE SET NULL
);

INSERT INTO suggestions (seeker_username, comment) VALUES
('emma_thompson', 'Great service!'),
('lily_johnson', 'Prompt and efficient.'),
('isabella_rodriguez', 'Satisfied with the provided services.'),
('logan_mitchell', 'Very professional.'),
('caleb_williams', 'Excellent communication.'),
('eren_yeager', 'Highly recommended.'),
('aiden_walker', 'Impressed with the quality of service.'),
('lucas_bennett', 'Quick response and reliable.'),
('ava_thompson', 'Happy with the overall experience.');

select * from suggestions ORDER BY comment_date DESC;



