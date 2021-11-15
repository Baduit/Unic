cmake_minimum_required(VERSION 3.12)

project(Example VERSION 0.1 DESCRIPTION "An example")

option(UNIC_EXAMPLE "UNIC_EXAMPLE" ON)
option(UNIC_TESTS "UNIC_TESTS" ON)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CPM)


add_subdirectory(lib)

if (UNIC_EXAMPLE)
	add_subdirectory(bin)
endif()

if (UNIC_TESTS)
	include(CTest)
	if(BUILD_TESTING)
		CPMAddPackage(
			NAME doctest
			GITHUB_REPOSITORY onqtam/doctest
			GIT_TAG 2.4.5
		)

		include(addTest)
		add_subdirectory(test)
	endif()
endif()