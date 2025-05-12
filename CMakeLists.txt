cmake_minimum_required(VERSION 3.26)
project(ChatServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Boost settings
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS system thread)

# Debug info
message(STATUS "Boost include dirs: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")

add_executable(chat_server src/main.cpp)

target_include_directories(chat_server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(chat_server PRIVATE ${Boost_LIBRARIES})
