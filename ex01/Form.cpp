#include "Form.hpp"

Form::Form() : _name("nameless"), _requirement(Grade(100)) {}

// "'"SUPERT SMART"'"" function to pass subject
static Grade validateGrade(int grade_value)
{
	try
	{
		return Grade(grade_value);
	}
	catch (const Grade::GradeTooHighException& e)
	{
		throw Form::GradeTooHighException(e.what());
	}
	catch (const Grade::GradeTooLowException& e)
	{
		throw Form::GradeTooLowException(e.what());
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

Form::Form(const std::string name, int grade_value) : _name(name), _requirement(validateGrade(grade_value)) {}

Form::Form(const Form& other) : _name(other._name), _requirement(other.Requirement().Value()) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) { if (this != &other) { std::cout << "cant do this assigment op"<< std::endl; } return *this; }

const std::string& Form::Name( void ) const { return this->_name; }
const grade& Form::Requirement( void ) const { return this->_requirement; }
bool Form::isSigned( void ) { return this->_signed; }

bool Form::beSigned(const Bureaucrat& b)
{
	if (!this->isSigned())
	{
		const grade b_grade = b.getGrade();
		if (b_grade < this->_requirement)
		{
			throw Bureaucrat::GradeTooLowException("Bureucrat grade is not suficient to sign form");
		}
		return true;
	}
	return false;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& message) 
{
	std::stringstream ss;
	ss << "FormHighRequirement: " << message;
	_message = ss.str();
}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Form::GradeTooHighException::what() const throw() { return _message.c_str(); }



Form::GradeTooLowException::GradeTooLowException(const std::string& message)
{
	std::stringstream ss;
	ss << ": " << "FormLowRequirement: " << message;
	_message = ss.str();
}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Form::GradeTooLowException::what() const throw() { return _message.c_str(); }


std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.Name().c_str() << ", Form grade " << f.Requirement() << "."; ;//<< f.Requirement() << "."; why this does not work
	return (os);
}