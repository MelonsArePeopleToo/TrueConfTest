cmake_minimum_required(VERSION 3.15)
project(TrueConfTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(TrueConfTest main.cpp Utils.cpp Utils.h MapContainer.cpp MapContainer.h VectorContainer.cpp VectorContainer.h)

target_link_libraries(TrueConfTest pthread)