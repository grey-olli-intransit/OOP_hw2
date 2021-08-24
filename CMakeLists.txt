CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
add_compile_options(-Wall -std=c++17)
PROJECT(homework2)
add_executable(hw2t1 src/hw2_task1.cpp)
add_executable(hw2t2 src/hw2_task2.cpp)
add_executable(blackjack src/blackjack.cpp)
target_include_directories(blackjack PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

