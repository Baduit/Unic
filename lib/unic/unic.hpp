#pragma once

#include <concepts>

namespace unic
{

template <typename T, std::invocable<T> Func>
constexpr auto operator->*(const T& str, Func&& f)
{
    return f(str);
}

} // namespace unic