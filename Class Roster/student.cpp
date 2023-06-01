/*
Req B.
In all.cpp files add:
#include <iostream>
#include <string>
using namespace std

Req D.
In file student.h:
#include “degree.h”
In file student.cpp:
#include “student.h”
You may defer the actual definition of the functions in student.cpp until they are required,
that is, create stub functions (empty functions) for now.
*/

#include <iostream>

#include <string>

#include "student.h"

using namespace std;

/*
Req D. 
For the Student class, do the following
1. In files student.h and student.cpp create the Student class, which includes each of the following variables:
•  student ID
•  first name
•  last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program

2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/

Student::Student() // parameterless constructor sets to default values
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	for (int i= 0; i < MAX_COURSES; i++) this->daysInCourse[i] = "";
	this->degreeProgram = DegreeProgram::UNDECLARED;
}

Student::Student(string firstName, string lastName, string emailAddress, string age, string daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < MAX_COURSES; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::Student() {} // destructor, Student class creates nothing dynamically

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
string Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(string age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) 
{ 
	for (int i = 0; i < MAX_COURSES; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader() // use to print the header
{
	cout << "Output format : ID | First Name | Last Name | Email Address | Age | Days in Course | Degree Program" << endl;
}

void Student::print()
{
	cout << this->getStudentID() << '\t'; // using tab separated output and getters
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; // degree program to string
}



