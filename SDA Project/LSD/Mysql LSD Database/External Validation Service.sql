-- External Validation Service
CREATE TABLE `evc` (
    `cnic` VARCHAR(13),
    `name` VARCHAR(50) NOT NULL,
    `date_of_birth` VARCHAR(10) NOT NULL,
    `gender` ENUM('Male', 'Female') NOT NULL,
    PRIMARY KEY(`cnic`)
);

DROP TABLE evc;

SELECT * FROM evc;

-- Inserting into evc table
INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('1234567890123', 'Emma Thompson', '1992-03-18', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('9876543210123', 'Lily Johnson', '1988-11-25', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('5551234567123', 'Isabella Rodriguez', '1995-07-12', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('7890123456123', 'Logan Mitchell', '1998-01-30', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('5678901234123', 'Caleb Williams', '1993-09-08', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('1230987654123', 'Eren Yaeger', '1996-12-05', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('8765432109123', 'Aiden Walker', '1991-06-22', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('2345678901123', 'Lucas Bennett', '1989-04-14', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('6789012345123', 'Ava Thompson', '1994-10-03', 'Female');



-- Not yet Made an Account
-- Inserting into evc table
INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('3332221110000', 'John Doe', '1985-08-20', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('4445556667777', 'Jane Smith', '1990-05-12', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('8887776665555', 'Michael Johnson', '1976-12-03', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('1112223334444', 'Emily Davis', '1982-09-15', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('9998887776666', 'Christopher White', '1997-07-28', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('6665554443333', 'Sophia Martinez', '1989-04-02', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('4443332221111', 'Ethan Taylor', '2000-11-08', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('7776665554444', 'Olivia Brown', '1995-03-22', 'Female');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('2221110009999', 'Matthew Miller', '1987-06-17', 'Male');

INSERT INTO evc (cnic, name, date_of_birth, gender)
VALUES ('5554443332222', 'Emma Wilson', '1993-10-31', 'Female');





