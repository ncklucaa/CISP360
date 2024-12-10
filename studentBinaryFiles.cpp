/*

Nick Luca
M13 Assignment

A lot of this work is from my own Activity 31 code!!!
also you will see just " cout << endl;
that is just for output purposes to make it look nicer and not all bunched up together

*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student // structure
{
	char name[80]; // for student name
	char studentID[10]; // for student ID
	float GPA; // for student GPA
};

void addNewRecords() // adding new student record into our file
{
	bool validGPA = false; // for checking if gpa is loswer 0.0 or higher than 4.0, and also for invalid inputs such as letters or negative numbers
	
	ofstream outFile("student.dat", ios::app | ios::binary);
	if (!outFile)
	{
		cout << "Unable to open file for writing." << endl;
		return;
	}

	Student stu;

	cin.ignore();

	cout << "Enter the Student's Name: ";
	cin.getline(stu.name, 80);

	cout << "Enter the Student ID: ";
	cin.getline(stu.studentID, 10);

	do
	{
		cout << "Enter the Student's GPA: ";
		cin >> stu.GPA;
		cout << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid GPA, please enter a GPA between (0.0 - 4.0)" << endl; // if not numeric number
		}
		else if (stu.GPA < 0.0 || stu.GPA > 4.0)
		{
			cout << "Invalid GPA, please enter a GPA between (0.0 - 4.0)" << endl; // if gpa is lower than 0.0 or higher than 4.0
		}
		else
		{
			validGPA = true;
		}
	} while (!validGPA);

	outFile.write(reinterpret_cast<char*>(&stu), sizeof(stu));
	outFile.close(); // file close
	cout << "Student Record added successfully!" << endl;
	cout << endl;
}

void searchStudentRecord()
{
	char findID[10]; // for option 2 in our menu searching student id to find in our records
	bool found = false;

	ifstream inFile("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "Unable to open file for output." << endl;
		return;
	}

	Student stu;
	cout << endl;

	cout << "Enter the Student ID to search in the records" << endl;
	cout << "Student ID: ";
	cin.ignore();
	cin.getline(findID, 10);
	cout << endl;

	while (inFile.read(reinterpret_cast<char*>(&stu), sizeof(stu)))
	{
		if (strcmp(stu.studentID, findID) == 0) // to compare both arrays and to see if student ID is in there and matches
		{
			cout << "Record for Student #" << findID << " found" << endl;
			cout << "------------------------------------------" << endl;
			cout << "Name: " << stu.name << endl;
			cout << "Student ID: " << stu.studentID << endl;
			cout << "GPA: " << fixed << setprecision(2) << stu.GPA << endl;
			cout << endl;

			found = true;
		}
	}

	if (!found)
	{
		cout << "No record found for Student #" << findID << endl;
		cout << endl;
	}

	inFile.close();
}

int main()
{
	int choice;

	do
	{
		cout << "Student Records" << endl;
		cout << "1. Add new records to the file" << endl;
		cout << "2. Search and display a record in the file" << endl;
		cout << "3. Quit program" << endl;
		cout << "Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			addNewRecords();
		}
		else if (choice == 2)
		{
			searchStudentRecord();
		}
		else if (choice == 3)
		{
			cout << "Exiting program" << endl;
		}
		else
		{
			cout << "Invalid choice, please pick an option (1-3)" << endl;
		}
	} while (choice != 3);

	return 0;
}