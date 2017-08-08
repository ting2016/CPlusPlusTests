#include "tool.h"
#include "patient.h"
#include "doctor.h"

std::ostream& operator<<(std::ostream &out, const Patient &pat){
    unsigned int length = pat.m_doctors.size();
    if(length == 0){
        out << pat.m_name << " has no doctor.";
        return out;
    }
    out << pat.m_name << " is seeing doctors:";
    for(unsigned int i = 0; i < length; i++){
        out << pat.m_doctors.at(i)->m_name << " "; // need to make this method friend of Class Doctor as well
        //out << pat.m_doctors.at(i)->getName() << " "; // only need to make this method friend of class Patient
    }

}

std::ostream& operator<<(std::ostream &out, const Doctor &doc){
    unsigned int length = doc.m_patients.size();
    if(length ==0){
        out << doc.m_name << " has no patient";
        return out;
    }
    out << doc.m_name << " is seeing patients:";
    for(unsigned int i = 0; i < length; i++){
        out << doc.m_patients.at(i)->getName() << " "; // need to make this method friend of Class Doctor
    }

}
