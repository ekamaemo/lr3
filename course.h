// course.h
#ifndef COURSE_H
#define COURSE_H

#include "student.h"
#define MAX_STUDENTS 100

struct Course {
    char* title;
    int numberOfStudents;
    float maxAverageScore;
    struct Student students[MAX_STUDENTS];
};

int addNewStudent(struct Course* course, struct Student student);
struct Student* searchTheBestStudent(struct Course* course);

#endif  // COURSE_H