#include "PresidentialPardonForm.hpp"

#define CONCRETE_FORM PresidentialPardonForm
#define SIGN_GRADE 72
#define EXEC_GRADE 45
#define NAME "PresidentialPardon"


CONCRETE_FORM::CONCRETE_FORM(void)
	: AForm(NAME, "nobody", SIGN_GRADE, EXEC_GRADE) {}
CONCRETE_FORM::CONCRETE_FORM(std::string target)
	: AForm(NAME, target, SIGN_GRADE, EXEC_GRADE) {}
CONCRETE_FORM::CONCRETE_FORM( const CONCRETE_FORM& other)
	: AForm(NAME, other.Target(), SIGN_GRADE, EXEC_GRADE) {}
CONCRETE_FORM::~CONCRETE_FORM() {}

CONCRETE_FORM& CONCRETE_FORM::operator=(const CONCRETE_FORM& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void CONCRETE_FORM::beExecuted() const
{
	std::cout << Target() << "has been pardoned by Zaphod Beeblebrox.." << std::endl;
}

#undef CONCRETE_FORM
#undef SIGN_GRADE
#undef EXEC_GRADE
#undef NAME