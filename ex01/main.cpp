# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
	std::stringstream	os;
	int					it = 0;
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
				case 1: // Invalid grade: below 1
					f = new Form("f00", 0, 0);
					break;

				case 2: // Invalid grade: above 150
					f = new Form("f00", 151, 151);
					break;

				case 3:
					b = new Bureaucrat("b", 100);
					f = new Form("f00", 75, 70);
					//b->signForm(*f);
					f->beSigned(*b);
					break;

				default:
					end_cases = true;
					std::cout << "----end of error cases-----" << std::endl;
					break;
			}
			if (!end_cases)
				std::cerr << "Failure: " << it << ": case did not throwed apropriated err" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Success: " << it << ": "<< e.what() << std::endl;
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
		b = new Bureaucrat("b", 50);
		f = new Form("f00", 75, 70);
		std::cout	<< "Now we created a Bureucrat ["<< *b 
					<<"] and a Form ["<< f <<"]."
					<< std::endl;
		std::cout << "b sign f00: ";
		b->signForm(*f);
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