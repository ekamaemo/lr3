#include "course.h"

int addNewStudent(struct Course* course, struct Student student){
    if (course->numberOfStudents < MAX_STUDENTS){
        course->numberOfStudents++;
        course->students[course->numberOfStudents - 1] = student;
        if (student.averageScore > course->maxAverageScore){
            course->maxAverageScore = student.averageScore;
        }
        return 1;
    } else {
        return 0;
    }
}

struct Student* searchTheBestStudent(struct Course* course){
    struct Student* bestStudent = {0};
    if (course->numberOfStudents == 0) return bestStudent;
    bestStudent = &course->students[0];
    for (int i = 1; i < course->numberOfStudents; i++){
        if (course->students[i].averageScore > bestStudent->averageScore){
            bestStudent = &course->students[i];
        }
    }
    return bestStudent;
}