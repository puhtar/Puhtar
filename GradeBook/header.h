#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 2

typedef struct
{
    int student_id;
    int grades_count;
    int grades_max;
    int *grades;
} grade;

typedef struct
{
    int student_id;
    char first_name[30];
    char last_name[30];
} student;

typedef struct
{
    int course_id;
    char course_name[30];
    int grades_count;
    int grades_max;
    grade *grades;
} course;

typedef struct
{
    int student_count;
    int student_max;
    student *student_list;
} students;

typedef struct
{
    int course_count;
    int course_max;
    course *course_list;
} courses;