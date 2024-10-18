create database LAB12;
use LAB12;

/*
 
 Muneel Haider
 21i-0640
 LAB 12

*/

create table users(

	userID int identity(1,1) primary key,
	userName varchar(250),
	userPassword varchar(250)
);

create table tasks(

	taskID int identity(1,1) primary key,
	userID int,
	taskName varchar(250),
	taskDescription varchar(250),
	taskStatus int,

	foreign key(userID) references users(userID)
);


INSERT INTO tasks (userID, taskName, taskDescription, taskStatus) 
VALUES 
(1, 'Task 1 for UserID 1', 'Insert Data.', 0),
(1, 'Task 2 for UserID 1', 'Clean Data', 0),
(1, 'Task 3 for UserID 1', 'Finalize Data', 0);


INSERT INTO tasks (userID, taskName, taskDescription, taskStatus) 
VALUES 
(2, 'Task 1 for User 2', 'Design Software', 0),
(2, 'Task 2 for User 2', 'Write Code for Software', 0),
(2, 'Task 3 for User 2', 'Push into Git', 0);


INSERT INTO tasks (userID, taskName, taskDescription, taskStatus) 
VALUES 
(3, 'Task 1 for User 3', 'Request Pull from Git', 0),
(3, 'Task 2 for User 3', 'Integrate with System Environment', 0),
(3, 'Task 3 for User 3', 'Deploy', 0);


SELECT t.taskID, t.taskName, t.taskDescription, t.taskStatus FROM tasks t INNER JOIN users u ON t.userID = u.userID WHERE u.userName = 'Muneel'
