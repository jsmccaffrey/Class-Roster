/*
Req B.
In all.cpp files add:
#include <iostream>
#include <string>
using namespace std

Req E.
In file roster.h:
#include “student.h”

In file roster.cpp:
#include “roster.h”
*/

#include <iostream>

#include <string>

#include "roster.h"

using namespace std;

/*
Req E. 
In files roster.h and roster.cpp create the Roster class, by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2.  Create a student object for each student in the data table and populate classRosterArray.
a.  Parse each set of data identified in the “studentData Table.”
b.  Add each student object to classRosterArray.
3.  Define the following functions:
a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
c.  public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
*/

void Roster::parse(string studentdata) // parses each row at a time
{
	DegreeProgram dp; 
	if (studentdata.at(1) == '1') dp = SECURITY;
	else if (studentdata.at(1) == '2') dp = NETWORK;
	else if (studentdata.at(1) == '3') dp = SOFTWARE;
	else if (studentdata.at(1) == '4') dp = SECURITY;
	else if (studentdata.at(1) == '5') dp = SOFTWARE;
	else dp = UNDECLARED;
	
	int rhs = studentdata.find(","); // finds the comma
	string sID = studentdata.substr(0, rhs); // student ID

	int lhs = rhs + 1; // keep going
	rhs = studentdata.find(",", lhs);
	string fnm = studentdata.substr(lhs, rhs - lhs); // first name

	lhs = rhs + 1; // keep going
	rhs = studentdata.find(",", lhs);
	string lnm = studentdata.substr(lhs, rhs - lhs); // last name

	lhs = rhs + 1; // keep going
	rhs = studentdata.find(",", lhs);
	string ema = studentdata.substr(lhs, rhs - lhs); // email address

	lhs = rhs + 1; // keep going 
	rhs = studentdata.find(",", lhs); 
	string ag = studentdata.substr(lhs, rhs - lhs); // age

	int d[3];
	for (int i = 0; i < 3; i++)
	{
		lhs = rhs + 1;
		rhs = studentdata.find(",", lhs);
		d[i] = stoi(studentdata.substr(lhs, rhs - lhs));
	}

	add(sID, fnm, lnm, ema, ag, d[0], d[1], d[2], dp);
}

// add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, string age, int days1, int days2, int days3, DegreeProgram dp)
{
	int darr[] = { days1, days2, days3 }; // puts number of days into array for constructor
	students[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, dp); // full constructor
}

// display all students
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::students[i]->print();
	cout << endl;
}

// displays only students with given degree program
void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (Roster::students[i]->getDegreeProgram() == dp) students[i]->print();
	}
	cout << endl;
}

//valid email should include an at sign ('@') and period ('.') and should not include a space (' ')
void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string ema = (students[i]->getEmailAddress());
		if (ema.find('@') == string::npos || ema.find('.') == string::npos || ema.find(" ") != string::npos)
		{
			any = true;
			cout << students[i]->getEmailAddress() << " - email is invalid. " << endl;
		}
	}
	if (!any) cout << "NONE" << endl;
	cout << endl; 
}

// prints average number of days in three courses
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (students[i]->getID()==studentID)
		{ 
			cout << "Student ID: " << studentID << ", average days in course is: " << (students[i]->getDaysInCourse()[0]
				+ students[i]->getDaysInCourse()[1]
				+ students[i]->getDaysInCourse()[2]) / 3;
		}
	}
	cout << endl; 
}

// remove student by ID
void Roster::removeByStudentID(string studentID) //student to be removed comes in as parameter
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (students[i]->getID() == studentID)
		{
			success = true; // found
			if (i < numStudents - 1)
			{
				Student* temp = students[i]; // swap with last student
				students[i] = students[numStudents - 1];
				students[numStudents - 1] = temp;
			}
			Roster::lastIndex--; // last student no longer visible
		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << endl;
	}
	else { cout << "The student with the ID " << studentID << " was not found." << endl << endl; }
}

// Req F5. Release allocated memory
Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED" << endl << endl;
	for (int i = 0 ; i < numStudents; i++)
	{
		cout << "Destroying student #" << i + 1 << endl;
		delete students[i];
		students[i] = nullptr;
	}
}
