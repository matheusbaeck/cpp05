#include "Bureaucrat.hpp"
#include FORM_INCLUDE
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#ifndef TARGET
# define TARGET "AnyBody"
#endif
#define BUREAUCRATE_NAME "Zaz"

#define CASE (__COUNTER__ + 1)

#define SIGN_LOW_GRADE(FormType) \
	case CASE: \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREUCRAT, MIN_GRADE); \
		os << *b << " Try to sign " << *f << " :"; \
		b->signForm(*f); \
		break; \

#define EXECUTE_LOW_GRADE(FormType) \
	case CASE: \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREAUCRATE_NAME, MAX_GRADE); \
		os << *b << " Try to execute " << *f << " :"; \
		b->signForm(*f); \
		b->changeGrade(MIN_GRADE); \
		b->executeForm(*f); \
		break; \

#define EXECUTE_NOT_SIGNED(FormType) \
	case CASE: \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREAUCRATE_NAME, MAX_GRADE); \
		os << *b << " Try to execute not signed " << *f << " :"; \
		b->executeForm(*f); \
		break; \

// Wrapper macro for full switch block
#define MUST_FAIL_CASES(FormType) \
		SIGN_LOW_GRADE(FormType) \
		EXECUTE_LOW_GRADE(FormType) \
		EXECUTE_NOT_SIGNED(FormType) \


#include <sstream>
#include <fstream>
#include <iostream>

void ReadFile(const std::string& fileName, std::ostringstream& out)
{
	std::ifstream file(fileName.c_str());

	if (!file.is_open())
	{
		out << "Failed to open file: " << fileName << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		out << line << std::endl;
	}

	file.close();
}

#define BUREUCRAT "james"
int main()
{
	std::ostringstream os;
	int it = 0;
	bool end_cases = false;
	Bureaucrat *b;
	AForm *f;

	while(!end_cases)
	{
		++it;
		try
		{
			switch (it)
			{
				MUST_FAIL_CASES(ShrubberyCreationForm);
				MUST_FAIL_CASES(RobotomyRequestForm);
				MUST_FAIL_CASES(PresidentialPardonForm);
				default:
					end_cases = true;
					std::cout << "----end of error cases-----" << std::endl;
					break;

			}
			if (!end_cases)
					std::cerr << "[❌ " << it << " " << os << "]: case did not throwed apropriated err" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "[✅ " << it << " " << os.str() << "]catched: "<< e.what() << std::endl;
		}
		//CLEANUP
		if (b != NULL) {
			delete b;
			b = NULL;
		}
		if (f != NULL) {
			delete f;
			f = NULL;
		}
		os.str("");
		os.clear();
	}

	it = 0;
	try
	{
	b	 = new Bureaucrat(BUREAUCRATE_NAME, MAX_GRADE);
		os << "[✅ " << ++it << "] Created Bureaucrat with MAX_GRADE: " << *b << std::endl;

		f = new ShrubberyCreationForm(TARGET);
		os << "[✅ " << ++it << "] Created ShrubberyCreationForm for TARGET" << std::endl;
		b->signForm(*f);
		os << "[✅ " << it << ".1] Signed form successfully" << std::endl;
		b->executeForm(*f);
		os << "[✅ " << it << ".2] Executed form successfully" << std::endl;
		os << "================= file:" << TARGET << " =================" << std::endl;
		ReadFile(std::string(TARGET) + "_shrubbery", os);
		os << "================= file:" << TARGET << " =================" << std::endl;
		delete f;

		f = new PresidentialPardonForm(TARGET);
		os << "[✅ " << ++it << "] Created PresidentialPardonForm for TARGET" << std::endl;
		b->signForm(*f);
		os << "[✅ " << it << ".1] Signed form successfully" << std::endl;
		b->executeForm(*f);
		os << "[✅ " << it << ".2] Executed form successfully" << std::endl;
		delete f;

		f = new RobotomyRequestForm(TARGET);
		os << "[✅ " << ++it << "] Created RobotomyRequestForm for TARGET" << std::endl;
		b->signForm(*f);
		os << "[✅ " << it << ".1] Signed form successfully" << std::endl;
		b->executeForm(*f);
		os << "[✅ " << it << ".2] Executed form successfully" << std::endl;
		delete f;
		delete b;

		std::cout << os.str();
	}
	catch(const std::exception& e)
	{
		std::cout << os.str() << std::endl;
		std::cout << "[❌ " << it << "]catched: " << e.what() << std::endl;
	}
	#if false
	#endif
	
	return (0);
}