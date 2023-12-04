cmake_minimum_required(VERSION 3.10)

project(money)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS ON)

# set(DCMAKE_CXX_FLAGS -Werror -Wall -Wextra)


# testing
enable_testing()

add_executable(test_case test_case.cpp
    src/money.cpp
    src/bank.cpp
    src/sum.cpp
    # src/expression.cpp
)

add_test(NAME money_test_cases COMMAND test_case)



# production
# add_executable(${PROJECT_NAME}
#     main.cpp
# )
