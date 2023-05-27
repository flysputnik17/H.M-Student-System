#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"Student.h"
#include"CourseGrade.c"


typedef struct {
    int id;
    char *name;
    int nume_courses;
    CourseGrade *grades;
    struct Student* next;
}Student;