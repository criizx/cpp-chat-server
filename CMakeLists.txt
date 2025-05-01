cmake_minimum_required(VERSION 3.16)
project(ChatServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(chat_server
    src/main.cpp
)

target_include_directories(chat_server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(chat_server PRIVATE ${Boost_LIBRARIES})
