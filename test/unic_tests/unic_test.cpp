#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <string_view>
#include <array>
#include <algorithm>

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


TEST_CASE("With a proxy with an algorithm from the std")
{
	constexpr auto find = UNIX_GENERATE_PROXY(std::ranges::find);
	constexpr std::array a = { 1, 2, 3, 4, 5 };

	// Not constexpr yet because std::ranges::find is not consxtpr yet with gcc on my dev env
	auto it = a->*find(3);
	REQUIRE(it != a.end());
	CHECK(*it == 3);
}