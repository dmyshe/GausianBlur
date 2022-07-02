cmake_minimum_required(VERSION 3.9)
 project(blur_homework)

 set (CMAKE_CXX_STANDARD 17)
 set(CONAN_DISABLE_CHECK_COMPILER TRUE)
 include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
 conan_basic_setup()
 if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.10")
 endif()

 add_library(GBlur
 SHARED
	Blur.cpp
	include/Blur.h
 )
 target_link_libraries(GBlur ${CONAN_LIBS})
 target_include_directories(GBlur PRIVATE ${CMAKE_BINARY_DIR}/../include)
if(WIN32)
 set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL$<$<CONFIG:Debug>:Debug>")
endif()
