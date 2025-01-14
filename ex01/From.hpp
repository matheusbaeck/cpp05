#ifndef FORM_HPP
# define FORM_HPP

# include <sstream>
# include <string>
# include <stdexcept>
# include <iostream>


class Form
{
	private:
		const std::string _name;
		const int _requirement;
		bool _signed;
	
	public:
		bool beSigned(cont & Bureucrat);
};

#endif