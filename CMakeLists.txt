cmake_minimum_required(VERSION 3.31)
project(fkcv)

set(CMAKE_CXX_STANDARD 17)

add_executable(fkcv
        main.cpp
        injector.h
        replicator.h
        neutral.h
        replicator.cpp
        injector.cpp
        keygen.h
        keygen.cpp
        shells-cleaner.h
        shells-cleaner.cpp)
