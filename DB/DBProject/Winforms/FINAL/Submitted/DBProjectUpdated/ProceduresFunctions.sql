use DBProject;

-- Add admin procedure

CREATE PROCEDURE RegisterAdmin
    @userName VARCHAR(250),
    @userPassword VARCHAR(250),
    @userEmail VARCHAR(250),
    @userRole VARCHAR(250),
    @profileName VARCHAR(250),
    @profileAddress VARCHAR(250),
    @profileCNIC VARCHAR(250),
    @profileDOB DATE, 
    @profileGender VARCHAR(1),
    @profileContact VARCHAR(250)

AS BEGIN
   
    INSERT INTO users (userName, userPassword, userEmail, userRole)
    VALUES (@userName, @userPassword, @userEmail, @userRole);

    DECLARE @userID INT;
    SET @userID = SCOPE_IDENTITY();

    INSERT INTO profile (userID, profileName, profileAddress, profileCNIC, profileDOB, profileGender, profileContact)
    VALUES (@userID, @profileName, @profileAddress, @profileCNIC, @profileDOB, @profileGender, @profileContact);

    INSERT INTO admin (userID)
    VALUES (@userID);

END

EXEC RegisterAdmin 
    @userName = 'Muneel', 
    @userPassword = '1234', 
    @userEmail = 'muneelhaider@gmail.com', 
    @userRole = 'Admin',
    @profileName = 'Muneel Haider',
    @profileAddress = 'Islamabad',
    @profileCNIC = '61101-4614698-3',
    @profileDOB = '2002-07-25', 
    @profileGender = 'M',
    @profileContact = '03088828430';

drop procedure RegisterAdmin

select *
from profile

DELETE FROM admin;

--------------------------------------------------------------------------------
