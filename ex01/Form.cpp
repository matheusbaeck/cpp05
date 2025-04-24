#include FORM_INCLUDE

// "'"SUPERT SMART"'"" function to pass subject
static Grade validateGrade(int grade_value)
{
	try
	{
		return Grade(grade_value);
	}
	catch (const Grade::GradeTooHighException& e)
	{
		throw FORM::GradeTooHighException(e.what());
	}
	catch (const Grade::GradeTooLowException& e)
	{
		throw FORM::GradeTooLowException(e.what());
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

#ifndef EX02
FORM::FORM()
	:	_name("form"),
		_signRequirement(Grade(100)),
		_executeRequirement(Grade(100)),
		_signed(false) {}

FORM::FORM(const std::string name, int signGrade, int execGrade)
	:	_name(name),
		_signRequirement(validateGrade(signGrade)),
		_executeRequirement(validateGrade(execGrade)),
		_signed(false) {}

FORM::FORM(const FORM& other)
	:	_name(other._name),
		_signRequirement(other.GetSignRequirement().Value()),
		_executeRequirement(other.GetExecRequirement().Value()),
		_signed(false) {}
#else
FORM::FORM()
	:	_name("form"),
		_target("nobody"),
		_signRequirement(Grade(100)),
		_executeRequirement(Grade(100)),
		_signed(false) {}

FORM::FORM(const std::string name, std::string target, int signGrade, int execGrade)
	:	_name(name),
		_target(target),
		_signRequirement(validateGrade(signGrade)),
		_executeRequirement(validateGrade(execGrade)),
		_signed(false) {}

FORM::FORM(const FORM& other)
	:	_name(other._name),
		_target(other._target),
		_signRequirement(other.GetSignRequirement().Value()),
		_executeRequirement(other.GetExecRequirement().Value()),
		_signed(false) {}

#endif

FORM::~FORM() {}

FORM& FORM::operator=(const FORM& other)
{ 
	if (this != &other) 
	{
		this->_signed = false;
		#ifdef EX02
		this->_target = other._target;
		#endif
	}
	return *this;
}

const std::string& FORM::Name( void ) const { return this->_name; }
const grade& FORM::GetSignRequirement( void ) const { return this->_signRequirement; }
const grade& FORM::GetExecRequirement( void ) const { return this->_executeRequirement; }
bool FORM::isSigned( void ) const { return this->_signed; }

#ifdef EX02
const std::string& FORM::Target( void ) const
{
	return _target;
}
#endif


void FORM::beSigned(const Bureaucrat& b)
{
	if (this->isSigned()) throw FORM::SignatureException("is already signed");
	const grade& b_grade = b.getGrade();
	if (b_grade < this->_signRequirement)
	{
		throw FORM::GradeTooLowException("Bureucrat grade is not suficient to sign form");
	}
	_signed = true;
}

#ifdef EX02
void FORM::execute(Bureaucrat const & b) const
{
	if(!this->_signed)
		throw std::runtime_error("form not signed");
	if(b.getGrade() < this->_executeRequirement)
		throw FORM::GradeTooLowException("grade to low to execute");
	this->beExecuted();
}
#endif

FORM::GradeTooHighException::GradeTooHighException(const std::string& message) { _message = message; }
FORM::GradeTooHighException::~GradeTooHighException() throw() {}
const char* FORM::GradeTooHighException::what() const throw() { return _message.c_str(); }

FORM::GradeTooLowException::GradeTooLowException(const std::string& message) { _message = message; }
FORM::GradeTooLowException::~GradeTooLowException() throw() {}
const char* FORM::GradeTooLowException::what() const throw() { return _message.c_str(); }

FORM::SignatureException::SignatureException(const std::string& message) { _message = message; }
FORM::SignatureException::~SignatureException() throw() {}
const char* FORM::SignatureException::what() const throw() { return _message.c_str(); }

FORM::FormExecutionException::FormExecutionException(const std::string& message) { _message = message; }
FORM::FormExecutionException::~FormExecutionException() throw() {}
const char* FORM::FormExecutionException::what() const throw() { return _message.c_str(); }

std::ostream& operator<<(std::ostream& os, const FORM& f)
{
	os << "Form " << f.Name();
	#ifdef EX02
	os << ", Target:" << f.Target();
	#endif
	os << ", requirements: to sign(" 
	<< f.GetSignRequirement() << "), to execute(" 
	<< f.GetExecRequirement() << ").";
	return (os);
}
