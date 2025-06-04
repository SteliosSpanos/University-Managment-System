#pragma once
#include "Course.h"
#include "Professor.h"
#include "Person.h"
#include "Student.h"
#include <vector>
#include <string>

class SystemRegister{
private:
	std::vector<Course*> courses;
	std::vector<Person*> members;

	Course* findCourseById(const std::string& id);
	Person* findMemberById(const std::string& id);

public:
	SystemRegister();
	~SystemRegister();

	void addCourse(Course* c);
	void editCourse(const std::string& id, const std::string& newName, unsigned int newSemester, Professor* newProf);
	void removeCourse(const std::string& id);

	void addMember(Person* p);
	void editMember(const std::string& id, Person* newMember);
	void removeMember(const std::string& id);

	void sendEmailToProf(const std::string& message);
	void sendEmailToStudents(const std::string& message);

	void setStudentGrade(const std::string& studentId, const std::string& courseId, int grade);

	void saveToCSV(const std::string& coursesFile, const std::string& membersFile) const;
	void loadFromCSV(const std::string& coursesFile, const std::string& membersFile);

	void displaySystem() const;

};
