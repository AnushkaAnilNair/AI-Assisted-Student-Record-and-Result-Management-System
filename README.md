# AI-Assisted Student Record and Result Management System

**Name:** Anushka Anil Nair  
**SAP ID:** 590032073  
**Course:** Programming in C (PRC1001)  
**Semester:** B.Tech CSE, Semester 1  
**University:** University of Petroleum and Energy Studies (UPES)

## Project Description

This project is a menu-driven Student Record and Result Management System developed using C programming.
The program stores student information, calculates CGPA, sorts student records and provides academic 
advice based on students' performance.

## Features

1. Display all student records.
2. Add new student details.
3. Search for a student using SAP ID.
4. Delete an individual student record.
5. Calculate CGPA of each student.
6. Calculate average CGPA of students belonging to each year.
7. Display students in increasing order of SAP ID.
8. Display students in alphabetical order of name.
9. Provide academic advice based on CGPA.

## Student Details Stored

The program stores the following information:

- SAP ID
- Roll Number
- Name
- Phone Number
- Email ID
- Year
- Semester
- SGPA for all eight semesters

The program initially contains five student records. More records can be added through the menu.

## C Programming Concepts Used

- Structures
- Arrays
- Functions
- Loops
- Conditional statements
- Switch-case
- Strings
- Sorting

## CGPA Calculation

CGPA is calculated by taking the average of available SGPA values.

**CGPA = Sum of available SGPA values / Number of available SGPA values**

SGPA values entered as zero represent unavailable results and are not included in the calculation.

## AI-Assisted Academic Advisor

The academic advisor provides recommendations using `if-else` conditions based on CGPA.

| CGPA Range | Recommendation |
|---|---|
| 9.0–10.0 | Excellent Performance |
| 7.0–below 9.0 | Good Performance |
| 5.0–below 7.0 | Needs Improvement |
| Above 0–below 5.0 | Requires Immediate Attention |

The AI tool was used to help design the advice categories. The recommendations are generated directly 
by the C program without using any external AI API.

## How to Run the Program

1. Download the file `590032073.c`.
2. Open it in a C programming environment.
3. Compile the program using a C compiler.
4. Run the program.
5. Select the required option from the menu.

For GCC, compile using:

`gcc 590032073.c -o student`

Run using:

`./student`

On Windows, run `student.exe`.

## Limitations

The program stores student records temporarily in memory. Changes are not saved permanently after the 
program closes.

## Conclusion

This project helped me understand and apply basic C programming concepts such as structures, arrays, 
functions, searching, sorting and conditional statements. It also helped me learn how AI tools can 
assist in developing program logic and how GitHub can be used to manage a programming project.
