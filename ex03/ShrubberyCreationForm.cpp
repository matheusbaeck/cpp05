#include "ShrubberyCreationForm.hpp"

#define CONCRETE_FORM ShrubberyCreationForm
#define SIGN_GRADE 145
#define EXEC_GRADE 137
#define NAME "ShrubberyCreation"

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
	std::string filename = Target() + "_shrubbery";
	std::ofstream outFile(filename.c_str());

	if (!outFile)
		throw AForm::FormExecutionException("Failed to create file: " + filename);

	outFile <<
		"       🌲" << std::endl <<
		"      🌳🌳" << std::endl <<
		"     🌲🌲🌲" << std::endl <<
		"    🌳🌳🌳🌳" << std::endl <<
		"   🌲🌲🌲🌲🌲" << std::endl <<
		"      ||||" << std::endl <<
		"      ||||" << std::endl;

	outFile.close();

	std::cout << "Shrubbery created at: " << filename << " 🌿" << std::endl;
}

#undef CONCRETE_FORM
#undef SIGN_GRADE
#undef EXEC_GRADE
#undef NAME