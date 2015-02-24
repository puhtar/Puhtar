/* Name: Patrick Watts
 * Date: 2/13/15
 * Course: CSCE 1040
 * Program: Homework 01
 * Email: PatrickWatts@my.unt.edu
 * File: hw01_func_header.h
 * Purpose: File for the function headers involving hw01_funcs.c and hw01_main.
 *
 *
 *
 */
 #include "header.h"
 
 // Func prototypes
 void initial_print(void);
 
 int menu(void);
 
 void new_course(courses * c);
 
 void new_student(students * s);
 
 void add_course_student(courses * c, students * s);
 
 void add_course_grades(courses * c, students * s);
 
 void print_student_grades(courses * c, students * s);
 
 void print_course_students(courses * c, students * s);
 
 void student_average(courses * c, students * s);
 
 void list_courses(courses * c);
 
 void list_students(students * s);
 
 void course_average(courses * c);
 
 void store_grade_book(courses * c, students * s);
 
 void load_grade_book(courses * c, students * s);
 
 int student_match(students * s);

 int course_match(courses * c);
