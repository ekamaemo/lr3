#include "student.h"

int changeAverageScore(struct Student* student, float newAverageScore){
    if (newAverageScore <= 5.0 && newAverageScore >= 2.0){
        student->averageScore = newAverageScore;
        return 1;
    }
    return 0;
}

int isExcellentStudent(struct Student* student){
    if (student->averageScore == 5.0){
        return 1;
    }
    return 0;
}