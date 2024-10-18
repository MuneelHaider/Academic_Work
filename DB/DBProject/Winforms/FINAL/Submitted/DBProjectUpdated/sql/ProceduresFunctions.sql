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

select *
from users

--------------------------------------------------------------------------------

CREATE PROCEDURE InsertFaculty
    @userName VARCHAR(250),
    @userPassword VARCHAR(250),
    @userEmail VARCHAR(250),
    @userRole VARCHAR(250),
    @profileName VARCHAR(250),
    @profileAddress VARCHAR(250),
    @profileCNIC VARCHAR(250),
    @profileDOB DATE, 
    @profileGender VARCHAR(1),
    @profileContact VARCHAR(250),
    @facultyDepartment VARCHAR(250),
    @facultyOffice VARCHAR(250)
AS
BEGIN
    
	INSERT INTO users (userName, userPassword, userEmail, userRole)
    VALUES (@userName, @userPassword, @userEmail, @userRole);

    
	DECLARE @userID INT = SCOPE_IDENTITY();

    
	INSERT INTO profile (userID, profileName, profileAddress, profileCNIC, profileDOB, profileGender, profileContact)
    VALUES (@userID, @profileName, @profileAddress, @profileCNIC, @profileDOB, @profileGender, @profileContact);

    
	INSERT INTO faculty (userID, facultyDepartment, facultyOffice)
    VALUES (@userID, @facultyDepartment, @facultyOffice);
END

-------------------------------------------------------------------------

CREATE PROCEDURE RemoveFaculty
    @userName VARCHAR(250)
AS BEGIN
    
	DECLARE @userID INT;
    SELECT @userID = userID FROM users WHERE userName = @userName;

    
	IF @userID IS NOT NULL
    BEGIN
    
		DELETE FROM faculty WHERE userID = @userID;
        
		DELETE FROM profile WHERE userID = @userID;

		DELETE FROM users WHERE userID = @userID;
    END
END

------------------------------------------------------------------------

CREATE TRIGGER trg_Users_Insert
ON users
AFTER INSERT
AS BEGIN
    
	INSERT INTO auditlogs (auditName, auditType, auditTime)
    VALUES ('users', 'INSERT', GETDATE());

END;

CREATE TRIGGER trg_Users_Delete
ON users
AFTER DELETE
AS BEGIN
    
	INSERT INTO auditlogs (auditName, auditType, auditTime)
    VALUES ('users', 'DELETE', GETDATE());

END;

-----------------------------------------------------------------

CREATE TRIGGER trg_Course_Delete
ON course
AFTER DELETE
AS BEGIN

    INSERT INTO auditlogs (auditName, auditType, auditTime)
    VALUES ('course', 'DELETE', GETDATE());

END;

CREATE TRIGGER trg_Course_Insert
ON course
AFTER INSERT
AS BEGIN

    INSERT INTO auditlogs (auditName, auditType, auditTime)
    VALUES ('course', 'INSERT', GETDATE());

END;

------------------------------------------------------------------