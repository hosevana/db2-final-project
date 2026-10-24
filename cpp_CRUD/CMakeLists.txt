cmake_minimum_required(VERSION 3.15)
project(mongo_test LANGUAGES CXX)

find_package(mongocxx REQUIRED)

add_executable(test_cpp test_cpp.cpp)
target_compile_features(test_cpp PRIVATE cxx_std_17)
target_link_libraries(test_cpp PRIVATE mongo::mongocxx_shared)