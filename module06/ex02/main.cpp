#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <time.h>


Base* generate(void)
{
	srand(time(NULL));
	int	choice = rand() % 3;
	Base* base;
	switch (choice)
	{
	case 0:
		std::cout << "type A generated" << std::endl;
		base = new A;
		break;
	case 1:
		std::cout << "type B generated" << std::endl;
		base = new B;
		break;
	case 2:
		std::cout << "type C generated" << std::endl;
		base = new C;
		break;
	}
	return base;
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "type A detected" << std::endl;
	if (b)
		std::cout << "type B detected" << std::endl;
	if (c)
		std::cout << "type C detected" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "type A detected" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "it wasn't a A type" << '\n';
	}
	try
	{
		B a = dynamic_cast<B&>(p);
		(void)a;
		std::cout << "type B detected" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "it wasn't a B type" << '\n';
	}
	try
	{
		C a = dynamic_cast<C&>(p);
		(void)a;
		std::cout << "type C detected" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "it wasn't a C type" << '\n';
	}
}

int main(void)
{
	Base* b = generate();
	identify(b);
	identify(*b);
	delete (b);
	return 0;
}