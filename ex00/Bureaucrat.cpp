#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(100) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade_value) : _name(name), _grade(grade_value) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other.getGradeToInt()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) { if (this != &other) { _grade = other.getGradeToInt(); } return *this; }


const std::string &	Bureaucrat::getName() const	{ return _name; }
Grade & Bureaucrat::getGrade()					{ return _grade; }
const grade & Bureaucrat::getGrade() const {return _grade; }
int Bureaucrat::getGradeToInt() const	{ return _grade.Value(); }

//Method to throw Burocrat::Exceptions
void Bureaucrat::changeGrade(int newGrade)
{
	try
	{
		_grade = newGrade;
	}
	catch(Grade::GradeTooLowException& e)
	{
		throw Bureaucrat::GradeTooLowException(e.what());
	}
	catch (Grade::GradeTooHighException& e)
	{
		throw Bureaucrat::GradeTooHighException(e.what());
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

// void signForm(const Form & form)
// {
// 	try
// 	{
// 		if (!form.beSigned(*this))
// 		{
// 			// form was already signed
// 		}
// 		//form signed
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
	
// }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGradeToInt() << ".";
	return (os);
}

// Bureaucrat::Grade operator+(const Grade& grade, int delta);
// Bureaucrat::Grade operator-(const Grade& grade, int delta);
// Bureaucrat::Grade operator+(int delta, const Grade& grade);
// Bureaucrat::Grade operator-(int delta, const Grade& grade);