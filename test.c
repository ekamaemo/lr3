#include "student.c"
#include "course.c"
#include <stdio.h>

void testChangeAverageScore();
void testIsExcellentStudent();
void testAddNewStudent();
void testSearchTheBestStudent();

int main() {
    testChangeAverageScore();
    testIsExcellentStudent();
    testAddNewStudent();
    testSearchTheBestStudent();
    return 0;
}

void testChangeAverageScore(){
    printf("Test function changeAverageScore");
    // проверяет работу функции, меняющей средний балл студента changeAverageScore
    struct Student Ivan = {"Ivan", 18, 4.3f};
    // Успешный тест
    float newScore = 4.7f;
    int result = changeAverageScore(&Ivan, newScore);
    if (result == 1 && Ivan.averageScore == newScore){
        printf("Previous score: %.2f\nNew score: %.2f\n", 4.3f, newScore);
    }
    // Негативный тест (оценка больше 5)
    newScore = 6.3f;
    float previousScore = Ivan.averageScore;
    result = changeAverageScore(&Ivan, newScore);
    if (result == 0 && previousScore == Ivan.averageScore){
        printf("Previous score: %.2f\nNew score: %.2f\n", previousScore, Ivan.averageScore);
    }
    // Крайний случай, оценка 2
    newScore = 2;
    result = changeAverageScore(&Ivan, newScore);
    if (result == 1 && Ivan.averageScore == newScore){
        printf("Previous score: %.2f\nNew score: %.2f\n", previousScore, newScore);
    }
}
void testIsExcellentStudent(){
    printf("Test function isExcellentStudent");
    // Успешный тест
    struct Student Bob = {"Bob", 19, 5};
    struct Student Rob = {"Rob", 20, 3.7};
    int resultBob = isExcellentStudent(&Bob);
    int resultRob = isExcellentStudent(&Rob);
    if (resultBob == 1 && resultRob == 0){
        printf("Bob is excellent student, Rob is not\n");
    }
    // Негативный тест (оценок нет, оценка 0)
    struct Student Jeb = {"Jeb", 21, 0};
    int resultJeb = isExcellentStudent(&Jeb);
    if (resultJeb == 0){
        printf("Jeb hasn't received any grades yet\n");
    }
    // Крайний случай (оценка 4.9)
    changeAverageScore(&Jeb, 4.9f);
    resultJeb = isExcellentStudent(&Jeb);
    if (resultJeb == 0){
        printf("Jeb is not an excellent student because his score is not 5\n");
    }
}

void testAddNewStudent(){
    printf("Test function addNewStudent\n");
    struct Student Phil = {"Phil", 23, 4.6};
    struct Course courseProgramming = {"Programming", 0, 0};
    // Успешный тест
    int result = addNewStudent(&courseProgramming, Phil);
    if (result == 1){
        printf("%s\nBefore: 0 students;\nStudents: None\nAfter: %d students;\nStudents:\n", courseProgramming.title, courseProgramming.numberOfStudents);
        for (int i = 0; i < courseProgramming.numberOfStudents; i++){
            printf("%s \n", courseProgramming.students[i].name);
        }
    }
    // Крайний случай (добавление 101 студента)
    for (int i = 0; i < 99; i++){
        addNewStudent(&courseProgramming, Phil);
    }
    // Негативный тест (добавление 101 студента)
    int n = courseProgramming.numberOfStudents; // число студентов до добавления нового студента
    result = addNewStudent(&courseProgramming, Phil);
    if (result == 0){
        printf("Before: %d students\nAfter: %d students\n", n, courseProgramming.numberOfStudents);
    }
}

void testSearchTheBestStudent(){
    printf("Test function searchTheBestStudent\n");
    struct Course mathematics = {"math", 0, 0.0};
    struct Student Lesly = {"Lesly", 23, 3.4};
    struct Student Abby = {"Abby", 24, 4.5};
    struct Student Addy = {"Addy", 22, 4.78};
    addNewStudent(&mathematics, Lesly);
    addNewStudent(&mathematics, Abby);
    addNewStudent(&mathematics, Addy);
    // Позитивный тест
    struct Student* bestStudent = searchTheBestStudent(&mathematics);
    struct Student* def = {0};
    if (bestStudent != def){
        printf("The best student: %s, his score is %.2f\n", bestStudent->name, bestStudent->averageScore);
    }
    // Негативный тест (поиск лучшего студента на курсе, где нет студентов)
    struct Course biology = {"biology", 0, 0.0};
    struct Student* bestBiologyStudent = searchTheBestStudent(&biology);
    if (bestBiologyStudent == def){
        printf("The best student was not found\n");
    }
}
