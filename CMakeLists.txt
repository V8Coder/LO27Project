cmake_minimum_required(VERSION 2.8.4)
project(LO27Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(LO27Project COMMAND make -C ${/home/g33k/Documents/Cours/UTBM/Cour/LO27/Project/LO27Project}
        CLION_EXE_DIR=${/home/g33k/Documents/Cours/UTBM/Cour/LO27/Project/LO27Project})
