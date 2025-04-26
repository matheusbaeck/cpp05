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

void Bureaucrat::changeGrade(int newGrade)
{
	try
	{
		grade old = this->_grade;
		_grade = newGrade;
		std::cout << *this << " changed it's grade " << old << std::endl;
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
	try
	{
		grade old = this->_grade;
		this->_grade += ammount;
		std::cout << *this << " incremented it's grade " << old << " by " << ammount << std::endl;
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

void Bureaucrat::decrementGrade( int ammount )
{
	try
	{
		grade old = this->_grade;
		this->_grade -= ammount;
		std::cout << *this << " decremented it's grade " << old << " by " << ammount << std::endl;
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

#ifndef EX00
void Bureaucrat::signForm(FORM & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed form " << form.Name() << std::endl;
	}
	catch (const FORM::SignatureException& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.Name() << " because " << e.what() << std::endl;
		std::cout << "Try signing a diferent Form" << std::endl;
	}
	catch (const FORM::GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.Name() << " because " << e.what() << std::endl;
		std::cout << "You need a grade higher than " << form.GetSignRequirement() << " to sign form " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.Name() << " because " << e.what() << std::endl;
	}
}
#endif


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << "[Grade:" << b.getGradeToInt() << "]";
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