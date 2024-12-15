#ifndef STUDENT_H
#define STUDENT_H

struct Student{
    char name[50];
    int age;
    float averageScore;
};

int changeAverageScore(struct Student* student, float newAverageScore);
int isExcellentStudent(struct Student* student);
#endif