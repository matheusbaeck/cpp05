#include "Intern.hpp"


// === Non-member creator functions ===
AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// === Intern Implementation ===

Intern::Intern()
{
	_memory = NULL;
}

Intern::~Intern()
{
	internMemory* curr = _memory;
	while (curr)
	{
		internMemory* next = curr->next;
		delete curr->form;
		delete curr;
		curr = next;
	}
}

Intern::Intern(const Intern& other) : _memory(NULL)
{
	// Optional: deep copy memory if needed
	(void)other; // Suppress unused warning
}

void Intern::trackAndClean(AForm* form)
{
	internMemory* node = new internMemory(form);

	if (!_memory)
	{
		_memory = node;
		return;
	}

	internMemory* curr = _memory;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}

const AForm& Intern::makeForm(const std::string& formName, const std::string& target)
{
	const char* formNames[] = {
		"Shrubbery",
		"Robotomy",
		"Presidential"
	};

	fptrArray creators[] = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	const int formCount = sizeof(formNames) / sizeof(formNames[0]);

	for (int i = 0; i < formCount; ++i)
	{
		if (formName == formNames[i])
		{
			AForm* form = creators[i](target);
			return *form;
		}
	}

	throw std::runtime_error("Intern couldn't find form: " + formName);
}
