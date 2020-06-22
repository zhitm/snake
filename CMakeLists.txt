cmake_minimum_required(VERSION 3.13)
project(SFMLApp)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/usr/lib/x86_64-linux-gnu")
set(SFML_LIBRARY_DIR "/usr/lib/x86_64-linux-gnu")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)


add_executable(SFMLApp main.cpp head.cpp head.h body.cpp body.h Apple.cpp Apple.h consts.h)
target_link_libraries (SFMLApp sfml-graphics sfml-window sfml-system)