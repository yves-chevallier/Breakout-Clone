cmake_minimum_required(VERSION 2.8...3.6)
project(breakout)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

file(GLOB SOURCES src/*.cpp)

add_executable(breakout ${SOURCES})

target_compile_features(breakout PRIVATE cxx_std_17)

target_compile_options(breakout
                       PRIVATE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
                       $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>)

target_compile_definitions(breakout
                           PRIVATE
                           $<$<CONFIG:Debug>:DEBUG>)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(breakout PRIVATE sfml-graphics)