-- creating table
CREATE TABLE employee (
emp_no INTEGER PRIMARY KEY,
emp_name varchar(20),
emp_address varchar(50)

);



-- inserting values
INSERT INTO employee VALUES (1, 'TOM', 'MANIPAL');
INSERT INTO employee VALUES (2, 'SID', 'MANGALORE');
INSERT INTO employee VALUES (3, 'JACK', 'MANIPAL');
INSERT INTO employee VALUES (4, 'JOHN', 'PUNE');
INSERT INTO employee VALUES (5, 'HARRY', 'MANGALORE');



-- displaying names
SELECT emp_name FROM employee;



-- displaying all employees from manipal
SELECT * FROM employee where emp_address='MANIPAL';



-- Adding salary column to table
ALTER TABLE employee ADD salary INTEGER;



-- Assigning salaries for employees
UPDATE employee set salary=10000 WHERE emp_no=1;
UPDATE employee set salary=20000 WHERE emp_no=2;
UPDATE employee set salary=30000 WHERE emp_no=3;
UPDATE employee set salary=40000 WHERE emp_no=4;
UPDATE employee set salary=50000 WHERE emp_no=5;



SELECT * FROM employee;
DESC employee;
DELETE FROM employee WHERE emp_address='MANGALORE';
SELECT * FROM employee;



ALTER TABLE employee RENAME TO employee1;
DROP TABLE employee1;