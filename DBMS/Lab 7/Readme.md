## Lab 7


Note: Use University DB schema for the following, unless a different DB schema is explicitly specified


Cursors:


CursorName %ISOPEN / FOUND / NOT FOUND:


1. The HRD manager has decided to raise the salary of all the Instructors in a given department number by 5%. Whenever, any such raise is given to the instructor, a record for the same is maintained in the salary_raise table. It includes the Instuctor Id, the date when the raise was given and the actual raise amount. Write a PL/SQL block to update the salary of each Instructor and insert a record in the salary_raise table.
salary_raise(Instructor_Id, Raise_date, Raise_amt)


CursorName%ROWCOUNT:


2. Write a PL/SQL block that will display the ID, name, dept_name and tot_cred of the first 10 students with lowest total credit.


Cursor For Loops:


3. Print the Course details and the total number of students registered for each course along with the course details - (Course-id, title, dept-name, credits, instructor_name, building, room-number, time-slot-id, tot_student_no )


4. Find all students who take the course with Course-id: CS101 and if he/ she has less than 30 total credit (tot-cred), deregister the student from that course. (Delete the entry in Takes table)


Where Current of:


5. Alter StudentTable(refer Lab No. 8 Exercise) by resetting column LetterGrade to F. Then write a PL/SQL block to update the table by mapping GPA to the corresponding letter grade for each student.


Parameterized Cursors:


6. Write a PL/SQL block to print the list of Instructors teaching a specified course.


7. Write a PL/SQL block to list the students who have registered for a course taught by his/her advisor.


Transactions (COMMIT / ROLLBACK / SAVEPOINT):


8. Write a PL/SQL block that updates the salary of ‘Biology’ department instructors by 20%. Subsequently, check the whether the department budget can support the raise. If not, undo the raise given to the instructors.