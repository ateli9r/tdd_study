cmake_minimum_required(VERSION 3.10)

project(money)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS ON)



# testing
enable_testing()

add_executable(test_case test_case.cpp
    src/dollar.cpp src/franc.cpp src/money.cpp
)

add_test(NAME test_case COMMAND test_case)



# production
# add_executable(${PROJECT_NAME}
#     main.cpp
# )
