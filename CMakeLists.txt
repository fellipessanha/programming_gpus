cmake_minimum_required(VERSION 3.19.2)

# set the project name
project(FourierTransform)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # asserts compile_commands.json gets generated

# find_package(Curses REQUIRED)
include_directories(
  include
)

# add the executable
add_executable(${PROJECT_NAME} src/main.cc)
target_link_libraries(${PROJECT_NAME})