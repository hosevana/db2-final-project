cmake_minimum_required(VERSION 3.16)

project(db2_cpp_crud LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(mongocxx CONFIG REQUIRED)

add_executable(main_cplusplus
    main_cplusplus.cpp
    database.cpp
)
target_link_libraries(main_cplusplus PRIVATE mongo::mongocxx_static)

add_executable(test_cpp test_cpp.cpp)
target_link_libraries(test_cpp PRIVATE mongo::mongocxx_static)