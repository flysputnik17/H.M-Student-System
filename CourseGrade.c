#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"CourseGrade.h"

typedef struct {
    int course_id;
    struct Course* currentCourse;
    float grade;
    struct CourseGrade* next;
}CourseGrade;

