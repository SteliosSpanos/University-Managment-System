#include "SystemRegister.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>

SystemRegister::SystemRegister() {}

SystemRegister::~SystemRegister() {
	for(auto c : courses){
		delete c;
	}
	for(auto m : members){
		delete m;
	}
	courses.clear();
	members.clear();
}

Course* SystemRegister::findCourseById(const std::string& id) {
	for(auto c : courses){
		if(c->getCourseId() == id){
			return c;
		}
	}
	return nullptr;
}

Person* SystemRegister::findMemberById(const std::string& id) {
	for(auto m : members){
		if(m->getId() == id){
			return m;
		}
	}
	return nullptr;
}

void SystemRegister::addCourse(Course* c) {
	if(findCourseById(c->getCourseId())){
		throw std::runtime_error("Το μάθημα υπάρχει ήδη");
	}
	courses.push_back(c);
}

void SystemRegister::editCourse(const std::string& id, const std::string& newName, unsigned int newSemester, Professor* newProf) {
	Course* c = findCourseById(id);
	if(!c){
	 	throw std::runtime_error("Το μάθημα δε βρέθηκε");
	}
	c->setCourseName(newName);
	c->setCourseSemester(newSemester);
	c->setCourseProfessor(newProf);
}

void SystemRegister::removeCourse(const std::string& id) {
	for(size_t i = 0; i < courses.size(); i++){
		if(courses[i]->getCourseId() == id){
			delete courses[i];
			courses.erase(courses.begin() + i);
			return;
		}
	}
	throw std::runtime_error("Το μάθημα δεν βρέθηκε");
}

void SystemRegister::addMember(Person* p) {
	if(findMemberById(p->getId())){
		throw std::runtime_error("Το μέλος υπάρχει ήδη");
	}
	members.push_back(p);
}

void SystemRegister::editMember(const std::string& id, Person* newMember) {
	for(size_t i = 0; i < members.size(); i++){
		if(members[i]->getId() == id){
			delete members[i];
			members[i] = newMember;
			return;
		}
	}
	throw std::runtime_error("Το μέλος δε βρέθηκε");
}

void SystemRegister::removeMember(const std::string& id) {
	for(size_t i = 0; i < members.size(); i++){
		if(members[i]->getId() == id){
			delete members[i];
			members.erase(members.begin() + i);
			return;
		}
	}
	throw std::runtime_error("Το μέλος δε βρέθηκε");
}

void SystemRegister::sendEmailToProf(const std::string& message) {
	for(auto p : members){
		Professor* prof = dynamic_cast<Professor*>(p);
		if(prof){
			prof->receiveEmail(message);
		}
	}
}

void SystemRegister::sendEmailToStudents(const std::string& message) {
	for(auto p : members){
		Student* student = dynamic_cast<Student*>(p);
		if(student){
			student->receiveEmail(message);
		}
	}
}

void SystemRegister::setStudentGrade(const std::string& studentId, const std::string& courseId, int grade) {
	Person* p = findMemberById(studentId);
	if(!p){
		throw std::runtime_error("Ο μαθητής δε βρέθηκε");
	}
	Student* student = dynamic_cast<Student*>(p);
	if(!student){
		throw std::runtime_error("Το μέλος δεν είναι μαθητής");
	}
	Course* course = findCourseById(courseId);
	if(!course){
		throw std::runtime_error("Το μάθημα δε βρέθηκε");
	}
	student->setGrade(course, grade);
}

void SystemRegister::saveToCSV(const std::string& coursesFile, const std::string& membersFile) const {
	std::ofstream cFile(coursesFile);
	if(!cFile.is_open()){
		throw std::runtime_error("Αδύνατο το άνοιγμα του αρχείου των μαθημάτων");
	}
	for(auto c : courses){
		c->displayCourseInfo(cFile);
	}
	cFile.close();

	std::ofstream mFile(membersFile);
	if(!mFile.is_open()){
		throw std::runtime_error("Αδύνατο το άνοιγμα του αρχείου των μελών");
	}
	for(auto m : members){
		m->displayInfo(mFile);
	}
	mFile.close();
}

void SystemRegister::loadFromCSV(const std::string& coursesFile, const std::string& membersFile) {
	for(auto c : courses){
		delete c;
	}
	for(auto m : members){
		delete m;
	}
	courses.clear();
	members.clear();

	std::ifstream mFile(membersFile);
	if(!mFile.is_open()){
		throw std::runtime_error("Αδύνατο το άνοιγμα του αρχείου των μελών");
	}
	std::string line1;
	while(std::getline(mFile, line1)){
		std::istringstream ss(line1);
		std::string type, id, name, email, word1, word2;
		std::getline(ss, type, ',');
		std::getline(ss, id, ',');
		std::getline(ss, name, ',');
		std::getline(ss, email, ',');
		std::getline(ss, word1, ',');
		std::getline(ss, word2, ',');
		if(type == "Φοιτητής"){
			unsigned int semester = std::atoi(word2.c_str());
			members.push_back(new Student(word1, id.c_str(), name, email, semester));
		}
		else if(type == "Καθηγητής"){
			members.push_back(new Professor(word1, id.c_str(), name, email, word2));
		}
		else{
			std::cerr << "Άγνωστος τύπος μέλους" << std::endl;
		}
	}
	mFile.close();

	std::ifstream cFile(coursesFile);
	if(!cFile.is_open()){
		throw std::runtime_error("Αδύνατο το άνοιγμα του αρχείου των μαθημάτων");
	}
	std::string line2;
	while(std::getline(cFile, line2)){
		std::istringstream ss(line2);
		std::string id, name, semesterString, profId;
		std::getline(ss, id, ',');
		std::getline(ss, name, ',');
		std::getline(ss, semesterString, ',');
		std::getline(ss, profId, ',');

		unsigned int semester = std::atoi(semesterString.c_str());
		Professor* matchedProf = nullptr;
		for(auto m : members){
			Professor* professor = dynamic_cast<Professor*>(m);
			if(professor && professor->getProfessorId() == profId){
				matchedProf = professor;
				break;
			}
		}
		if(matchedProf){
			courses.push_back(new Course(id, name, semester, matchedProf));
		}
		else{
			std::cerr << "Δεν βρέθηκε καθηγητής" << std::endl;
		}
	}
	cFile.close();
}

void SystemRegister::displaySystem() const {
	if(members.empty()){
		std::cout << "Δεν υπάρχει κανένα μέλος" << std::endl;
	}
	else{
		std::cout << "----ΜΕΛΗ ΣΥΣΤΉΜΑΤΟΣ----" << std::endl;
		for(const auto& m : members){
			m->displayInfo(std::cout);
		}
	}

	if(courses.empty()){
		std::cout << "Δεν υπάρχει κανένα μάθημα" << std::endl;
	}
	else{
		std::cout << "----ΜΑΘΗΜΑΤΑ----" << std::endl;
		for(const auto& c : courses){
			c->displayCourseInfo(std::cout);
		}
	}
}
