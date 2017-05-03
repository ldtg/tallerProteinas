cmake_minimum_required(VERSION 3.6)
project(tp1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -pedantic -pedantic-errors -O3 -ggdb -DDEBUG -fno-inline")
set(SOURCE_FILES main.c codon.h codon.c codigo_genetico.c codigo_genetico.h socket.c socket.h servidor.c servidor.h cliente.c cliente.h aminoacido.c aminoacido.h)
add_executable(tp1 ${SOURCE_FILES})