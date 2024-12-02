cmake_minimum_required(VERSION 3.10)
project(PAOO_Tema3)

# Setăm standardul C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adăugăm directorul include/
include_directories(${PROJECT_SOURCE_DIR}/include)

# Adăugăm sursele
add_executable(PAOO_Tema3 
    src/main.cpp
    src/Matrix.cpp
)