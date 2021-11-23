#include <iostream>
#include <vector>
#include <algorithm>

#include <unic/unic.hpp>


int main()
{
	using unic::operator->*;
	constexpr auto find = UNIC_GENERATE_PROXY(std::ranges::find);
	std::vector ints = { 1, 2, 3, 4, 5 };

	auto it = ints->*find(3);
	if (it != ints.cend())
		std::cout << "Found : " << *it << std::endl;
	else
		std::cout << "Not found :'(" << std::endl;
}