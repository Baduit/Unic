add_library(unic INTERFACE)
target_compile_features(unic INTERFACE cxx_std_20)
target_include_directories(unic INTERFACE ${CMAKE_CURRENT_LIST_DIR})