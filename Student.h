#pragma once
#include "Person.h"
#include "Course.h"
#include <string>
#include <vector>

class Student : public Person{
private:
	std::string am;
	unsigned int semester;
	std::vector<std::pair<Course*, int>> courses;
public:
	Student(const std::string& _am, const char* _id, const std::string& _fullName, int _birthYear, const std::string& _address, const std::string& _phone, const std::string& _email, unsigned int semester);
	Student(const std::string& _am, const char* _id, const std::string& _fullName, const std::string& _email, unsigned int _semester);

	std::string getAm() const;
	unsigned int getSemester() const;

	void setAm(const std::string& _am);
	void setSemester(unsigned int _semester);

	void enrollCourse(Course* c);
	void setGrade(Course* c, int grade);
	int getGrade(Course* c) const;

	void displayInfo(std::ostream& output) const override;
	void receiveEmail(const std::string& message) const override;
};

