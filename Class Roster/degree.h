#pragma once
#include <string>

// Req C. In file degree.h define an enumerated data type DegreeProgram for the degree programs 
// containing the data type values SECURITY, NETWORK, and SOFTWARE.

enum DegreeProgram {
	UNDECLARED,
	SECURITY,
	NETWORK,
	SOFTWARE
};

// parallel array
static const std::string degreeProgramStrings[] = { "UNDECLARED", "SECURITY", "NETWORK", "SOFTWARE" };