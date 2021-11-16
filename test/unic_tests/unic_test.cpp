#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <string_view>

#include <unic/unic.hpp>

struct StartsWith
{
    constexpr auto operator()(std::string_view starter) const
    {
        return [starter](const auto& str) { return str.starts_with(starter); };
    }
};
StartsWith starts_with{};

using unic::operator->*;



TEST_CASE("Example")
{
	constexpr std::string_view str = "lola";
	constexpr bool b = str->*starts_with("Lolo");
	static_assert(b == false);
	static_assert(str->*starts_with("lol"));
}
