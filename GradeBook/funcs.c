/* Name: Patrick Watts
 * Date: 2/13/15
 * Course: CSCE 1040
 * Program: Homework 01
 * Email: PatrickWatts@my.unt.edu
 * File: hw01_funcs.c
 * Purpose: Various functions for the menu options for hw01_main.c
 *
 *
 *
 */
 #include "func_header.h"
 
 // Functions
 
 void initial_print(void){
	 printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	 "Department of Computer Science and Engineering",
	 "CSCE 1040",
	 "Program: Homework 01",
	 "Name: Patrick Watts",
	 "EUID: ptw0021",
	 "Email: PatrickWatts@my.unt.edu",
	 "Date: 2/15/2015");
	 
	 return;
 }
 
 int menu(void){
	int option = 0;
	
	printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
	"Menu Options",
	"1. Add a new course",
	"2. Add a new student",
	"3. Add a student to a course",
	"4. Add grades for a student in a course",
	"5. Print a list of all grades for a student in a course",
	"6. Print a list of all students in a course",
	"7. Compute the average for a student in a course",
	"8. Print a list of all courses",
	"9. Print a list of all students",
	"10. Compute the average for a course",
	"11. Store Grade Book (to a disk file)",
	"12. Load Grade Book (from a disk file)",
	"Please use a number 1-12:");
	scanf("%d",&option);
	getchar();
	
	if (option < 1 || option > 12){
		printf("Please use a number 1-12! Try again.");
		menu();
	}
	 
	return option; 
 }
 
 void new_course(courses * c){
	 int i, course_id;
	 char option = 'n';
	 
	 if (c->course_count == c->course_max) 
		{
			course *temp;
			temp = (course *) realloc(c->course_list, sizeof(course) *(c->course_max + CHUNKSIZE));
			c->course_max += CHUNKSIZE;
			c->course_list = temp;
         
            grade *grade_temp;
	        grade_temp = (grade *) malloc(sizeof(grade) * CHUNKSIZE);
	        c->course_list[c->course_count].grades_max += CHUNKSIZE;
	        c->course_list[c->course_count].grades = grade_temp;
	        c->course_list[c->course_count].grades_count = 0;
            c->course_list[c->course_count].grades[0].grades_count = c->course_list[c->course_count].grades[0].grades_count = c->course_list[c->course_count].grades[0].student_id = 0;
         
            
		}
	 
	 printf("\nWhat is the course id number:");
	 scanf("%d%*c", &(c->course_list[c->course_count].course_id));

	 printf("\nWhat is the course name:");
	 scanf("%s", c->course_list[c->course_count].course_name);
	 
	 printf("\n%s %d %s\n", c->course_list[c->course_count].course_name, c->course_list[c->course_count].course_id, "added.");
	 
	 c->course_count += 1;
     
	 return;
}

void new_student(students * s){
	int i, j, id_number;
	
	if (s->student_count == s->student_max) 
		{
			student *temp;
			temp = (student *) realloc(s->student_list, sizeof(student) *(s->student_max + CHUNKSIZE));
			s->student_max += CHUNKSIZE;
			s->student_list = temp;
		}
	
	printf("\nWhat is the student's id number:");
	scanf("%d", &(s->student_list[s->student_count].student_id));
	
	for(i = 0; i < s->student_count; i++){
		if(s->student_list[i].student_id == s->student_list[s->student_count].student_id){
			printf("\nThe student id already exists! Try again.");
			s->student_max -= CHUNKSIZE;
			return;
		}
	}
	
	printf("\nWhat is the first name of the student:");
	scanf("%s", s->student_list[s->student_count].first_name);
	
	printf("\nWhat is the last name of the student:");
	scanf("%s", s->student_list[s->student_count].last_name);
	
	printf("\n%d %s %s %s\n", s->student_list[s->student_count].student_id, s->student_list[s->student_count].first_name, s->student_list[s->student_count].last_name, "added.");
	
	s->student_count += 1;
	
	return;
}

