cmake_minimum_required(VERSION 2.6)

project("cppapi")
set(CPPAPI_VERSION 1)
set(CPPAPI_VERSION_MINOR 0)
set(CPPAPI_VERSION_PATCH 0)
set(CPPAPI_AUTHOR "kmc7468")

file(GLOB SOURCES "./src/" "*.cc")
add_library(cppapi SOURCES)

add_definitions(-std=c++1z -Wall -fmodules)