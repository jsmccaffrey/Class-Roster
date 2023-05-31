/*
Req B.
In all.cpp files add:
#include <iostream>
#include <string>
using namespace std
In file main.cpp add :
#include “roster.h”
*/

#include <iostream>

#include <string>

#include "roster.h

using namespace std;

// Req F1.
void studentHeader() {
	cout << "C867 - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010397156" << endl;
	cout << "Name: James McCaffrey" << endl << endl;
}

int main()
{
	// Req A. In file main.cpp add studentData[] from task scenario into the main() function
	string studentData[] = {
	"A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
	"A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
	"A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
	"A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
	"A5, James, McCaffrey, jmc1180@wgu.edu, 23, 35, 21, 7, SOFTWARE" }; 

	// Req F1. In file main.cpp print out to the screen, via your application, the course title,
	// the programming language used, your WGU student ID, and your name, in main()
	studentHeader();



    return 0;
}