cmake_minimum_required(VERSION 3.22)
project(SmartPointer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SmartPointer main.cpp SmartPtrBase.h SmartPtrUnique.h SmartPtrShared.h)
