#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& _profId, const char* _id, const std::string& _fullName, const std::string& _email, const std::string& _specialty)
: Person(_id, _fullName, _email), profId(_profId), specialty(_specialty) {}

Professor::Professor(const std::string& _profId, const char* _id, const std::string& _fullName, int _birthYear, const std::string& _address, const std::string& _phone, const std::string& _email, const std::string& _specialty)
: Person(_id, _fullName, _birthYear, _address, _phone, _email), profId(_profId), specialty(_specialty) {}

std::string Professor::getProfessorId() const { return profId; }
std::string Professor::getSpecialty() const { return specialty; }

void Professor::setProfessorId(const std::string& _profId) { profId = _profId; }
void Professor::setSpecialty(const std::string& _specialty) { specialty = _specialty; }

void Professor::displayInfo(std::ostream& output) const{
	output << "Καθηγητής," << getId() << "," << getFullName() << "," << getEmail() << "," << profId << "," << specialty << std::endl;
}

void Professor::receiveEmail(const std::string& message) const{
	std::cout << "Ο καθηγητής " << getFullName() << " [ " << getEmail() << " ] έλαβε το μύνημα: " << message << std::endl;
}


