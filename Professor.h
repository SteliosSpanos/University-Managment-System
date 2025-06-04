#pragma once
#include "Person.h"
#include <string>

class Professor : public Person{
private:
        std::string profId;
        std::string specialty;
public:
	Professor(const std::string& _profId, const char* _id, const std::string& _fullName, int _birthYear, const std::string& _address, const std::string& _phone, const std::string& _email, const std::string& _specialty);
        Professor(const std::string& _profId, const char* _id, const std::string& _fullName, const std::string& _email, const std::string& _specialty);

        std::string getProfessorId() const;
        std::string getSpecialty() const;

        void setProfessorId(const std::string& _profId);
        void setSpecialty(const std::string& _specialty);

        void displayInfo(std::ostream& output) const override;
	void receiveEmail(const std::string& message) const override;
};
