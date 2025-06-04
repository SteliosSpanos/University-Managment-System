#pragma once
#include <string>

class Person{
private:
	char* id;
	std::string fullName;
	int birthYear;
	std::string address;
	std::string phone;
	std::string email;
public:
	Person(const char* _id, const std::string& _fullName, int _birthYear, const std::string& _address, const std::string& _phone, const std::string& _email);
	Person(const char* _id, const std::string& _fullName, const std::string& _email);
	Person(const Person& p);
	virtual ~Person();

	char* getId() const;
	std::string getFullName() const;
	int getBirthYear() const;
	std::string getAddress() const;
	std::string getPhone() const;
	std::string getEmail() const;

	void setId(const char* _id);
	void setFullName(const std::string& _fullName);
	void setBirthYear(int _birthYear);
	void setAddress(const std::string& _address);
	void setPhone(const std::string& _phone);
	void setEmail(const std::string& _email);

	int calculateAge(int currentYear) const;
	virtual void displayInfo(std::ostream& output) const = 0;
	void displayPersonInfo(std::ostream& output) const;
	virtual void receiveEmail(const std::string& message) const = 0;
};
