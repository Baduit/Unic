# Unic
A library to simulate the "unified call syntax" in C++20 with a slightly different syntax.

The goal behind this library is to mess around with this concept, it is not intented to be used in a serious project.

# What is the "unified call syntax" ?
It is a way to call a free a similar way you would call a method.
More information here :
* https://en.wikipedia.org/wiki/Uniform_Function_Call_Syntax
* http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4174.pdf
* https://isocpp.org/files/papers/N4165.pdf

# What can I do with this library ?
```C++
// You can write something like this
str->*split(",");
// Instead of something like that
split(str, ",");
```

# How to use it ?
Here's an example :
```C++
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
```

# How to integrate it ?
It is a header only library, you can use it by:
* Use CMake and link against it : target_link_libraries(your_target Croissant) (It is defined as an INTERFACE library)
* Add in your project the single header Croissant.hpp which is in the folder single_header
* Add the lib directory in your path and include <unic/unic.hpp>

# How does it work ?
In this library there is only 2 small things :
* An overload of the operator ->*, on the left side it takes anything and on the right side it takes a callable which take the object on the left side as argument.
* A macro to create a proxy for a function so it can be used with the operator ->*, I will explain later why

Let's take the following code from the example:
```C++
using unic::operator->*; // 1
constexpr auto find = UNIC_GENERATE_PROXY(std::ranges::find); // 2
std::vector ints = { 1, 2, 3, 4, 5 };

ints->*find(3); // 3
```
First we make the overload of the operator->* avaible in the current scope.   
Second we generate the proxy for the function from the standard library __std::ranges::find__  

Now let's look at the last line see what is happening :
- The __operator()__ of find is called first because of the precedence of operator, it returns a lambda. This lambda has one argument which can be anything and when the lambda is called, it executes the wrapped function __std::ranges::find__, the first argument passed to __std::ranges::find__ is the argument of the lambda, the others are the one passed to the __operator()__ we just called, in our case __3__.
- The __operator->*__ is called, on the left side there is the __std::vector<int>__ : __ints__, on the right side a lambda, it will call the lambda with __ints__ as argument, this mean it is going to call __std::ranges::find__ with __ints__ and __3__ as argument.

To summarize,
```C++
ints->*find(3)
```
Is equivalent to this :
```C++
unic::operator->*(ints, find.operator()(3));
```
And this is equivalent to that:
```C++
unic::operator->*(ints, [](auto&& t) { return std::ranges::find(std::forward<T>(t), 3; };);
```
Which is also also the equivalent of this:
```C++
std::ranges::find(ints, 3);
```


