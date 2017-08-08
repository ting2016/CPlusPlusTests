#include "cents.h"

Cents::Cents(int cents){
	m_cents = cents;
}

int Cents::getCents(){
	return m_cents;
}

void Cents::setCents(int cents){
	m_cents = cents;
}
bool operator<(const Cents& c1, const Cents& c2){
	return c1.m_cents<c2.m_cents ;
}

bool operator>(const Cents& c1, const Cents& c2){
	return c1.m_cents>c2.m_cents;
}
