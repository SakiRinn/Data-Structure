cmake_minimum_required(VERSION 3.0.0)
project(Data_Structure)
include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(app_header)
add_subdirectory(app)

aux_source_directory(src SRC_DIR)
aux_source_directory(app APP_DIR)

include_directories(include)
include_directories(app_header)

add_executable(object main.c ${SRC_DIR} ${APP_DIR})