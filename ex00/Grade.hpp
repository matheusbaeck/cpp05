#ifndef GRADE_HPP
# define GRADE_HPP

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


class Grade
{
	private:
		int _value;
		static const int _min_grade;
		static const int _max_grade;

		bool isValidGrade(int value, std::string caller) const;

	public:
		Grade( void );
		Grade( int );
		Grade( const Grade & );
		~Grade();

		int Value( void ) const;

		Grade& operator=( const Grade& );

		Grade& operator++( void );
		Grade& operator--( void );
		Grade& operator+=( int );
		Grade& operator-=( int );
		Grade& operator=( int );

		bool operator==( const Grade& ) const;
		bool operator!=( const Grade& ) const;
		bool operator<( const Grade& ) const;
		bool operator>( const Grade& ) const;
		bool operator<=( const Grade& ) const;
		bool operator>=( const Grade& ) const;


	class GradeTooHighException : public std::exception {
		private:
			std::string _message;

		public:
			GradeTooHighException(std::string caller);
			virtual ~GradeTooHighException() throw();
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		private:
			std::string _message;

		public:
			GradeTooLowException(std::string caller);

			virtual ~GradeTooLowException() throw();
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Grade& g);

# endif