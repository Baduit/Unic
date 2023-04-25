add_library(unic INTERFACE)
target_compile_features(unic INTERFACE cxx_std_20)
target_include_directories(unic INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
	$<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)