/*

Nick Luca
M11 Assignment
courseGrade.cpp

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Stu // struct and member names provided by the prof
{
    string name; // student name
    int idNum; // student id number
    float* tests; // student tests average
    float average; // students average of all the tests they have taken if there are multiple
    char grade; // students grade
};

// functions prototypes
void studentInfo(Stu* stu, int numStu, int Tests); // getting all the students information
void getGradeAverage(Stu* stu, int Tests); // calculating the student tests average and their grade
void displayStudentInfo(Stu* stu, int numStu); // displaying to output the students information

int main() 
{
    int numStu, Tests;

    cout << "\033[0;93mWhat is the amount of students you would like to enter?: \033[0m"; // bright yellow text color to output
    cin >> numStu; // user input for the amount of students they have
    cout << endl; // for output reasons

    while (numStu <= 0) // for input validation
    {
        cout << "\033[0;91mYou cannot enter zero or a negative amount of students, please try again\033[0m" << endl; // bright red text color to output
        cout << "\033[0;93mWhat is the amount of students you would like to enter?: \033[0m"; // bright yellow text color to output
        cin >> numStu; // user input for the amount of students they have
        cout << endl; // for output reasons
    }

    cout << "\033[0;93mEnter the amount of tests each student has taken: \033[0m"; // bright yellow text color to output
    cin >> Tests; // user input for how many test or tests a student or students have taken
    cout << endl; // for output reasons

    while (Tests <= 0) // for input validation
    {
        cout << "\033[0;91mStudents aren't able to take zero or a negative amount of tests, please try again\033[0m" << endl; // bright red text color to output
        cout << "\033[0;93mEnter the amount of tests each student has taken: \033[0m"; // bright yellow text color to output
        cin >> Tests; // user input for how many test or tests a student or students have taken
        cout << endl; // for output reasons
    }

    Stu* stu = new Stu[numStu]; // array has been dynamically allocated

    studentInfo(stu, numStu, Tests); // caling the studentInfo function
    displayStudentInfo(stu, numStu); // calling the displayStudentInfo function

    for (int i = 0; i < numStu; i++) 
    {
        delete[] stu[i].tests; // free the dynamically allocated memory
    }
    delete[] stu; // free the dynamically allocated memory

    return 0;
}

void studentInfo(Stu* stu, int numStu, int Tests) // getting student or students information
{
    int i, count;

    for (i = 0; i < numStu; i++) 
    {
        cout << "\033[0;94mEnter information for Student \033[0m" << i + 1 << endl; // bright blue text to output

        cin.ignore();
        cout << "\033[0;93mStudent Name: \033[0m"; // bright yellow text color to output
        getline(cin, stu[i].name); // user input for student name
        cout << endl; // for output reasons

        cout << "\033[0;93mStudent ID Number: \033[0m"; // bright yellow text color to output
        cin >> stu[i].idNum; // user input for student id number
        cout << endl; // for output reasons

        stu[i].tests = new float[Tests]; // array has been dynamically allocated

        for (count = 0; count < Tests; count++) 
        {
            cout << "\033[0;93mTest \033[0m" << count + 1 << " \033[0;93mscore \033[0m" << "\033[0;93mfor Student \033[0m" << i + 1 << "\033[0;93m: \033[0m"; // bright yellow text color to output
            cin >> stu[i].tests[count]; // user input for test score or scores
            cout << endl; // for output reasons

            while (stu[i].tests[count] < 0) // for input validation
            {
                cout << "\033[0;91mA test score cannot be zero or a negative number, please try again\033[0m" << endl; // bright red text color to output
                cout << "\033[0;93mTest \033[0m" << count + 1 << " \033[0;93mscore: \033[0m"; // bright yellow text color to output
                cin >> stu[i].tests[count]; // user input for test score or scores
                cout << endl; // for output reasons
            }
        }
        getGradeAverage(&stu[i], Tests); // calling the getGradeAverage function
    }
}

void getGradeAverage(Stu* stu, int Tests) // getting student or students tests average and grade
{
    float testTotal = 0;
    int i;

    for (i = 0; i < Tests; i++) 
    {
        testTotal += *(stu->tests + i); // calculating tests totals
    }

    stu->average = testTotal / Tests; // calculating average

    if (stu->average >= 90) // assinging student or students grade
    {
        stu->grade = 'A';
    }
    else if (stu->average >= 80) 
    {
        stu->grade = 'B';
    }
    else if (stu->average >= 70) 
    {
        stu->grade = 'C';
    }
    else if (stu->average >= 60) 
    {
        stu->grade = 'D';
    }
    else 
    {
        stu->grade = 'F';
    }
}

void displayStudentInfo(Stu* stu, int numStu) // displaying the information to output
{
    int i;

    cout << "\033[0;94mStudent Information\033[0m" << endl; // bright blue text color to output
    cout << left << setw(15) << "Name" << setw(20) << "Student ID Number" << setw(15) << "Test Average" << setw(10) << "Grade" << endl;
    cout << "---------------------------------------------------------------------" << endl; // for output reasons and because looks nicer

    for (i = 0; i < numStu; ++i) 
    {
        cout << left << setw(15) << stu[i].name << setw(20) << stu[i].idNum << setw(15) << fixed << setprecision(2) << stu[i].average << setw(10) << stu[i].grade << endl;
    }
}
