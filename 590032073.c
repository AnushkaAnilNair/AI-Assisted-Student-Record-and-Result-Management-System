/* Student Record and Result Management System
   Name: Anushka Anil Nair
   SAP ID: 590032073
   Programming in C - Semester 1
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

struct Student {
    long long sap;
    char roll[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
};

struct Student students[MAX] = {
    {50001234, "R001", "Aarav Sharma", "9876543210", "aarav@gmail.com", 1, 2, {8.5, 8.8}},
    {50001211, "R002", "Priya Singh", "9123456789", "priya@gmail.com", 2, 4, {9.0, 8.5, 9.2, 8.9}},
    {50001300, "R003", "Rohan Verma", "9988776655", "rohan@gmail.com", 3, 6, {7.5, 8.0, 7.8, 8.2, 8.0, 8.4}},
    {50001150, "R004", "Neha Gupta", "9811223344", "neha@gmail.com", 4, 8, {9.5, 9.2, 9.4, 9.1, 9.6, 9.3, 9.5, 9.7}},
    {50001280, "R005", "Kabir Mehta", "9700112233", "kabir@gmail.com", 2, 3, {8.0, 8.1, 8.3}}
};
int count = 5;

/* Read a line of text, including spaces. */
void readText(char text[], int size) {
    int n;
    fgets(text, size, stdin);
    n = strlen(text);
    if (n > 0 && text[n - 1] == '\n')
        text[n - 1] = '\0';
}

/* Remove extra characters after a number entered using scanf. */
void clearInput() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

int readNumber() {
    int number;
    while (scanf("%d", &number) != 1) {
        printf("Enter a valid whole number: ");
        clearInput();
    }
    clearInput();
    return number;
}

long long readSAP() {
    long long number;
    while (scanf("%lld", &number) != 1) {
        printf("Enter a valid SAP ID: ");
        clearInput();
    }
    clearInput();
    return number;
}

float readSGPA() {
    float value;
    while (1) {
        if (scanf("%f", &value) == 1 && value >= 0 && value <= 10) {
            clearInput();
            return value;
        }
        printf("Enter SGPA between 0 and 10: ");
        clearInput();
    }
}

int findStudent(long long sap) {
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].sap == sap) return i;
    }
    return -1;
}

void printStudent(int i) {
    int j;
    printf("\nSAP ID: %lld\n", students[i].sap);
    printf("Roll No: %s\n", students[i].roll);
    printf("Name: %s\n", students[i].name);
    printf("Phone: %s\n", students[i].phone);
    printf("Email: %s\n", students[i].email);
    printf("Year: %d\n", students[i].year);
    printf("Current Semester: %d\n", students[i].semester);
    for (j = 0; j < 8; j++) {
        if (students[i].sgpa[j] > 0)
            printf("Semester %d SGPA: %.2f\n", j + 1, students[i].sgpa[j]);
        else
            printf("Semester %d SGPA: Not available\n", j + 1);
    }
}

void displayAll() {
    int i;
    if (count == 0) {
        printf("No student records.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printStudent(i);
    }
}
int main() {
    int choice;
    do {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Display all students\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        choice = readNumber();
        switch (choice) {
            case 1: displayAll(); break;
            case 2: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 2);
    return 0;
}
