#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

#define SIGN_GRADE 145
#define EXEC_GRADE 137
#define NAME "ShrubberyCreationForm"

typedef class Form AForm

class ShrubberyCreationForm : AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string, std::string );
		ShrubberyCreationForm( const ShrubberyCreationForm& );
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& );

		virtual bool beSigned(const Bureaucrat& )
};

ShrubberyCreationForm::ShrubberyCreationForm(void) _target("target")
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) _target(target)
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE) {}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other)
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE)
{
	if (*this != other)
	{
		// here can i use the base = operator?
		this->_target = other.Target;
	}
	return *this;
}

void ShrubberyCreationForm::beExecuted()
{
	/*Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.*/
	std::cout << /* some message */ << std::endl;
	/* throw error */
	return false;
}

#endif