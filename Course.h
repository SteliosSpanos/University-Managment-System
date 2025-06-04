#pragma once
#include <string>
#include "Professor.h"

class Course{
private:
	std::string courseId;
	std::string courseName;
	unsigned int semester;
	Professor* professor;
public:
	Course(const std::string& _courseId, const std::string& _courseName, unsigned int _semester, Professor* _professor);

	std::string getCourseId() const;
	std::string getCourseName() const;
	unsigned int getCourseSemester() const;
	Professor* getCourseProfessor() const;

	void setCourseId(const std::string& _courseId);
	void setCourseName(const std::string& _courseName);
	void setCourseSemester(unsigned int _semester);
	void setCourseProfessor(Professor* _professor);

	void displayCourseInfo(std::ostream& output) const;
};
