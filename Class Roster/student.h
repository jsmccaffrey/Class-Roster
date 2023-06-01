#pragma once
#include <iostream>
#include <iomanip>

/*
In file student.h:
#include “degree.h”
In file student.cpp:
#include “student.h”
You may defer the actual definition of the functions in student.cpp until they are required,
that is, create stub functions (empty functions) for now.
*/

#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

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


class Student 
{
public:
	const static int MAX_COURSES = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	double daysInCourse[MAX_COURSES];
	DegreeProgram degreeProgram;
public:
	Student(); // parameterless constructor sets to default values
	Student(string studentID, string firstName, string lastName, string emailAddress, string age, double daysInCourse[], DegreeProgram degreeProgram); //full constructor
	~Student(); // destructor

	// getters aka accessors
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getAge();
	double* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	// setters aka mutators
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(string age);
	void setDaysInCourse(double daysInCourse[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader(); // displays a header for the data to follow

	void print(); // displays this student data
};