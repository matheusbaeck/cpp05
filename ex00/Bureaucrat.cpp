#include "/home/math/repo/cpp05/ex00/Bureaucrat.hpp"

const int Bureaucrat::Grade::_min_grade = MIN_GRADE;
const int Bureaucrat::Grade::_max_grade = MAX_GRADE;

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(100) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade_value) : _name(name), _grade(Grade(grade_value)) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other.getGradeValue()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) { if (this != &other) { _grade = other.getGradeValue(); } return *this; }


const std::string &	Bureaucrat::getName() const			{ return _name; }
Bureaucrat::Grade & Bureaucrat::getGrade()				{ return _grade; }
int Bureaucrat::getGradeValue() const	{ return _grade.Value(); }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGradeValue() << ".";
	return (os);
}

// Bureaucrat::Grade operator+(const Grade& grade, int delta);
// Bureaucrat::Grade operator-(const Grade& grade, int delta);
// Bureaucrat::Grade operator+(int delta, const Grade& grade);
// Bureaucrat::Grade operator-(int delta, const Grade& grade);