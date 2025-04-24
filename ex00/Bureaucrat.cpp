#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade_value) : _name(name), _grade(validateGrade(grade_value)) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other.getGradeToInt()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) { if (this != &other) { _grade = other.getGradeToInt(); } return *this; }


const std::string &	Bureaucrat::getName() const	{ return _name; }
grade& Bureaucrat::getGrade()					{ return _grade; }
const grade& Bureaucrat::getGrade() const		{ return _grade; }
int Bureaucrat::getGradeToInt() const			{ return _grade.Value(); }



/*
Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
 */
//Method to catch Grade::Exception and throw Burocrat::Exception
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

void Bureaucrat::incrementGrade( int ammount )
{
	this->_grade += ammount;
}

void Bureaucrat::decrementGrade( int ammount )
{
	this->_grade -= ammount;
}

#ifndef EX00
void Bureaucrat::signForm(FORM & form) const
{
	try
	{
		form.beSigned(*this);
		// if (!form.beSigned(*this))
		// {
		// 	throw std::runtime_error("Form was already signed");
		// }
		std::cout << this->getName() << " signed form " << form.Name() << std::endl;
	}
	catch (const FORM::GradeTooLowException& e)
	{
		/* define a specific behavior for FORM::Grade low, maybe throw a Bureucrat exception*/
		throw;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.Name() << " because " << e.what() << std::endl;
	}
}
#endif

Grade Bureaucrat::validateGrade( int value )
{
	try
	{
		return Grade(value);
	}
	catch (const Grade::GradeTooHighException& e)
	{
		throw Bureaucrat::GradeTooHighException(e.what());
	}
	catch (const Grade::GradeTooLowException& e)
	{
		throw Bureaucrat::GradeTooLowException(e.what());
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGradeToInt() << ".";
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message = "") : _message(message) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message = "") : _message(message) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return _message.c_str();
}

#ifdef EX02
void Bureaucrat::executeForm(FORM const & f)
{
	try
	{
		f.execute(*this);
	}
	catch(FORM::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		throw Bureaucrat::GradeTooLowException(e.what());
	}
	catch(FORM::SignatureException& e)
	{
		std::cerr << e.what() << std::endl;
		throw;
	}
	catch(FORM::FormExecutionException& e)
	{
		std::cerr << e.what() << std::endl;
		throw;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Form ["<< *this <<"] execution failure: " << e.what() << std::endl;
		throw;
	}
}
#endif

// Bureaucrat::Grade operator+(const Grade& grade, int delta);
// Bureaucrat::Grade operator-(const Grade& grade, int delta);
// Bureaucrat::Grade operator+(int delta, const Grade& grade);
// Bureaucrat::Grade operator-(int delta, const Grade& grade);