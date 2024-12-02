cmake_minimum_required(VERSION 3.10)
project(relogio VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(relogio main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
find_package(date CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE date::date date::date-tz)