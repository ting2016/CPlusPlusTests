#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <vector>
class Patient;
class Doctor{
private:
    std::string m_name;
    std::vector<Patient *> m_patients;
public:
    Doctor(std::string name):m_name(name){}
    void addPatient(Patient *pat);
    std::string getName();
    friend std::ostream& operator<<(std::ostream& out, const Doctor& doc);
    friend std::ostream& operator<<(std::ostream &out, const Patient &pat);
};

#endif // DOCTOR_H
