## Lab 2

Consider the following schema:


Employee (EmpNo, EmpName, Gender, Salary, Address, DNo)


Department (DeptNo, DeptName, Location)
1. Create Employee table with following constraints:

 Make EmpNo as Primary key.

 Do not allow EmpName, Gender, Salary and Address to have null values.

 Allow Gender to have one of the two values: ‘M’, ‘F’.


2. Create Department table with following:

 Make DeptNo as Primary key

 Make DeptName as candidate key



3. Make DNo of Employee as foreign key which refers to DeptNo of Department.


4. Insert few tuples into Employee and Department which satisfies the above constraints.


5. Try to insert few tuples into Employee and Department which violates some of the above constraints.


6. Try to modify/delete a tuple which violates a constraint.
(Ex: Drop a department tuple which has one or more employees)


7. Modify the foreign key constraint of Employee table such that whenever a department tuple is deleted, the employees belonging to that department will also be deleted.
Naming Constraints:


8. Create a named constraint to set the default salary to 10000 and test the constraint by
inserting a new record.
University Database Schema:

Student (ID, name,dept-name, tot-cred)

Instructor(ID, name, dept-name, salary)

Course (Course-id, title,dept-name, credits)

Takes (ID, course-id, sec-id, semester, year, grade)

Classroom (building, room-number, capacity)

Department (dept-name, building, budget)

Section (course-id, section-id, semester, year, building, 
room-number, time-slot-id)

Teaches (id, course-id, section-id, semester, year)

Advisor(s-id, i-id)

Time-slot (time-slot-id, day, start-time, end-time)

Prereq (course-id, prereq-id)

(Use University database for the exercise problems given below)
Retrieving records from a table:


9. List all Students with names and their department names.


10. List all instructors in CSE department.


11. Find the names of courses in CSE department which have 3 credits.


12. For the student with ID 12345 (or any other value), show all course-id and title of all courses registered for by the student.


13. List all the instructors whose salary is in between 40000 
    and 90000.


Retrieving records from multiple tables:


14. Display the IDs of all instructors who have never taught a course.


15. Find the student names, course names, and the year, for all students those who have attended classes in room-number 303.


Rename and Tuple Variables (Use as in select and from):


16. For all students who have opted courses in 2015, find their names and course id’s with the attribute course title replaced by c-name.


17. Find the names of all instructors whose salary is greater than the salary of at least one instructor of CSE department and salary replaced by inst-salary.
String Operations (Use %, _, LIKE):


18. Find the names of all instructors whose department name includes the substring ‘ch’.
Built-in Functions:


19. List the student names along with the length of the student names.


20. List the department names and 3 characters from 3rd position of each department name


21. List the instructor names in upper case.


22. Replace NULL with value1(say 0) for a column in any of the table


23. Display the salary and salary/3 rounded to nearest hundred from Instructor.
Add date of birth column (DOB) to Employee Table. Insert appropriate DOB values for different employees and try the exercise problems given below:


24. Display the birth date of all the employees in the following format:

 ‘DD-MON-YYYY’

 ‘DD-MON-YY’

 ‘DD-MM-YY’


25. List the employee names and the year (fully spelled out) in which they are born

 ‘YEAR’

 ‘Year’

 ‘year’


26. List the employee names and the day of the week (fully spelled out) in which they are born

 ‘DAY’

 ‘Day’


27.  List the employee names and the month(fully spelled out) in which they are born

 ‘MONTH’

 ‘Month’



28. Find the last day of the month(and its day of the week) in which employee Mr. X is born


29. Find the age of all the employees


30. Find the Saturday following the Employee’s 60th birthday


31. List the employees whose birthday falls in the given year X


32. List the employees whose birthday fall between the given years X and Y


33. List the employees who will retire on the given year X.