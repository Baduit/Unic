#pragma once

#include <concepts>
#include <memory>

std::unique_ptr<int> toto;

namespace unic
{

/*
struct StartsWith
{
    constexpr auto operator()(std::string_view starter) const
    {
        return [starter](const auto& str) { return str.starts_with(starter); };
    }
};
StartsWith starts_with{};
*/

#define UNIX_GENERATE_PROXY(function) []<typename... Args>(Args&&... args) { return [&]<typename T>(T&& t) { return function(std::forward<T>(t), std::forward<Args>(args)...); } ; }

template <typename T, std::invocable<T> Proxy>
constexpr auto operator->*(T&& t, Proxy&& p)
{
    return p(std::forward<T>(t));
}

} // namespace unic