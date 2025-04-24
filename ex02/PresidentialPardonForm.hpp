#ifndef PRESENTIALPARDONFORM_HPP
# define PRESENTIALPARDONFORM_HPP

#include FORM_INCLUDE

#define CONCRETE_FORM PresidentialPardonForm

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