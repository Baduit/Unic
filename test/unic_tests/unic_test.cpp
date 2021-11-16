#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <string_view>

#include <unic/unic.hpp>

using unic::operator->*;



TEST_CASE("operator->* alone")
{
	struct StartsWith
	{
		constexpr auto operator()(std::string_view starter) const
		{
			return [starter](const auto& str) { return str.starts_with(starter); };
		}
	};
	StartsWith starts_with{};

	constexpr std::string_view str = "lola";
	constexpr bool b = str->*starts_with("Lolo");
	static_assert(b == false);
	static_assert(str->*starts_with("lol"));
}

constexpr bool my_starts_with(std::string_view str, std::string_view maybe_substr)
{
	return str.starts_with(maybe_substr);
}

TEST_CASE("With a proxy for a function")
{
	constexpr auto starts_with = UNIX_GENERATE_PROXY(my_starts_with);
	constexpr std::string_view str = "lola";
	{
		constexpr bool b = str->*starts_with("lol");
		static_assert(b);
	}
	{
		constexpr bool b = str->*starts_with("loli");
		static_assert(!b);
	}
}