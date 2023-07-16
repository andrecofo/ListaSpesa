cmake_minimum_required(VERSION 3.25)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 23)

add_executable(ListaSpesa main.cpp Observer.h Subject.h Products.h List.h User.h)
