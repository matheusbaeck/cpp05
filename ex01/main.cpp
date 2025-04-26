# include "Bureaucrat.hpp"
# include "Form.hpp"

#define CASE (__COUNTER__ + 1)
#define DIV std::cout << std::endl << "-----------------<div>------------------" << std::endl << std::endl;

int main()
{
	std::stringstream	os;
	int					it = 0;
	// bool				form_should_be_signed = false;
	bool				end_cases = false;
	Bureaucrat			*b = NULL;
	Form				*f = NULL;

	while (!end_cases)
	{
		++it;
		try
		{
			switch (it)
			{
				case CASE: // Invalid grade: below 1
					f = new Form("f00", MAX_GRADE - 1, 75);
					break;
				
				case CASE: // Invalid grade: below 1
					f = new Form("f00", 75, MAX_GRADE - 1);
					break;

				case CASE: // Invalid grade: above 150
					f = new Form("f00", MIN_GRADE + 1, 0);
					break;

				case CASE: // Invalid grade: above 150
					f = new Form("f00", 75, MIN_GRADE + 1);
					break;

				case CASE: // grade to low to sign
					b = new Bureaucrat("b", MIN_GRADE);
					f = new Form("f00", MAX_GRADE, MIN_GRADE);
					f->beSigned(*b);
					break;

				case CASE: // grade to low to sign
					b = new Bureaucrat("b", MIN_GRADE);
					f = new Form("f00", MIN_GRADE - 1, MIN_GRADE);
					f->beSigned(*b);
					break;
				
				case CASE: // grade to low to sign
					b = new Bureaucrat("b", MAX_GRADE + 1);
					f = new Form("f00", MAX_GRADE, MIN_GRADE);
					f->beSigned(*b);
					break;

				case CASE:
					// form_should_be_signed = true;
					b = new Bureaucrat("b", MAX_GRADE);
					f = new Form("f00", MAX_GRADE, MAX_GRADE);
					f->beSigned(*b);
					if (f->isSigned())
					{
						f->beSigned(*b);
					}
					break;

				default:
					end_cases = true;
					std::cout << "----------<end of error cases>----------" << std::endl;
					break;
			}
			if (!end_cases)
				std::cerr << "[❌]" << it << ": case did not throwed apropriated err" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "[✅] " << it << ": "<< e.what() << std::endl;
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
	}
	it = 0;
	try
	{
		DIV
		b = new Bureaucrat("Bureaucrat", MIN_GRADE);
		f = new Form("Form", 75, 70);
		std::cout	<< "Now we created "<< *b 
					<<" and a "<< *f
					<< std::endl << std::endl;
		b->signForm(*f);
		std::cout << (f->isSigned() ? "[❌] is signed when it should't" : "[✅] is't signed when it should't") << std:: endl;
		b->incrementGrade(100);
		b->signForm(*f);
		std::cout << (!f->isSigned() ? "[❌] is't signed when it should" : "[✅] is signed when it should") << std:: endl;
		DIV
	}
	catch (const std::exception& e)
	{
		std::cout << os.str() << std::endl;
		std::cout << "Failure " << it << " catched: " << e.what() << std::endl;
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
}