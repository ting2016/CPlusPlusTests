#include "patient.h"
#include <string>

std::string Patient::getName(){
    return m_name;
}

void Patient::addDoctor(Doctor *doc){
    m_doctors.push_back(doc);
}
