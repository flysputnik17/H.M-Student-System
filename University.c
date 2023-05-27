#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"University.h"
#include"Student.c"


typedef struct {
    char *name;
    int num_courses;
    Course *courses;
    Student *students;
}University;