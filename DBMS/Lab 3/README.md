## Lab 3



Set Operations


UNION (Use union all to retain duplicates):

1. Find courses that ran in Fall 2009 or in Spring 2010

INTERSECT (Use intersect all to retain duplicates):

2. Find courses that ran in Fall 2009 and in spring 2010

MINUS:


3. Find courses that ran in Fall 2009 but not in Spring 2010

Null values


4. Find the name of the course for which none of the students registered.


Nested Subqueries


Set Membership (in / not in):


5. Find courses offered in Fall 2009 and in Spring 2010.


6. Find the total number of students who have taken course taught by the instructor with ID 10101.


7. Find courses offered in Fall 2009 but not in Spring 2010.


8. Find the names of all students whose name is same as the instructor’s name.


Set Comparison (>=some/all)


9. Find names of instructors with salary greater than that of some (at least one) instructor
in the Biology department.


10. Find the names of all instructors whose salary is greater than the salary of all instructors in the Biology department.


11. Find the departments that have the highest average salary.


12. Find the names of those departments whose budget is lesser than the average salary of all instructors.
Test for Empty Relations (exists/ not exists)


13. Find all courses taught in both the Fall 2009 semester and in the Spring 2010 semester.


14. Find all students who have taken all courses offered in the Biology department.
Test for Absence of Duplicate Tuples


15. Find all courses that were offered at most once in 2009.


16. Find all the students who have opted at least two courses offered by CSE department.
Subqueries in the From Clause


17. Find the average instructors salary of those departments where the average salary is greater than 42000
Views


18. Create a view all_courses consisting of course sections offered by Physics department in the Fall 2009, with the building and room number of each section.


19. Select all the courses from all_courses view.


20. Create a view department_total_salary consisting of department name and total salary of that department.