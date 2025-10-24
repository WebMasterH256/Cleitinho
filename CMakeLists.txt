cmake_minimum_required(VERSION 4.0)
project(Cleitinho C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Cleitinho
        main.c
        Clientes/Cliente.h
        Ordens/Ordem.h
        Pecas/Peca.h
        util/util.h
        util/util.c
        Clientes/Cliente.c
        Pecas/Peca.c
)
