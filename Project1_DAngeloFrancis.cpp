//************************************************
// TITLE: Grade Book                *
// FILE NAME: Project1_DAngeloFrancis.cpp        *
// PROGRAMMER: D'Angelo Francis                  *
// DATE: February 10, 2025                       *
// REQUIREMENTS:Read the student’s names and test*
// scores from a file, calculate the average of  *
// the test scores and then provide a letter     *
// grade for the average                         *
//************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_TESTS = 10;
const int MAX_STUDENTS = 60;

string getFileName();
ifstream openFile(string fileName);
int readFile(ifstream& inputFile, string studentNames[], double testScores[][MAX_TESTS], int& numTests);
void closeFile(ifstream& inputFile);
void calculateAverages(double testScores[][MAX_TESTS], double averages[], int numStudents, int numTests);
char getLetterGrade(double average);
void displayGrades(string studentNames[], double averages[], int numStudents);

int main() {
    string studentNames[MAX_STUDENTS]; 
    double testScores[MAX_STUDENTS][MAX_TESTS];
    double averages[MAX_STUDENTS]; 
    int numTests, numStudents;

    string fileName = getFileName();
    ifstream inputFile = openFile(fileName);

    numStudents = readFile(inputFile, studentNames, testScores, numTests);
    closeFile(inputFile);

    calculateAverages(testScores, averages, numStudents, numTests);
    displayGrades(studentNames, averages, numStudents);

    return 0;
}
string getFileName() {
    string fileName;
    cout << "Enter the file name you wish to read: ";
    cin >> fileName;
    return fileName;
}
ifstream openFile(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile) {
        cout << "*ERROR* Unable to open file." << endl;
    }
    cout << "*SUCCESS* File was opened.\n\n";
    return inputFile;
}
int readFile(ifstream& inputFile, string studentNames[], double testScores[][MAX_TESTS], int& numTests) {
    int numStudents = 0;  
    numTests = 0;  

    while (inputFile >> studentNames[numStudents]) { 
        int count = 0;
        while (count < MAX_TESTS && inputFile >> testScores[numStudents][count]) { 
            count++;
        }
        if (numStudents == 0) {
            numTests = count;  
        }
        numStudents++;
    }
    return numStudents; 
}
void closeFile(ifstream& inputFile) {
    inputFile.close();
}
void calculateAverages(double testScores[][MAX_TESTS], double averages[], int numStudents, int numTests) {
    for (int i = 0; i < numStudents; i++) {
        double total = 0;
        for (int j = 0; j < numTests; j++) {
            total += testScores[i][j];
        }
        averages[i] = total / numTests;
    }
}
char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}
void displayGrades(string studentNames[], double averages[], int numStudents) {
    cout << left << setw(15) << "Student Name" << setw(10) << "Average" << "Grade" << endl;
    cout << "______________________________\n";

    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(15) << studentNames[i]
            << setw(10) << fixed << setprecision(2) << averages[i]
            << getLetterGrade(averages[i]) << endl;
    }
}

