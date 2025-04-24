#ifndef FORM_HPP
# define FORM_HPP

# include <sstream>
# include <string>
# include <stdexcept>
# include <iostream>
# include "Grade.hpp"
# include "Bureaucrat.hpp"


#ifndef EX02
#define FORM Form
#else
#define FORM AForm
#endif

class Bureaucrat;

class FORM
{
	private:
		const std::string _name;
		#ifdef EX02
		std::string _target;
		#endif
		const grade _signRequirement;
		const grade _executeRequirement;
		bool _signed;
	
	public:
		FORM( void );
		#ifndef EX02
		FORM( const std::string, int , int );
		~FORM( void );
		#else
		FORM( const std::string, std::string, int, int);
		virtual ~FORM( void );
		#endif
		FORM( const FORM & );

		FORM & operator=(const FORM & );

		#ifndef EX02
		const std::string& Name( void ) const;
		const grade& GetSignRequirement( void ) const;
		const grade& GetExecRequirement( void ) const;
		#else
		const std::string& Name( void ) const;
		const grade& GetSignRequirement( void ) const;
		const grade& GetExecRequirement( void ) const;
		const std::string& Target( void ) const;
		void SetTarget( std::string );
		#endif

		bool isSigned( void ) const;
		void beSigned( const Bureaucrat& );

		#ifdef EX02
		virtual void execute( Bureaucrat const & ) const;
		virtual void beExecuted( void ) const = 0;
		#endif

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

		class SignatureException: public std::exception {
			private:
				std::string _message;
			public:
				SignatureException( const std::string& );
				virtual ~SignatureException() throw();
				const char* what() const throw();
		};

		class FormExecutionException: public std::exception {
			private:
				std::string _message;
			public:
				FormExecutionException( const std::string& );
				virtual ~FormExecutionException() throw();
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const FORM& f);

#endif