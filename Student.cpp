#include "Student.h"
#include <iostream>

Student::Student(const std::string& _am, const char* _id, const std::string& _fullName, const std::string& _email, unsigned int _semester)
: Person(_id, _fullName, _email), am(_am), semester(_semester) {}

Student::Student(const std::string& _am, const char* _id, const std::string& _fullName, int _birthYear, const std::string& _address, const std::string& _phone, const std::string& _email, unsigned int _semester)
: Person(_id, _fullName, _birthYear, _address, _phone, _email), am(_am), semester(_semester) {}


std::string Student::getAm() const { return am; }
unsigned int Student::getSemester() const { return semester; }

void Student::setAm(const std::string& _am) { am = _am; }
void Student::setSemester(unsigned int _semester) { semester = _semester; }

void Student::enrollCourse(Course* c) {
	if(!c){
		throw std::invalid_argument("Ο δείκτης μαθήματος είναι nullptr");
	}
	for(const auto& p : courses){
		if(p.first == c){
			throw std::invalid_argument("Το μάθημα έχει ήδη δηλωθεί");
		}
	}
	courses.push_back({c, -1});
}

void Student::setGrade(Course* c, int grade) {
	if(!c){
		throw std::invalid_argument("Ο δείκτης μαθήματος είναι nullptr");
	}
	for(auto& p : courses){
		if(p.first == c){
			p.second = grade;
			return;
		}
	}
	throw std::invalid_argument("Ο φοιτητής δεν είναι εγγεγραμμένος στο μάθημα");
}

int Student::getGrade(Course* c) const {
	if(!c){
		throw std::invalid_argument("Ο δείκτης μαθήματος είναι nullptr");
	}
	for(const auto& p : courses){
		if(p.first == c){
			return p.second;
		}
	}
	throw std::invalid_argument("Δεν βρέθηκε βαθμός για αυτό το μάθημα");
}

void Student::displayInfo(std::ostream& output) const {
	output << "Φοιτητής," << getId() << "," << getFullName() << "," << getEmail() << "," << am << "," <<  semester << std::endl;
}

void Student::receiveEmail(const std::string& message) const{
	std::cout << "O μαθητής " << getFullName() << " [ " << getEmail() << " ] έλαβε το μύνημα: " << message << std::endl;
}
