#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

#define SIGN_GRADE 72
#define EXEC_GRADE 45
#define NAME "RobotomyRequest"

class RobotomyRequestForm : AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string, std::string );
		RobotomyRequestForm( const RobotomyRequestForm& );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& );

		virtual bool beSigned(const Bureaucrat& )
};

RobotomyRequestForm::RobotomyRequestForm(void) _target("target")
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) _target(target)
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE) {}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other)
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE)
{
	if (*this != other)
	{
		this->_target = other.Target;
	}
	return *this;
}

void RobotomyRequestForm::beExecuted()
{
	/*Makes some drilling noises. Then, informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, informs that the robotomy failed*/
	std::cout << /* some message */ << std::endl;
	/* throw error */
	return false;
}

#endif
