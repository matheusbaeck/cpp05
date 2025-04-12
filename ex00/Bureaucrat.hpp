#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <sstream>
# include <string>
# include <stdexcept>
# include <iostream>

# include "Grade.hpp"

#ifndef EX00
# include "Form.hpp"

class FORM;
#endif

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
		void				incrementGrade( int );
		void 				decrementGrade( int );
		static Grade		validateGrade( int );
		#ifndef EX00
		void				signForm(FORM & ) const;
		#endif
		#ifdef EX02
		void executeForm(FORM const & form);
		#endif

		class GradeTooHighException : public std::exception {
			private:
				std::string _message;
			public:
				GradeTooHighException( std::string message );
				virtual ~GradeTooHighException() throw();
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooLowException( std::string message );
				virtual ~GradeTooLowException() throw();
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif