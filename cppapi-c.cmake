cmake_minimum_required(VERSION 2.6)

project("cppapi-c")
set(CPPAPI_C_VERSION 1)
set(CPPAPI_C_VERSION_MINOR 0)
set(CPPAPI_C_VERSION_PATCH 0)
set(CPPAPI_C_AUTHOR "kmc7468")

file(GLOB SOURCES "./src/cppapi-c/" "*.cc")
file(GLOB SOURCES_USING_NAMESPACE "./src/cppapi-c/using_namespace/" "*.c")
add_library(cppapi-c SOURCES SOURCES_USING_NAMESPACE)

add_definitions(-std=c++1z -Wall -fmodules)