void add_course_student(courses * c, students * s){
	int i = 0, j = 0, k = 0, course_id, student_id;
	
	i = course_match(c);
	
	if(i == -1)
		return;

	j = student_match(s);
	
	if(j == -1)
		return;
       
	for(k = 0; k <= c->course_list[i].grades_count; k++){
		if(c->course_list[i].grades[k].student_id == s->student_list[j].student_id){
			printf("\n%s %s is already in the class.", s->student_list[j].first_name, s->student_list[j].last_name);
			return;
		}
		
		if(c->course_list[i].grades[k].student_id == 0){
			c->course_list[i].grades[k].student_id = s->student_list[j].student_id;
			printf("\n%s %s added to %s.", s->student_list[j].first_name, s->student_list[j].last_name, c->course_list[i].course_name);
            
            if (c->course_list[i].grades_count == c->course_list[i].grades_max)
                {
                    grade *grade_temp;
	                grade_temp = (grade *) realloc(c->course_list[i].grades, sizeof(int) *(c->course_list[i].grades_max + CHUNKSIZE));
	                c->course_list[i].grades_max += CHUNKSIZE;
	                c->course_list[i].grades = grade_temp;
                    c->course_list[i].grades[c->course_list[i].grades_count + 1].grades_count = c->course_list[i].grades[c->course_list[i].grades_count + 1].grades_max = c->course_list[i].grades[c->course_list[i].grades_count + 1].student_id = 0;
            }
            if (c->course_list[i].grades[k].grades_count == c->course_list[i].grades[k].grades_max)
					{
						int *temp;
						temp = (int *) malloc(sizeof(int) * CHUNKSIZE);
						c->course_list[i].grades[k].grades_max += CHUNKSIZE;
						c->course_list[i].grades[k].grades = temp;
					}
           
			break;
		}
		
		if(k == 20){
			printf("\nThe class is full. Try another class.");
			return;
		}
	}
	
    c->course_list[i].grades_count += 1;
    
	return;
}
 
 void add_course_grades(courses * c, students * s){
	int i, j, k, l, f = 1;
	char choice = 'y';
	
	i = course_match(c);
	if(i == -1)
		return;
	
	j = student_match(s);
	if(j == -1)
		return;
	
	for(k=0; k<c->course_list[i].grades_count; k++)
		if(c->course_list[i].grades[k].student_id == s->student_list[j].student_id && c->course_list[i].grades[k].student_id != 0){
		
			while(choice == 'y'){
				if (c->course_list[i].grades[k].grades_count == c->course_list[i].grades[k].grades_max)
					{
						int *temp;
						temp = (int *) realloc(c->course_list[i].grades[k].grades, sizeof(int) *(c->course_list[i].grades[k].grades_max + CHUNKSIZE));
						c->course_list[i].grades[k].grades_max += CHUNKSIZE;
						c->course_list[i].grades[k].grades = temp;
					}
						
				printf("\nGrade %d:",f);
				scanf("%d", &c->course_list[i].grades[k].grades[l]);
				f++;
				getchar();
				
				printf("\nAny more grades (y/n):");
				choice = getchar(); 
			    
                c->course_list[i].grades[k].grades_count++;
            }
		}
		
	return;
}
 
 void print_student_grades(courses * c, students * s){
	int i, j, k, l, f = 1;
	
	i = course_match(c);
	
	if(i == -1)
		return;
		
	j = student_match(s);
	
	if(j == -1)
		return;
		
	for(k=0; k<c->course_list[i].grades_count; k++){
		if(c->course_list[i].grades[k].student_id == s->student_list[j].student_id && c->course_list[i].grades[k].student_id != 0){
			printf("\n%s %s Grades\n", s->student_list[j].first_name, s->student_list[j].last_name);
			for(l=0; l<c->course_list[i].grades[k].grades_count; l++){	
				printf("\nGrade %3d: %5d", f, c->course_list[i].grades[k].grades[l]);
				f++;
			}
		}
		if(k==19 && c->course_list[i].grades[k].student_id != (0 && s->student_list[j].student_id))
			printf("\n%s %s is not in %s! Try again.\n", s->student_list[j].first_name, s->student_list[j].last_name, c->course_list[i].course_name);
	}
	
	return;
}
 
 void print_course_students(courses * c, students * s){
	int i, j, k, course_id, student_id;
	
	i = course_match(c);
	
	if(i == -1)
		return;
	
	printf("\n%s %d\n", c->course_list[i].course_name, c->course_list[i].course_id);
	printf("\n%15s%15s%15s\n", "ID Number", "First Name", "Last Name");
	
	for(j=0; j<100; j++)
		for(k=0; k<20; k++)
			if(c->course_list[i].grades[k].student_id == s->student_list[j].student_id && c->course_list[i].grades[k].student_id != 0)
				printf("\n%15d%15s%15s\n", s->student_list[j].student_id, s->student_list[j].first_name, s->student_list[j].last_name);
		
	return;
 }
 
 void student_average(courses * c, students * s){
	int i, j, k, l, total = 0, average;
	
	i = course_match(c);
	
	if(i == -1)
		return;
	
	j = student_match(s);
	
	if(j == -1)
		return;
		
	for(k=0; k<c->course_list[i].grades_count; k++){
		if(c->course_list[i].grades[k].student_id == s->student_list[j].student_id && c->course_list[i].grades[k].student_id != 0){
			for(l=0; l<c->course_list[i].grades[k].grades_count; l++){	
				total += c->course_list[i].grades[k].grades[l];
			}
			break;
		}
		if(k==(c->course_list[i].grades_count - 1) && c->course_list[i].grades[k].student_id != s->student_list[j].student_id)
			printf("\n%s %s is not in %s! Try again.\n", s->student_list[j].first_name, s->student_list[j].last_name, c->course_list[i].course_name);
	}
	
	average =(int)total / (int)l;
	
	printf("\n%s %s Average: %d", s->student_list[j].first_name, s->student_list[j].last_name, average);
	
	return;
 }
 
 void list_courses(courses * c){
	 int i = 0;
	 
	 printf("\n%15s%10s","Course Name", "Course ID");
	  
	 for(i=0;i<c->course_count;i++){
		printf("\n%15s%10d", c->course_list[i].course_name, c->course_list[i].course_id);
	 }
	
	 printf("\n");
	 
	 return;
 }
 
 void list_students(students * s){
	 int i = 0;
	 
	 printf("\n%s\n%15s%15s%15s", "Student List", "ID Number", "First Name", "Last Name");
	 
	 for(i=0;i<s->student_count;i++){
		 printf("\n%15d%15s%15s", s->student_list[i].student_id, s->student_list[i].first_name, s->student_list[i].last_name);
	 }
	 
	 printf("\n");
	 
	 return;
 }
 
 void course_average(courses * c){
	 int i, j, k, grades_count = 0, total = 0, average;
	 
	 i = course_match(c);
	 if(i == -1)
		return;
	  
	 for(j=0; j<c->course_list[i].grades_count; j++){
		for(k=0; k<c->course_list[i].grades[j].grades_count; k++){
			total += c->course_list[i].grades[j].grades[k];
			grades_count++; 
		}
	 }
	 
	 average = (int)total / (int)grades_count;
	
	 printf("\nCourse Average: %d", average);
	 
	 return;
 }
 
 void store_grade_book(courses * c, students * s){
	
	
	return;
}	
 
 void load_grade_book(courses * c, students * s){
	char input[30];
	 
	printf("\nGrade Book %s Loaded!\n", input);
	 
	return; 
 }
 
int student_match(students * s){
	int i, student_id;
	
	printf("\nWhat is the student id:");
	scanf("%d", &student_id);
    
    for(i = 0; i < s->student_count; i++){
		if(s->student_list[i].student_id == student_id){
			printf("\nStudent Found!\n");
			return i;
		}
		
		if(i == (s->student_count -1) && s->student_list[i].student_id != student_id){
			printf("\nThe student id does not exist. Try again!\n");
			return -1;
		}		
	}
    
	return 0;
}

int course_match(courses * c){
	int i, course_id;
	
	printf("\nWhat is the course id:");
	scanf("%d", &course_id);
	
	for(i = 0; i < c->course_count; i++){
		if(c->course_list[i].course_id == course_id){
			printf("\nCourse Found!\n");
			return i;
		}
		
		if(i == (c->course_count -1) && c->course_list[i].course_id != course_id){
			printf("\nThe course id does not exist. Try again!\n");
			return -1;
		}		
	}
}
