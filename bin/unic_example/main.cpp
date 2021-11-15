#include <iostream>

#include <unic/unic.hpp>

int main()
{
	auto i = unic::add(9, 4);
	std::cout << "The result is: " << i << std::endl;
}