#include "logger.h"

Logger* Logger::m_pInstance = nullptr;

Logger* Logger::Instance(){
	if(!m_pInstance){
		m_pInstance = new Logger();
	}
	return m_pInstance;
}


