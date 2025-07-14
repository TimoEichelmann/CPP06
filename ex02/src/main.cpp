#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <sys/time.h>


Base * generate(void)
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	srand(tp.tv_usec);
	Base *result;
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "instantiating A" << std::endl;
		result = new A;
	}
	else if (random == 1)
	{
		std::cout << "instantiating B" << std::endl;
		result = new B;
	}
	else if (random == 2)
	{
		std::cout << "instantiating C" << std::endl;
		result = new C;
	}
	return result;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "A" << std::endl;
	B* b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "B" << std::endl;
	C* c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
			}
			catch(std::exception &e)
			{
				std::cout << "no derived class" << std::endl;
				return ;
			}
			std::cout << "C" << std::endl;
			return ;
		}
		std::cout << "B" << std::endl;
		return ;
	}
	std::cout << "A" << std::endl;
	return ;
}

int main(void)
{
	Base *p;
	for(int i = 1; i < 6; i++)
	{
		std::cout << "starting test " << i << std::endl;
		p = generate();
		std::cout << "identify pointer: "; 
		identify(p);
		std::cout << "identify reference: ";
		identify(*p);
		delete p;
		std::cout << "test finished\n" << std::endl;
	}
}