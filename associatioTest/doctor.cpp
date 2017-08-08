#include "doctor.h"
#include "patient.h"
void Doctor::addPatient(Patient *pat){
    m_patients.push_back(pat);
    pat->addDoctor(this);
}

std::string Doctor::getName(){
    return m_name;
}
