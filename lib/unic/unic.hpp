#pragma once

#include <concepts>
#include <utility>

namespace unic
{

#define UNIX_GENERATE_PROXY(function)                                                                        \
	[]<typename... Args>(Args&&... args)                                                                    \
	{                                                                                                        \
		return [&args...]<typename T>(T&& t) { return function(std::forward<T>(t), std::forward<Args>(args)...); }; \
	}

template <typename T, std::invocable<T> Proxy>
constexpr auto operator->*(T&& t, Proxy&& p)
{
	return p(std::forward<T>(t));
}

} // namespace unic