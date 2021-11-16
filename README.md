# Unic
A library to simulate the "unified call syntax" in C++20 with a slightly different syntax.

The goal behind this library is to mess around with this concept, it is not intented to be used in a serious project.

# What is the "unified call syntax" ?
It is a way to call a free a similar way you would call a method. With this library you can do something :
```C++
// todo ^^
```

See :
* https://en.wikipedia.org/wiki/Uniform_Function_Call_Syntax
* http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4174.pdf
* https://isocpp.org/files/papers/N4165.pdf

# How to use it ?
// todo

# How to integrate it ?
It is a header only library, you can use it by:
* Use CMake and link against it : target_link_libraries(your_target Croissant) (It is defined as an INTERFACE library)
* Add in your project the single header Croissant.hpp which is in the folder single_header
* Add the lib directory in your path and include <unic/unic.hpp>

# How does it work ?
// todo

# Todo
- Almost everything (yeazh I know it helps a lot)
