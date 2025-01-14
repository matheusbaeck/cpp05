#include "Form.hpp"

Form::Form() : _name("nameless"), _grade(100) {}

Form::Form(const std::string& name, int grade_value) : _name(name), _grade(Grade(grade_value)) {}

Form::Form(const Form& other) : _name(other._name), _grade(other.getGradeValue()) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) { if (this != &other) { _grade = other.getGradeValue(); } return *this; }


std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", Form grade " << f.getRequirement() << ".";
	return (os);
}