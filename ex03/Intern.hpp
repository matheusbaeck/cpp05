#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <stdexcept>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

typedef AForm* (*fptrArray)(const std::string&);

struct internMemory
{
	AForm*			form;
	internMemory*	next;

	internMemory(AForm* f) : form(f), next(NULL) {}
};

// === Non-member creator functions ===
AForm* createShrubbery(const std::string& target);
AForm* createRobotomy(const std::string& target);
AForm* createPresidential(const std::string& target);

// === Intern class ===
class Intern
{
	private:
		internMemory* _memory;

	public:
		Intern();
		Intern(const Intern&);
		~Intern();

		const AForm& makeForm(const std::string& formName, const std::string& target);
		void trackAndClean(AForm* form);
};

// Intern::~Intern()
// {
// 	internMemory* curr = _memory;
// 	while (curr)
// 	{
// 		internMemory* next = curr->next;
// 		delete curr->form;
// 		delete curr;
// 		curr = next;
// 	}
// }



// void Intern::trackAndClean(AForm* form)
// {
// 	internMemory* node = new internMemory(form);

// 	if (!_memory)
// 	{
// 		_memory = node;
// 		return;
// 	}
// 	internMemory* curr = _memory;
// 	while (curr->next)
// 		curr = curr->next;
// 	curr->next = node;
// }


// const AForm& Intern::makeForm(const std::string& formName, const std::string& target)
// {
// 	static const char* formNames[] = {
// 		"Shrubbery",
// 		"Robotomy",
// 		"Presidential"
// 	};

// 	static fptrArray creators[] = {
// 		&createShrubbery,
// 		&createRobotomy,
// 		&createPresidential
// 	};

// 	const int formCount = sizeof(formNames) / sizeof(formNames[0]);

// 	for (int i = 0; i < formCount; ++i)
// 	{
// 		if (formName == formNames[i])
// 		{
// 			AForm* form = creators[i](target);
// 			return *form;
// 		}
// 	}
// 	throw std::runtime_error("Intern couldn't find form: " + formName);
// }

#endif