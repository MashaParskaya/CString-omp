cmake_minimum_required(VERSION 2.8)

project(CString)

set(CString_src main.cpp cstr.cpp autotest.cpp cstrHori.cpp cstrVert.cpp operator_plus.cpp)
set(CString_hdr cstr.hpp autotest.hpp cstrHori.hpp cstrVert.hpp operator_plus.hpp factory.hpp factoryHori.hpp factoryVert.hpp playgroung.hpp)

add_executable(${PROJECT_NAME} ${CString_src} ${CString_hdr})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 /std:c++14")
