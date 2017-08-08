#ifndef TOOL_H
#define TOOL_H
#include <iostream>
class Doctor;
class Patient;
std::ostream& operator<<(std::ostream& out, const Doctor& doc);
std::ostream& operator<<(std::ostream& out, const Patient& pat);

#endif // TOOL_H
