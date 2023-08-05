cmake_minimum_required(VERSION 3.25.1)

project(
    blackjack
    VERSION 0.0
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Werror")

file(GLOB src_files CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} ${src_files})
target_include_directories(${PROJECT_NAME} PUBLIC include)


