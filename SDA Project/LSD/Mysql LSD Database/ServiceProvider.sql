CREATE TABLE `serviceprovider` (
    `username` VARCHAR(20) PRIMARY KEY,
    `name` VARCHAR(50) NOT NULL,
    `status` ENUM('Active', 'Inactive') NOT NULL,
    `date_of_birth` VARCHAR(10) NOT NULL,
    `gender` ENUM('Male', 'Female') NOT NULL,
    `email` VARCHAR(50) NOT NULL,
    `phone` VARCHAR(10) NOT NULL,
    `zipcode` VARCHAR(5) NOT NULL,
    `joining_date` VARCHAR(10) NOT NULL,
    `rating` DECIMAL(2, 1) NOT NULL,
    `image` VARCHAR(255)
);

-- Insertions for the serviceprovider table with usernames
INSERT INTO serviceprovider (username, name, status, date_of_birth, gender, email, phone, zipcode, joining_date, rating, image)
VALUES
('john_smith', 'John Smith', 'Active', '1980-05-15', 'Male', 'john.smith@example.com', '1234567890', '54321', '2011-05-15', 4.5, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/John Smith.png'),
('emily_johnson', 'Emily Johnson', 'Active', '1992-09-28', 'Female', 'emily.johnson@example.com', '9876543210', '67890', '2021-05-15', 4.8, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Emily Johnson.png'),
('michael_brown', 'Michael Brown', 'Active', '1985-03-12', 'Male', 'michael.brown@example.com', '5678901234', '67890', '2018-05-15', '4.2', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Michael Brown.png'),
('samantha_davis', 'Samantha Davis', 'Active', '1990-11-07', 'Female', 'samantha.davis@example.com', '2345678901', '24680', '2016-05-15', 4.6, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Samantha Davis.png'),
('david_wilson', 'David Wilson', 'Active', '1988-07-23', 'Male', 'david.wilson@example.com', '3456789012', '97531', '2019-05-15', '4.4', 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/David Wilson.png');


INSERT INTO serviceprovider (username, name, status, date_of_birth, gender, email, phone, zipcode, joining_date, rating, image)
VALUES
('alex_taylor', 'Alex Taylor', 'Active', '1975-04-20', 'Male', 'alex.taylor@services.com', '5551010101', '12345', '2019-08-10', 4.7, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Alex Taylor.png'),
('maria_gonzalez', 'Maria Gonzalez', 'Active', '1983-12-05', 'Female', 'maria.gonzalez@services.com', '5552020202', '23456', '2020-03-15', 4.9, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Maria Gonzalez.png'),
('liam_nguyen', 'Liam Nguyen', 'Active', '1990-09-30', 'Male', 'liam.nguyen@services.com', '5553030303', '34567', '2021-07-20', 4.6, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Liam Nguyen.png'),
('nora_khan', 'Nora Khan', 'Active', '1978-06-15', 'Female', 'nora.khan@services.com', '5554040404', '45678', '2021-11-11', 4.8, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Nora Khan.png'),
('ethan_lee', 'Ethan Lee', 'Active', '1982-01-22', 'Male', 'ethan.lee@services.com', '5555050505', '56789', '2021-02-28', 4.5, 'D:\\IntellijProjects\\LSD/src/main/resources/Images/Service Providers/Ethan Lee.png');


-- Trigger to delete all the pending and cancelled bookings done by a service provider, if the service provider is deleted from the database
DELIMITER //
CREATE TRIGGER BeforeServiceProviderDelete
BEFORE DELETE ON serviceprovider
FOR EACH ROW
BEGIN
    DELETE FROM booking
    WHERE provider_username = OLD.username AND status IN('Pending', 'Cancelled');
END;
//
DELIMITER ;


DROP TRIGGER IF EXISTS BeforeServiceProviderDelete;

-- A query to find the number of service seekers who joined each year, limit to last 10y
SELECT YEAR(joining_date), COUNT(username) 
FROM serviceprovider
GROUP BY YEAR(joining_date)
ORDER BY YEAR(joining_date) DESC LIMIT 10;



-- Create the 'categories' table
CREATE TABLE `categories` (
    `id` INT PRIMARY KEY,
    `name` VARCHAR(255),
    `price` DECIMAL(5, 2) -- New 'price' attribute
);


-- Insertions for the categories with category id and random prices between $50 and $100
INSERT INTO categories (id, name, price) VALUES
(1, 'Plumber', ROUND(RAND() * (100 - 50) + 50, 2)),
(2, 'Electrician', ROUND(RAND() * (100 - 50) + 50, 2)),
(3, 'Roofer', ROUND(RAND() * (100 - 50) + 50, 2)),
(4, 'Builder', ROUND(RAND() * (100 - 50) + 50, 2)),
(5, 'Gardener', ROUND(RAND() * (100 - 50) + 50, 2)),
(6, 'Painter', ROUND(RAND() * (100 - 50) + 50, 2)),
(7, 'Landscaper', ROUND(RAND() * (100 - 50) + 50, 2)),
(8, 'Carpenter', ROUND(RAND() * (100 - 50) + 50, 2)),
(9, 'Plasterer', ROUND(RAND() * (100 - 50) + 50, 2)),
(10, 'Driveways', ROUND(RAND() * (100 - 50) + 50, 2)),
(11, 'Fencing', ROUND(RAND() * (100 - 50) + 50, 2)),
(12, 'Tree surgeon', ROUND(RAND() * (100 - 50) + 50, 2)),
(13, 'Handyman', ROUND(RAND() * (100 - 50) + 50, 2)),
(14, 'Locksmith', ROUND(RAND() * (100 - 50) + 50, 2)),
(15, 'Bathrooms', ROUND(RAND() * (100 - 50) + 50, 2)),
(16, 'Tiler', ROUND(RAND() * (100 - 50) + 50, 2)),
(17, 'Central heating', ROUND(RAND() * (100 - 50) + 50, 2)),
(18, 'Boiler repair', ROUND(RAND() * (100 - 50) + 50, 2));



-- No more than 3 categories
CREATE TABLE `provider_categories` (
    `provider_username` VARCHAR(20),
    `category_id` INT,
    PRIMARY KEY (`provider_username`, `category_id`),
    FOREIGN KEY (`provider_username`) REFERENCES serviceprovider(`username`) ON DELETE CASCADE,
    FOREIGN KEY (`category_id`) REFERENCES categories(`id`) ON DELETE CASCADE
);

-- Insertions for the provider_categories table with usernames and category id
-- John Smith is a plumber and electrician
INSERT INTO provider_categories (provider_username, category_id) VALUES
('john_smith', 1), -- plumber
('john_smith', 2); -- electrician

-- Emily Johnson is an electrician and tiler
INSERT INTO provider_categories (provider_username, category_id) VALUES
('emily_johnson', 2), -- electrician
('emily_johnson', 16); -- tiler

-- Michael Brown is a roofer and builder
INSERT INTO provider_categories (provider_username, category_id) VALUES
('michael_brown', 3), -- roofer
('michael_brown', 4); -- builder

-- Samantha Davis is a builder and landscaper
INSERT INTO provider_categories (provider_username, category_id) VALUES
('samantha_davis', 4), -- builder
('samantha_davis', 7); -- landscaper

-- David Wilson is a gardener and landscaper
INSERT INTO provider_categories (provider_username, category_id) VALUES
('david_wilson', 5), -- gardener
('david_wilson', 7); -- landscaper





-- Alex Taylor is a plumber, electrician, and central heating
INSERT INTO provider_categories (provider_username, category_id) VALUES
('alex_taylor', 1), -- plumber
('alex_taylor', 2), -- electrician
('alex_taylor', 17); -- Central heating

-- Maria Gonzalez is a gardener, landscaper, and tree surgeon
INSERT INTO provider_categories (provider_username, category_id) VALUES
('maria_gonzalez', 5), -- gardener
('maria_gonzalez', 7), -- landscaper
('maria_gonzalez', 12); -- tree surgeon

-- Maria Gonzalez is a builder, carpenter, and plasterer
INSERT INTO provider_categories (provider_username, category_id) VALUES
('liam_nguyen', 4), -- builder
('liam_nguyen', 8), -- carpenter
('liam_nguyen', 9); -- plasterer

-- Nora Khan is a painter, handyman, and tiler
INSERT INTO provider_categories (provider_username, category_id) VALUES
('nora_khan', 6), -- painter
('nora_khan', 13), -- handyman
('nora_khan', 16); -- tiler

-- Ethan Lee is a locksmith, driveways, and fencing
INSERT INTO provider_categories (provider_username, category_id) VALUES
('ethan_lee', 14), -- locksmith
('ethan_lee', 10), -- driveways
('ethan_lee', 11); -- fencing



drop table provider_categories;
drop table categories;
drop table serviceprovider;



-- A query that displays the roles(categories) of the service providers
SELECT sp.username AS provider_username, c.name AS category_name
FROM serviceprovider sp
INNER JOIN provider_categories pc ON sp.username = pc.provider_username
INNER JOIN categories c ON pc.category_id = c.id;


-- A query that displays the roles of a specific service provider, directly from the provdier_categories table
SELECT c.id, c.name
                FROM provider_categories pc  
                JOIN categories c ON pc.category_id = c.id 
                WHERE pc.provider_username = "david_wilson"



