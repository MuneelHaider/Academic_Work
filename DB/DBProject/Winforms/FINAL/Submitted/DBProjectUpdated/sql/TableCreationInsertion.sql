create database DBProject;
use DBProject;

drop database DBProject;
use [LAB 6];

create table users(

	userID int primary key identity,
	userName varchar(250),
	userPassword varchar(250),
	userEmail varchar(250),
	userRole varchar(250),
);

create table profile(

	profileID int primary key identity,
	userID int,
	profileName varchar(250),
	profileAddress varchar(250),
	profileCNIC varchar(250),
	profileDOB date, 
	profileGender varchar(1),
	profileContact varchar(250),

	foreign key(userID) references users(userID)
);

create table roles(

	roleID int primary key identity,
	userID int,
	roleName varchar(250),

	foreign key(userID) references users(userID)
);

create table admin(

	adminID int primary key identity,
	userID int,

	foreign key(userID) references users(userID)
);

create table faculty(

	facultyID int primary key identity,
	userID int,
	facultyDepartment varchar(250),
	facultyOffice varchar(250),

	foreign key(userID) references users(userID)
);

create table course(

	courseID int primary key identity,
	facultyID int,
	courseName varchar(250),
	
	foreign key(facultyID) references faculty(facultyID)
);

create table ta(

	taID int primary key identity,
	userID int,
	courseID int,
	taAvailability int,

	foreign key(courseID) references course(courseID),
	foreign key(userID) references users(userID),
);

create table ld(

	ldID int primary key identity,
	userID int,
	courseID int,

	foreign key(userID) references users(userID),
	foreign key(courseID) references course(courseID)
);

create table lab(

	labID int primary key identity,
	ldID int,
	labName varchar(250),
	labDate date,
	labStatus int,
	labDescription varchar(250),

	foreign key(ldID) references ld(ldID)
);

create table taskTA(

	taskID int primary key identity,
	facultyID int,
	taID int,
	taskName varchar(250),
	taskDescription varchar(250),
	taskDueDate date, 
	taskStatus int,

	foreign key(facultyID) references faculty(facultyID),
	foreign key(taID) references ta(taID)
);

create table feedback(

	feedbackID int primary key identity,
	userID int,
	feedbackDescription varchar(250),
	feedbackDate date,

	foreign key(userID) references users(userID)
);

create table auditlogs(

	auditlogID int primary key identity,
	auditName varchar(250),
	auditType varchar(250),
	auditTime datetime,
);