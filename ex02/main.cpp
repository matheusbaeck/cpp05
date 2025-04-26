#include "Bureaucrat.hpp"
#include FORM_INCLUDE
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <sstream>
#include <fstream>
#include <iostream>

#ifndef TARGET
# define TARGET "AnyBody"
#endif

#define LOG(msg) std::cout << msg << std::endl;
#define ERR(msg) std::cerr << msg << std::endl;
#define DIV(div) std::cout << std::endl << "-----------------<"<<div<<">------------------" << std::endl << std::endl;

#define BUREAUCRAT "Bureaucrat"
#define CASE (__COUNTER__ + 1)

#define SIGN_LOW_GRADE(FormType) \
	case CASE: \
		DIV(#FormType) \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREAUCRAT, MIN_GRADE); \
		LOG(*b << " Try to sign " << *f << " :") \
		f->beSigned(*b); \
		break; \

#define DOUBLE_SIGN_CASE(FormType) \
	case CASE: \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREAUCRAT, MAX_GRADE); \
		b->signForm(*f); \
		if (f->isSigned()) \
		{ \
			LOG(*b << " Try to sign " << *f << " :") \
			f->beSigned(*b); \
		} \
		break; \

#define EXECUTE_LOW_GRADE(FormType) \
	case CASE: \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREAUCRAT, MAX_GRADE); \
		LOG(*b << " Try to execute " << *f << " :") \
		b->signForm(*f); \
		b->changeGrade(MIN_GRADE); \
		b->executeForm(*f); \
		break; \

#define EXECUTE_NOT_SIGNED(FormType) \
	case CASE: \
		f = new FormType(TARGET); \
		b = new Bureaucrat(BUREAUCRAT, MAX_GRADE); \
		LOG(*b << " Try to execute not signed " << *f << " :") \
		b->executeForm(*f); \
		break; \

#define MUST_FAIL_CASES(FormType) \
		SIGN_LOW_GRADE(FormType) \
		DOUBLE_SIGN_CASE(FormType) \
		EXECUTE_LOW_GRADE(FormType) \
		EXECUTE_NOT_SIGNED(FormType) \




void ReadFile(const std::string& fileName)
{
	std::ifstream file(fileName.c_str());

	if (!file.is_open())
	{
		LOG("Failed to open file: " << fileName);
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		LOG(line);
	}

	file.close();
}

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
					DIV("end of error cases")
					break;

			}
			if (!end_cases)
					LOG("[❌] " << it << " " << os << ": case did not throwed apropriated err")
		}
		catch(const std::exception& e)
		{
			LOG("[✅ " << it << " " << os.str() << "]catched: "<< e.what())
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
		DIV("Instance of Bureaucrate max grade" << MAX_GRADE)
		b	 = new Bureaucrat(BUREAUCRAT, MAX_GRADE);
		LOG("[✅] " << ++it << " Created Bureaucrat with MAX_GRADE: " << *b);


		DIV("Instance of ShrubberyCreationForm")
		f = new ShrubberyCreationForm(TARGET);
		LOG("[✅] " << ++it << " Created ShrubberyCreationForm for TARGET");
		b->signForm(*f);
		LOG("[✅ " << it << ".1 Signed form successfully");
		b->executeForm(*f);
		LOG("[✅] " << it << ".2 Executed form successfully");
		LOG("================= file:" << TARGET << " =================");
		ReadFile(std::string(TARGET) + "_shrubbery");
		LOG("================= file:" << TARGET << " =================");
		delete f;

		DIV("Instance of PresidentialPardonForm")
		f = new PresidentialPardonForm(TARGET);
		LOG("[✅] " << ++it << " Created PresidentialPardonForm for TARGET");
		b->signForm(*f);
		LOG("[✅] " << it << ".1 Signed form successfully");
		b->executeForm(*f);
		LOG("[✅] " << it << ".2 Executed form successfully");
		delete f;

		DIV("Instance of RobotomyRequestForm")
		f = new RobotomyRequestForm(TARGET);
		LOG("[✅] " << ++it << " Created RobotomyRequestForm for TARGET");
		b->signForm(*f);
		LOG("[✅] " << it << ".1 Signed form successfully");
		b->executeForm(*f);
		LOG("[✅] " << it << ".2 Executed form successfully");
		delete f;
		delete b;

	}
	catch(const std::exception& e)
	{
		ERR("[❌] " << it << "catched: " << e.what())
	}
	#if false
	#endif
	
	return (0);
}
