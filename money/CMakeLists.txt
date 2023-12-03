cmake_minimum_required(VERSION 3.10)

project(money)

add_executable(${PROJECT_NAME}
    main.cpp
)


# testing
enable_testing()

add_executable(test_case test_case.cpp

)

add_test(NAME test_case COMMAND test_case)
