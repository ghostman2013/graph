cmake_minimum_required(VERSION 3.6)
project(task_01)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(SRC
    "i_graph.hpp" "i_graph.cpp"
    "arc_graph.hpp" "arc_graph.cpp"
    "matrix_graph.hpp" "matrix_graph.cpp")
#Link runTests with test.cpp and the GTest and pthread library
add_executable(runTests "test.cpp" ${SRC})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_executable(${PROJECT_NAME} "main.cpp" ${SRC})
