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

create table demos(

	demosID int primary key identity,
	taID int,
	demosDate date,
	demosStatus int,
	demosMarks int,

	foreign key(taID) references ta(taID)
);

create table ld(

	ldID int primary key identity,
	userID int,
	courseID int,

	foreign key(userID) references users(userID)
);

create table lab(

	labID int primary key identity,
	ldID int,
	labMarks int,
	labDate date,

	foreign key(ldID) references ld(ldID)
);

create table attendence(

	attendenceID int primary key identity,
	ldID int,
	facultyID int,
	attendenceChar varchar(1),
	attendenceDate date,

	foreign key(ldID) references ld(ldID),
	foreign key(facultyID) references faculty(facultyID)
);

create table task(

	taskID int primary key identity,
	facultyID int,
	taskDescription varchar(250),
	taskDueDate date, 
	taskStatus int,

	foreign key(facultyID) references faculty(facultyID)
);

create table feedback(

	feedbackID int primary key identity,
	userID int,
	feedbackDescription varchar(250),
	feedbackDate date,

	foreign key(userID) references users(userID)
);

