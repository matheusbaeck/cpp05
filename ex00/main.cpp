#include "Bureaucrat.hpp"

int main()
{
	std::stringstream	os;
	int					it = 0;
	bool				end_cases = false;
	Bureaucrat			*b;

	while (!end_cases)
	{
		++it;
		try
		{
			switch (it)
			{
				case 1: // Invalid grade: below 1
					b = new Bureaucrat("b", 0);
					break;

				case 2: // Invalid grade: above 150
					b = new Bureaucrat("b", 151);
					break;

				case 3: // Valid grade but trying to decrement below 1
					b = new Bureaucrat("b", 150);
					--b->getGrade();  // Should throw an exception because grade cannot go below 1
					break;

				case 4: // Valid grade but trying to increment above 150
					b = new Bureaucrat("b", 1);
					++b->getGrade();  // Should throw an exception because grade cannot exceed 150
					break;

				case 5: // Valid grade: increasing grade significantly
					b = new Bureaucrat("b", 75);
					b->getGrade() += 100; // Should throw an exception because grade would go above 150
					break;

				case 6: // Valid grade: decreasing grade significantly
					b = new Bureaucrat("b", 75);
					b->getGrade() -= 100; // Should throw an exception because grade would go below 1
					break;

				case 7: // Valid grade: increasing grade significantly
					b = new Bureaucrat("b", 75);
					b->getGrade() += -100; // Should throw an exception because grade would go below 1
					break;
				
				case 8: // Valid grade: increasing grade significantly
					b = new Bureaucrat("b", 75);
					b->getGrade() -= -100; // Should throw an exception because grade would go above 150
					break;

				case 9: // Constructing with a valid grade but modifying it directly
					b = new Bureaucrat("b", 75);
					b->getGrade() = 151;  // Invalid grade directly assigned, should trigger an exception
					break;

				case 10: // Constructing with a valid grade but modifying it directly
					b = new Bureaucrat("b", 75);
					b->getGrade() = -1;  // Invalid grade directly assigned, should trigger an exception
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
	}
	it = 0;
	try
	{
		++it; b = new Bureaucrat("b", 75);		(b->getGradeToInt() == 75) ? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; ++b->getGrade(); 					(b->getGradeToInt() == 74) ? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; --b->getGrade();					(b->getGradeToInt() == 75) ? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; b->getGrade() += 10;				(b->getGradeToInt() == 65) ? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; b->getGrade() -= 10;				(b->getGradeToInt() == 75) ? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; b->getGrade() = 10;				(b->getGradeToInt() == 10) ? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		
		++it; (b->getGrade() == Bureaucrat(*b).getGrade())		? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; (b->getGrade() == Bureaucrat("b", 10).getGrade())	? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; (b->getGrade() >= Bureaucrat("b", 10).getGrade())	? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; (b->getGrade() <= Bureaucrat("b", 10).getGrade())	? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; (b->getGrade() < Bureaucrat("b", 9).getGrade())		? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		++it; (b->getGrade() > Bureaucrat("b", 11).getGrade())	? os << "Sucess: " << it << std::endl : os << "Failure: " << it << std::endl;
		std::cout << os.str();
	}
	catch (const std::exception& e)
	{
		std::cout << os.str() << std::endl;
		std::cout << "Failure " << it << " catched: " << e.what() << std::endl;
	}
	
	(void) b;
}