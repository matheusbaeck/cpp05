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
				if (value < _min_grade && value > _max_grade)
					return (true);
				std::stringstream stream;
				stream << caller << ": Grade must be between " << _max_grade << " and " << _min_grade;
				//throw std::overflow_error(stream.str());
				throw std::out_of_range(stream.str());
				return (false);
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
};

#endif