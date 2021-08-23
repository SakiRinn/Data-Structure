cmake_minimum_required(VERSION 3.0.0)
project(Data_Structure)
include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(include)
add_subdirectory(header)
add_subdirectory(lib)
add_subdirectory(src)

include_directories(include)
include_directories(header)
aux_source_directory(lib LIB_DIR)
aux_source_directory(src SRC_DIR)

add_executable(object main.cpp ${LIB_DIR} ${SRC_DIR})