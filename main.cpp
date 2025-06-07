#include "SystemRegister.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include <iostream>

int main() {
	SystemRegister reg;

	Professor* p1 = new Professor("12345", "Κ001", "Κώστας Παπαδόπουλος", "kpap@gmail.com", "Προγραμματισμός");
	reg.addMember(p1);

	Student* s1 = new Student("24390042", "Φ001", "Στέλιος Σπανός", "st@gmail.com", 2);
	reg.addMember(s1);

	Course* c1 = new Course("CS101", "Εισαγωγή στον Προγραμματισμό", 2, p1);
	reg.addCourse(c1);

	s1->enrollCourse(c1);
	reg.setStudentGrade("Φ001", "CS101", 5);

	reg.displaySystem();

	reg.saveToCSV("courses.csv", "members.csv");


	SystemRegister reg2;

	reg2.loadFromCSV("courses.csv", "members.csv");
	std::cout << "----Μετά την φόρτωση από CSV----" << std::endl;
	reg2.displaySystem();

	reg2.sendEmailToStudents("16/6 Εξέταση");
	reg2.sendEmailToProf("13:00 Συνέδριο Καθηγητών");

	return 0;
}
