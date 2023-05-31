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

#include “student.h”

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

Student::Student() //parameterless constructor sets to default values
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

Student::Student() {} //destructor, Student class creates nothing dynamically


