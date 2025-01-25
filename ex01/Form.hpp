#ifndef FORM_HPP
# define FORM_HPP

# include <sstream>
# include <string>
# include <stdexcept>
# include <iostream>
# include "Grade.hpp"
# include "Bureaucrat.hpp"


typedef Grade grade;

class Form
{
	private:
		const std::string _name;
		const grade _requirement;
		bool _signed;
	
	public:
		Form( void );
		Form( const std::string, int );
		Form( const Form & );
		~Form( void );

		Form & operator=(const Form & );

		const std::string& Name( void ) const;
		const grade& Requirement( void ) const;
		bool isSigned( void );

		bool beSigned( const Bureaucrat& );

		class GradeTooHighException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooHighException( const std::string& );
				virtual ~GradeTooHighException() throw();
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooLowException( const std::string& );

				virtual ~GradeTooLowException() throw();
				const char* what() const throw();
		};
};

#endif