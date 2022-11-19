cmake_minimum_required(VERSION 3.21.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

list (APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
find_package(Qt5 REQUIRED)

project(malom CXX)

add_executable(${PROJECT_NAME} src/main.cpp src/board.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
#target_link_libraries(${PROJECT_NAME} qt::qt)
