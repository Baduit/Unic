cmake_minimum_required(VERSION 3.12)

project(unic VERSION 0.1 DESCRIPTION "An experimental library" LANGUAGES CXX)

option(UNIC_EXAMPLE "UNIC_EXAMPLE" ON)
option(UNIC_TESTS "UNIC_TESTS" ON)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CPM)
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.6.0")


add_subdirectory(lib)

if (UNIC_EXAMPLE)
	add_subdirectory(bin)
endif()

if (UNIC_TESTS)
	include(CTest)
	if(BUILD_TESTING)
		CPMAddPackage("gh:onqtam/doctest@2.4.9")

		include(addTest)
		add_subdirectory(test)
	endif()
endif()

packageProject(
  NAME ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  NAMESPACE ${PROJECT_NAME}
  BINARY_DIR ${PROJECT_BINARY_DIR}
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/include
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
  VERSION_HEADER "${VERSION_HEADER_LOCATION}"
  COMPATIBILITY SameMajorVersion
)