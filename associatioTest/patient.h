#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <vector>
class Doctor;
class Patient{
private:
    std::string m_name;
    std::vector<Doctor *> m_doctors;
    void addDoctor(Doctor *doc);
public:
    Patient(std::string name):m_name(name){}
    std::string getName();
    friend class Doctor;
    friend std::ostream& operator<<(std::ostream& out, const Patient& pat);
};

#endif // PATIENT_H
