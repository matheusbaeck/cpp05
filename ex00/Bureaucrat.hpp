#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <sstream>
# include <string>
# include <stdexcept>
# include <iostream>

#ifndef MAX_GRADE
# define MAX_GRADE 1
#endif

#ifndef MIN_GRADE
# define MIN_GRADE 150
#endif

class GradeTooHighException;

class GradeTooLowException;

class Bureaucrat
{
	private:

		class Grade
		{
			int _value;
			static const int _min_grade;
			static const int _max_grade;

			bool isValidGrade(int value, std::string caller)
			{
				if (value < _max_grade)
					throw Bureucrat::GradeTooHighException(_max_grade, caller);
				if (value > _min_grade)
					throw Bureaucrat::GradeTooLowException(_min_grade, caller);
				return (true);
			}

			Grade( void ) {}

			public:

				Grade(int value) { 
					if (isValidGrade(value, "ctor")) {
						_value = value;
					}
				}
				Grade(const Grade & src) { *this = src; }
				~Grade() {}

				int Value() const { return _value; }

				Grade& operator=(const Grade& other) {
					if (*this != other) {
						this->_value = other._value;
					}
					return *this;
				}

				Grade& operator++() {
					if (isValidGrade(_value - 1, "operator++")) {
						--_value;
					}
					return *this;
				}

				Grade& operator--()
				{
					if (isValidGrade(_value + 1, "operator--")) {
						++_value;
					}
					return *this;
				}

				Grade& operator+=(int delta) {
					if (isValidGrade(_value - delta, "operator+=")) {
						_value -= delta;
					}
					return *this;
				}

				Grade& operator-=(int delta) {
					if (isValidGrade(_value + delta, "operator-=")) {
						_value += delta;
					}
					return *this;
				}

				Grade& operator=(int value)
				{
					if (isValidGrade(value, "operator=")) {
						_value = value;
					}
					return *this;
				}

				bool operator==(const Grade& other) const { return _value == other._value; }
				bool operator!=(const Grade& other) const { return _value != other._value; }
				bool operator<(const Grade& other) const { return _value > other._value; }
				bool operator>(const Grade& other) const { return _value < other._value; }
				bool operator<=(const Grade& other) const { return _value >= other._value; }
				bool operator>=(const Grade& other) const { return _value <= other._value; }
		};
		const std::string _name;
		Grade _grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string&, int );
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=( const Bureaucrat& );

		const std::string &	getName() const;
		Grade & 			getGrade();
		int					getGradeValue() const;

		class GradeTooHighException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooHighException(int maxGrade, std::string caller) {
					std::stringstream ss;
					ss << caller << ": " << "Grade too high! Must be " << maxGrade << " or greater.";
					_message = ss.str();
				}

				virtual ~GradeTooHighException() throw() {}

				const char* what() const throw() {
					return _message.c_str();
				}
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooLowException(int minGrade, std::string caller) {
					std::stringstream ss;
					ss << caller << ": " << "Grade too low! Must be " << minGrade << " or lower.";
					_message = ss.str();
				}

				virtual ~GradeTooLowException() throw() {}

				const char* what() const throw() {
					return _message.c_str();
				}
		};

};

#endif