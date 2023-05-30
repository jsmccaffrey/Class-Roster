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

class Student {
	public:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		string age;
		string daysInCourse;
		string degree;


};

