LAB EXERCISE:

NOTE: Use a table StudentTable(RollNo, GPA) and populate the table with {(1, 5.8); (2, 6.5); (3, 3.4); (4,7.8); (5, 9.5)} unless a different DB schema is explicitly specified.

1. Write a PL/SQL block to display the GPA of given student.
Usage of IF –THEN:

2. Write a PL/SQL block to display the letter grade(0-4: F; 4-5: E; 5-6: D; 6-7: C; 7-8: B; 8-9: A; 9-10: A+} of given student.


3. Input the date of issue and date of return for a book. Calculate and display the fine with the appropriate message using a PL/SQL block. The fine is charged as per the table 8.1:

Late period Fine
7 days NIL

8 – 15 days Rs.1/day

16 - 30 days Rs. 2/ day

After 30 days Rs. 5.00

Simple LOOP:

4. Write a PL/SQL block to print the letter grade of all the students(RollNo: 1 - 5).
Usage of WHILE:

5. Alter StudentTable by appending an additional column LetterGrade Varchar2(2). Then write a PL/SQL block to update the table with letter grade of each student.

Usage of FOR:

6. Write a PL/SQL block to find the student with max. GPA without using aggregate function.

Usage of GOTO:

7. Implement lab exercise 4 using GOTO.

Exception Handling:


8. Based on the University database schema, write a PL/SQL block to display the details of the Instructor whose name is supplied by the user. Use exceptions to show appropriate error message for the following cases:

a. Multiple instructors with the same name

b. No instructor for the given name

9. Extend lab exercise 5 to validate the GPA value used to find letter grade. If it is outside the range, 0 – 10, display an error message, ‘Out of Range’ via an exception handler.
