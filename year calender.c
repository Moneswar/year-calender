#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 50
#define MAX_NAME_LENGTH 50

// Structure for student
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Student;

// Structure for course
typedef struct {
    char name[MAX_NAME_LENGTH];
    int code;
} Course;

// Function prototypes
void addStudent(Student students[], int *numStudents);
void addCourse(Course courses[], int *numCourses);
void displayStudents(Student students[], int numStudents);
void displayCourses(Course courses[], int numCourses);

int main() {
    Student students[MAX_STUDENTS];
    Course courses[MAX_COURSES];
    int numStudents = 0;
    int numCourses = 0;
    int choice;

    do {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Display Students\n");
        printf("4. Display Courses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                addCourse(courses, &numCourses);
                break;
            case 3:
                displayStudents(students, numStudents);
                break;
            case 4:
                displayCourses(courses, numCourses);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void addStudent(Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter student ID: ");
    scanf("%d", &students[*numStudents].id);
    (*numStudents)++;
}

void addCourse(Course courses[], int *numCourses) {
    if (*numCourses >= MAX_COURSES) {
        printf("Maximum number of courses reached.\n");
        return;
    }

    printf("Enter course name: ");
    scanf("%s", courses[*numCourses].name);
    printf("Enter course code: ");
    scanf("%d", &courses[*numCourses].code);
    (*numCourses)++;
}

void displayStudents(Student students[], int numStudents) {
    printf("\nStudent List:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, ID: %d\n", students[i].name, students[i].id);
    }
}

void displayCourses(Course courses[], int numCourses) {
    printf("\nCourse List:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("Name: %s, Code: %d\n", courses[i].name, courses[i].code);
    }
}
