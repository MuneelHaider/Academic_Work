#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

/*

    Muneel Haider
    21i-0640
    Assignment 3
    Question 5

*/

typedef struct {

    int rollNo;
    char name[50];
    char course[50];
    char grade;
    int marks;

} Student;

typedef struct {

    double total;
    int count;

} AverageData;

Student studentArray[100];
AverageData avgData = {0, 0};

int studentCount = 0;
pthread_mutex_t mutex;

void readStudentData(const char* filename) {

    FILE *file = fopen(filename, "r");

    if (!file) {

        perror("Error opening file");
        exit(1);
    }

    fscanf(file, "%*[^\n]\n");

    while(fscanf(file, "%d,%49[^,],%49[^,],%c,%d\n", &studentArray[studentCount].rollNo, studentArray[studentCount].name, studentArray[studentCount].course, &studentArray[studentCount].grade, &studentArray[studentCount].marks) != EOF) {
        
        studentCount++;
    }

    fclose(file);
}

void* calculatePartialAverage(void* arg) {

    int start = ((int*)arg)[0];
    int end = ((int*)arg)[1];
    
    double total = 0;
    int count = 0;

    for (int i = start; i <= end; i++) {
    
        int gradeValue = 0;

        if (studentArray[i].grade == 'A') {
    
            gradeValue = 4;
    
        } else if (studentArray[i].grade == 'B') {
    
            gradeValue = 3;
    
        } else if (studentArray[i].grade == 'C') {
    
            gradeValue = 2;
    
        } else if (studentArray[i].grade == 'D') {
    
            gradeValue = 1;
        }

        total += gradeValue;
        count++;
    }

    pthread_mutex_lock(&mutex);
    
    avgData.total += total;
    avgData.count += count;
    
    pthread_mutex_unlock(&mutex);

    pthread_exit(0);
}


void* findStudentsNeedingCounseling(void* arg) {
   
    int start = ((int*)arg)[0];
    int end = ((int*)arg)[1];

    for (int i = start; i <= end; i++) {
   
        if (studentArray[i].grade == 'D') {
   
            printf("Student needing counseling: %s\n", studentArray[i].name);
        }
    }
   
    pthread_exit(0);
}

int compareStudentsByMarks(const void* a, const void* b) {
   
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
   
    return studentB->marks - studentA->marks;
}

void* sortStudents(void* arg) {
   
    qsort(studentArray, studentCount, sizeof(Student), compareStudentsByMarks);
    
    pthread_exit(0);
}

int main() {
   
    readStudentData("student-data.csv");
    pthread_mutex_init(&mutex, NULL);

    int partitionSize = studentCount / 2;
    int args[2][2] = {{0, partitionSize - 1}, {partitionSize, studentCount - 1}};

    pthread_t threadsA[2], threadsB[2];
   
    for (int i = 0; i < 2; i++) {
   
        pthread_create(&threadsA[i], NULL, calculatePartialAverage, (void*)args[i]);
        pthread_create(&threadsB[i], NULL, findStudentsNeedingCounseling, (void*)args[i]);
    }

    pthread_t threadC;
    pthread_create(&threadC, NULL, sortStudents, NULL);

    for (int i = 0; i < 2; i++) {
   
        pthread_join(threadsA[i], NULL);
        pthread_join(threadsB[i], NULL);
    }
   
    pthread_join(threadC, NULL);

    char averageGrade;

    if (avgData.count > 0) {
        
        double average = avgData.total / avgData.count;

        if (average >= 3.5) {
        
            averageGrade = 'A';
        
        } else if (average >= 2.5) {
        
            averageGrade = 'B';
        
        } else if (average >= 1.5) {
        
            averageGrade = 'C';
        
        } else {
        
            averageGrade = 'D';
        }
    } 
    else {
    
        averageGrade = 'F';
    }

    printf("Average Grade: %c\n\n\n", averageGrade);

    for (int i = 0; i < studentCount; i++) {

        printf("%d.  ", i + 1);
        printf("%d,\t %s, %s, %c, %d\n", studentArray[i].rollNo, studentArray[i].name, studentArray[i].course, studentArray[i].grade, studentArray[i].marks);
    }

    pthread_mutex_destroy(&mutex);
   
    pthread_exit(0);
}