#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <sstream>
# include <string>
# include <stdexcept>
# include <iostream>
#include "Grade.hpp"


typedef Grade grade;

class Bureaucrat
{
	private:
		const std::string _name;
		grade _grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string&, int );
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=( const Bureaucrat& );

		const std::string &	getName() const;
		grade & 			getGrade();
		const grade & 		getGrade() const;
		int					getGradeToInt() const;
		void				changeGrade( int );

		class GradeTooHighException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooHighException(std::string message = "") : _message(message) {}

				virtual ~GradeTooHighException() throw() {}

				const char* what() const throw() {
					return _message.c_str();
				}
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooLowException(std::string message = "") : _message(message) {}

				virtual ~GradeTooLowException() throw() {}

				const char* what() const throw() {
					return _message.c_str();
				}
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif