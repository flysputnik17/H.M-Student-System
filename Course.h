#ifndef COURSE_H
#define COURSE_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>




typedef struct {
    int id;
    char *name;
    struct Course *next;
}Course;


Course* Add_course(int id, char* name, Course* head);
Course* Delete_course(int id, char* name, Course* head);
void Edit_course(int id, Course* head);
void Print_courses(Course* head);
#endif