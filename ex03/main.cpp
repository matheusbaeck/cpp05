#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include FORM_INCLUDE
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <sstream>
#include <fstream>
#include <iostream>

int main()
{
	std::ostringstream os;
	try
	{
		Intern intern;
		const AForm& shrub = intern.makeForm("Shrubbery", "Zaz");
		intern.trackAndClean(const_cast<AForm*>(&shrub));
		std::cout << "[✅] Intern created: " << shrub << std::endl;

		const AForm& robot = intern.makeForm("Robotomy", "Thor");
		intern.trackAndClean(const_cast<AForm*>(&robot));
		std::cout << "[✅] Intern created: " << robot << std::endl;

		const AForm& pardon = intern.makeForm("Presidential", "Mamagalh");
		intern.trackAndClean(const_cast<AForm*>(&pardon));
		std::cout << "[✅] Intern created: " << pardon << std::endl;

		// Should throw
		const AForm& fail = intern.makeForm("UnknownForm", "Nobody");
		intern.trackAndClean(const_cast<AForm*>(&fail));
		std::cout << "[❌] This should not print!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[✅] Intern error caught as expected: " << e.what() << std::endl;
	}

	return 0;
}
