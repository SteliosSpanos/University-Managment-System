#include "Course.h"
#include <iostream>

Course::Course(const std::string& _courseId, const std::string& _courseName, unsigned int _semester, Professor* _professor)
: courseId(_courseId), courseName(_courseName), semester(_semester), professor(_professor) {}

std::string Course::getCourseId() const { return courseId; }
std::string Course::getCourseName() const { return courseName; }
unsigned int Course::getCourseSemester() const { return semester; }
Professor* Course::getCourseProfessor() const { return professor; }

void Course::setCourseId(const std::string& _courseId) { courseId = _courseId; }
void Course::setCourseName(const std::string& _courseName) { courseName = _courseName; }
void Course::setCourseSemester(unsigned int _semester) { semester = _semester; }
void Course::setCourseProfessor(Professor* _professor) { professor = _professor; }

void Course::displayCourseInfo(std::ostream& output) const {
	output << courseId << "," << courseName << "," << semester << ",";
	if(professor){
		output << professor->getProfessorId() << std::endl;
	}
	else{
		output << "Not Assigned" << std::endl;
	}
}
