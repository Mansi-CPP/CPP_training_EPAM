#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char* name;
    int* marks;
    int num_marks;
};

int main() {
    struct Student student;

    student.name = (char*)malloc(50 * sizeof(char)); 
    if (student.name == NULL) {
        printf("Memory allocation failed for name\n");
        return 1;
    }

  
    student.num_marks = 5;
    student.marks = (int*)malloc(student.num_marks * sizeof(int));  
    if (student.marks == NULL) {
        printf("Memory allocation failed for marks\n");
        free(student.name);  
        return 1;
    }


    strcpy(student.name, "Mansi Shahi");
    for (int i = 0; i < student.num_marks; i++) {
        student.marks[i] = (i + 1) * 10;  
    }

   
    printf("Student Name: %s\n", student.name);
    printf("Marks: ");
    for (int i = 0; i < student.num_marks; i++) {
        printf("%d ", student.marks[i]);
    }
    printf("\n");

   
    free(student.name);
    free(student.marks);

    return 0;
}