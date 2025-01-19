#include "Grade.hpp"

const int Grade::_min_grade = MIN_GRADE;
const int Grade::_max_grade = MAX_GRADE;


bool Grade::isValidGrade(int value, std::string caller) const
{
	if (value < _max_grade)
		throw GradeTooHighException(caller);
	if (value > _min_grade)
		throw GradeTooLowException(caller);
	return (true);
}

Grade::Grade( void ) {}
Grade::Grade(int value) { if (isValidGrade(value, "ctor")) _value = value; }
Grade::Grade(const Grade & src) { *this = src; }
Grade::~Grade() {}

int Grade::Value() const { return _value; }

Grade& Grade::operator=(const Grade& other) { if (*this != other && isValidGrade(other.Value(), "operator=")) this->_value = other.Value(); return *this; }

Grade& Grade::operator++() 					{ if (isValidGrade(_value - 1, "operator++")) --_value; 			return *this; }
Grade& Grade::operator--() 					{ if (isValidGrade(_value + 1, "operator--")) ++_value; 			return *this; }
Grade& Grade::operator+=(int delta) 		{ if (isValidGrade(_value - delta, "operator+=")) _value -= delta; 	return *this; }
Grade& Grade::operator-=(int delta) 		{ if (isValidGrade(_value + delta, "operator-=")) _value += delta; 	return *this; }
Grade& Grade::operator=(int value) 			{ if (isValidGrade(value, "operator=")) _value = value; 			return *this; }

bool Grade::operator==(const Grade& other) const { return _value == other._value; }
bool Grade::operator!=(const Grade& other) const { return _value != other._value; }
bool Grade::operator<(const Grade& other) const { return _value > other._value; }
bool Grade::operator>(const Grade& other) const { return _value < other._value; }
bool Grade::operator<=(const Grade& other) const { return _value >= other._value; }
bool Grade::operator>=(const Grade& other) const { return _value <= other._value; }


Grade::GradeTooHighException::GradeTooHighException(std::string caller) {
	std::stringstream ss;
	ss << caller << ": " << "Grade too high! Must be " << _max_grade << " or greater.";
	_message = ss.str();
}

Grade::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Grade::GradeTooHighException::what() const throw() { return _message.c_str(); }

Grade::GradeTooLowException::GradeTooLowException(std::string caller) {
	std::stringstream ss;
	ss << caller << ": " << "Grade too low! Must be " << _min_grade << " or lower.";
	_message = ss.str();
}

Grade::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Grade::GradeTooLowException::what() const throw() { return _message.c_str(); }

std::ostream& operator<<(std::ostream& os, const Grade& g)
{
	os << g.Value();
	return os;
}