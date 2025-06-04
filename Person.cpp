#include "Person.h"
#include <iostream>
#include <cstring>

Person::Person(const char* _id, const std::string& _fullName, int _birthYear, const std::string& _address, const std::string& _phone, const std::string& _email)
: fullName(_fullName), birthYear(_birthYear), address(_address), phone(_phone), email(_email) {
	id = new char[strlen(_id) + 1];
	strcpy(id, _id);
}

Person::Person(const char* _id, const std::string& _fullName, const std::string& _email)
: fullName(_fullName), email(_email) {
	id = new char[strlen(_id) + 1];
	strcpy(id, _id);
}

Person::Person(const Person& p)
: fullName(p.fullName), birthYear(p.birthYear), address(p.address), phone(p.phone), email(p.email) {
	id = new char[strlen(p.id) + 1];
	strcpy(id, p.id);
}

Person::~Person() {
	delete[] id;
}

char* Person::getId() const { return id; }
std::string Person::getFullName() const { return fullName; }
int Person::getBirthYear() const { return birthYear; }
std::string Person::getAddress() const { return address; }
std::string Person::getPhone() const { return phone; }
std::string Person::getEmail() const { return email; }

void Person::setId(const char* _id) {
	delete[] id;
	id = new char[strlen(_id) + 1];
	strcpy(id, _id);
}
void Person::setFullName(const std::string& _fullName) { fullName = _fullName; }
void Person::setBirthYear(int _birthYear) { birthYear = _birthYear; }
void Person::setAddress(const std::string& _address) { address = _address; }
void Person::setPhone(const std::string& _phone) { phone = _phone; }
void Person::setEmail(const std::string& _email) { email = _email; }

int Person::calculateAge(const int currentYear) const {
	if(currentYear <= birthYear){
		return 0;
	}
	return currentYear - birthYear;
}

void Person::displayPersonInfo(std::ostream& output) const {
	output << id << "," << fullName << "," << birthYear << "," << address << "," << phone << "," << email;
}


