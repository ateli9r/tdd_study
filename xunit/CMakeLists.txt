cmake_minimum_required(VERSON 3.10)
project(xunit)

find_package(Python3 COMPONENTS Interpreter Development)


message("Python3_ROOT_DIR: $ENV{Python3_ROOT_DIR}")
message("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")

# enable_testing()

