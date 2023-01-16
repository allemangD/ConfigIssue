cmake_minimum_required(VERSION 3.24)
project(ConfigIssue)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConfigIssue main.cpp)

enable_testing()
add_test(NAME DemoConfigIssue COMMAND ConfigIssue)
set_tests_properties(
        DemoConfigIssue PROPERTIES
        PASS_REGULAR_EXPRESSION "SAMPLE: '.+'"
)
