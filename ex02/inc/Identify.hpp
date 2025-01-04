#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include <typeinfo>  // Required for std::bad_cast

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif
