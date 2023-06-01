/*
Req B.
In all.cpp files add:
#include <iostream>
#include <string>
using namespace std
In file main.cpp add :
#include "roster.h"
*/

#include <iostream>

#include <string>

#include "roster.h"

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
	const string studentData[] = 
	{
	"A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
	"A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
	"A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
	"A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
	"A5, James, McCaffrey, jmc1180@wgu.edu, 23, 35, 21, 7, SOFTWARE" 
	}; 

	const int numStudents = 5;

	// Req F1. In file main.cpp print out to the screen, via your application, the course title,
	// the programming language used, your WGU student ID, and your name, in main()
	studentHeader();

	// Req F2. In file main.cpp create an instance of the Roster class called classRoster in the main() function.
	Roster classRoster;

	/*
	Req F3. In file main.cpp, in the main() function call:
	classRoster.parse(studentData[i]);
	We must parse the string from studentData[] before you can add Student object to the classRosterArray.
	In file roster.cpp, in the parse() function, call the add() function with all the student attributes :
	classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	
	Req F4.
	In file main.cpp, convert the following pseudo code to complete the rest of the  main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();
	*/

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students : " << endl;
	classRoster.printAll();
	cout << "Displaying invalid emails: " << endl;
	classRoster.printInvalidEmails(); 
	cout << endl;

	/*
	Req 4 cont.
	loop through classRosterArray and for each element:

	classRoster.printAverageDaysInCourse(/*current_object's student id*);
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
	expected: the above line should print a message saying such a student with this ID was not found.
	*/

	for (int i = 0; i < 3; i++)
	{
		cout << "Showing students in degree program: " << degreeProgramStrings[i] << endl;
		classRoster.printByDegreeProgram((DegreeProgram)i); 
	}

	// cout << "Displaying average days: " << endl;
	// classRoster.printAverageDaysInCourse(); 

	cout << "Removing A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();
	cout << endl; 

	cout << "Removing A3: " << endl; 
	classRoster.remove("A3");  
	cout << endl; 

	system("pause");

	// Req F5. Release allocated memory
	

    return 0;
}