#ifndef PRESENTIALPARDONFORM_HPP
# define PRESENTIALPARDONFORM_HPP

#include "Form.hpp"

#define SIGN_GRADE 72
#define EXEC_GRADE 45
#define NAME "PresidentialPardon"

typedef class Form AForm

class PresidentialPardonForm : AForm
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string, std::string );
		PresidentialPardonForm( const PresidentialPardonForm& );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& );

		virtual bool beSigned(const Bureaucrat& )
};

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm(NAME, "nobody", SIGN_GRADE, EXEC_GRADE) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) _target(target)
	: AForm(NAME, target, SIGN_GRADE, EXEC_GRADE) {}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other)
	: AForm(NAME, other.Target(), SIGN_GRADE, EXEC_GRADE)

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void PresidentialPardonForm::beExecuted()
{
	/*Informs that <target> has been pardoned by Zaphod Beeblebrox..*/
	std::cout << /* some message */ << std::endl;
	/* throw error */
	return false;
}

#endif