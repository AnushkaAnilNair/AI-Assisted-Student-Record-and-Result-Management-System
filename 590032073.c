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

void addStudent() {
    int j, year, sem;
    long long sap;

    if (count == MAX) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter SAP ID: ");
    sap = readSAP();

    if (sap <= 0 || findStudent(sap) != -1) {
        printf("Invalid or duplicate SAP ID.\n");
        return;
    }

    students[count].sap = sap;

    printf("Enter roll number: ");
    readText(students[count].roll, 20);

    printf("Enter name: ");
    readText(students[count].name, 50);

    printf("Enter phone number: ");
    readText(students[count].phone, 15);

    printf("Enter email: ");
    readText(students[count].email, 50);

    printf("Enter year (1-4): ");
    year = readNumber();

    if (year < 1 || year > 4) {
        printf("Invalid year. Record not added.\n");
        return;
    }

    printf("Enter current semester (1-8): ");
    sem = readNumber();

    if (sem < 1 || sem > 8 || (sem + 1) / 2 != year) {
        printf("Semester does not match year.\n");
        return;
    }

    students[count].year = year;
    students[count].semester = sem;

    for (j = 0; j < 8; j++) {
        students[count].sgpa[j] = 0;
    }

    printf("Enter SGPA for completed semesters.\n");
    printf("Enter 0 if result is unavailable.\n");

    for (j = 0; j < sem; j++) {
        printf("Semester %d SGPA: ", j + 1);
        students[count].sgpa[j] = readSGPA();
    }

    count++;
    printf("Student added successfully.\n");
}

void searchStudent() {
    int i;
    long long sap;

    printf("Enter SAP ID to search: ");
    sap = readSAP();

    i = findStudent(sap);

    if (i == -1) {
        printf("Student not found.\n");
    }
    else {
        printStudent(i);
    }
}

void deleteStudent() {
    int i, j;
    long long sap;

    printf("Enter SAP ID to delete: ");
    sap = readSAP();

    i = findStudent(sap);

    if (i == -1) {
        printf("Student not found.\n");
        return;
    }

    for (j = i; j < count - 1; j++) {
        students[j] = students[j + 1];
    }

    count--;
    printf("Student deleted.\n");
}

float getCGPA(int index) {
    float sum = 0;
    int i, n = 0;

    for (i = 0; i < 8; i++) {
        if (students[index].sgpa[i] > 0) {
            sum = sum + students[index].sgpa[i];
            n++;
        }
    }

    if (n == 0)
        return 0;

    return sum / n;
}

void calculateCGPA() {
    int i;

    if (count == 0) {
        printf("No student records.\n");
        return;
    }

    printf("\n===== CGPA OF ALL STUDENTS =====\n");

    for (i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("SAP ID: %lld\n", students[i].sap);
        printf("CGPA: %.2f\n\n", getCGPA(i));
    }
}

void averageCGPA() {
    int year, i, n;
    float sum;

    printf("\n===== AVERAGE CGPA BY YEAR =====\n");

    for (year = 1; year <= 4; year++) {
        sum = 0;
        n = 0;

        for (i = 0; i < count; i++) {
            if (students[i].year == year &&
                getCGPA(i) > 0) {
                sum = sum + getCGPA(i);
                n++;
            }
        }

        if (n > 0)
            printf("Year %d Average CGPA: %.2f\n",
                   year, sum / n);
        else
            printf("Year %d: No available CGPA\n", year);
    }
}

void sortBySAP() {
    int i, j;
    struct Student temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (students[i].sap > students[j].sap) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by SAP ID:\n");
    displayAll();
}

void sortByName() {
    int i, j;
    struct Student temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by Name:\n");
    displayAll();
}

void academicAdvisor() {
    int i;
    long long sap;
    float cgpa;

    printf("Enter SAP ID: ");
    sap = readSAP();

    i = findStudent(sap);

    if (i == -1) {
        printf("Student not found.\n");
        return;
    }

    cgpa = getCGPA(i);

    printf("\n===== AI-ASSISTED ACADEMIC ADVISOR =====\n");
    printf("Student Name: %s\n", students[i].name);
    printf("CGPA: %.2f\n", cgpa);

    if (cgpa == 0) {
        printf("No SGPA results available.\n");
    }
    else if (cgpa >= 9.0 && cgpa <= 10.0) {
        printf("Excellent Performance\n");
        printf("Advice: Maintain your current study pattern.\n");
    }
    else if (cgpa >= 7.0 && cgpa < 9.0) {
        printf("Good Performance\n");
        printf("Advice: Keep practising and aim for higher grades.\n");
    }
    else if (cgpa >= 5.0 && cgpa < 7.0) {
        printf("Needs Improvement\n");
        printf("Advice: Focus more on subjects with lower SGPA.\n");
    }
    else if (cgpa > 0.0 && cgpa < 5.0) {
        printf("Requires Immediate Attention\n");
        printf("Advice: Seek guidance from teachers and study regularly.\n");
    }
    else {
        printf("Invalid CGPA.\n");
    }
}


int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Display all students\n");
        printf("2. Add student\n");
        printf("3. Search student\n");
        printf("4. Delete student\n");
        printf("5. Calculate CGPA\n");
        printf("6. Average CGPA by year\n");
        printf("7. Sort by SAP ID\n");
        printf("8. Sort by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        choice = readNumber();

        switch (choice) {
            case 1:
                displayAll();
                break;

            case 2:
                addStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                calculateCGPA();
                break;

            case 6:
                averageCGPA();
                break;

            case 7:
                sortBySAP();
                break;

            case 8:
                sortByName();
                break;

            case 9:
                academicAdvisor();
                break;

            case 10:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 10);

    return 0;
}
