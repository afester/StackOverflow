cmake_minimum_required (VERSION 2.6)
project (conflict)
add_executable(conflict foo/conflict.cpp bar/conflict.cpp main.cpp)
include_directories("/usr/include/qt4/QtGui" "/usr/include/qt4")

