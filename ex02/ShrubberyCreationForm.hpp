#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include FORM_INCLUDE

#define CONCRETE_FORM ShrubberyCreationForm

class CONCRETE_FORM : public AForm
{
	public:
		CONCRETE_FORM( void );
		CONCRETE_FORM( std::string );
		CONCRETE_FORM( const CONCRETE_FORM& );
		virtual ~CONCRETE_FORM();

		CONCRETE_FORM& operator=(const CONCRETE_FORM& );

		void beExecuted( void ) const;
};

std::ostream& operator<<(std::ostream& os, const FORM& f);

#undef CONCRETE_FORM
#endif