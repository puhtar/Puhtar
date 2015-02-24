#include "func_header.h"

int main(){
    int option = 0, i = 0, j = 0, k = 0;
    char choice[30];
    
    initial_print();
    
    printf("\nWelcome to the Grade Book!\n");
    
    courses *cours;
    students *studs;
    
    studs = (students *) malloc(sizeof(students) * CHUNKSIZE);
    cours = (courses *) malloc(sizeof(courses) * CHUNKSIZE);
    
    studs->student_count = 0;
    cours->course_count = 0;
    studs->student_max = cours->course_max = 0;
    
    do{
	
		option = menu();
	
		switch(option){
			case 1: new_course(cours);
					break;
		 
			case 2: new_student(studs);
					break;
		 
			case 3: add_course_student(cours, studs);
					break;
		 
			case 4: add_course_grades(cours, studs);
					break;
 
			case 5: print_student_grades(cours, studs);
					break;
		 
			case 6: print_course_students(cours, studs);
					break;
 
			case 7: student_average(cours, studs);
					break;
		 
			case 8: list_courses(cours);
					break;
		 
			case 9: list_students(studs);
					break;
		 
			case 10: course_average(cours);
					break;
 
			case 11: store_grade_book(cours, studs);
					break;
		  
			case 12: load_grade_book(cours, studs);
					break;
		}
		
		printf("\nDo you wish to continue (y/n):");
		scanf("%s", choice);
		
		if(choice[0] == 110 || choice[0] == 78)
			option = 0;
			
	}while(option != 0);
 
 printf("\nThank you for using the Grade Book program.\n");
    
    
    return 0;    
}
