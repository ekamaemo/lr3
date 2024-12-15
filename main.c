#include <stdio.h>
#include "student.c"
#include "course.c"

int main() {
    struct Student student1 = {"Ivanov Ivan", 20, 4.6f};
    struct Student student2 = {"Petrov Petr", 22, 3.8f};

    struct Course course = { .title = "Programming", .numberOfStudents = 0, .maxAverageScore = 0.0};

    addNewStudent(&course, student1);
    addNewStudent(&course, student2);
    struct Student* topStudent = searchTheBestStudent(&course);
    if (topStudent != NULL) {
        printf("Top student: %s with avg grade: %.2f\n", topStudent->name, topStudent->averageScore);
    }
    return 0;
}