cmake_minimum_required(VERSION 3.15)

project(lab05 LANGUAGES CXX)

# Configuración del estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente compartidos por ambos ejecutables
set(SHARED_SRC
    ${PROJECT_SOURCE_DIR}/src/graph.cpp
)

add_executable(ejer5
    ${SHARED_SRC}
    ${PROJECT_SOURCE_DIR}/src/graph_dfs.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Ejecutable para DFS Iterativa
add_executable(ejer7
    ${SHARED_SRC}
    ${PROJECT_SOURCE_DIR}/src/graph_dfs_itera.cpp
    ${PROJECT_SOURCE_DIR}/src/main1.cpp
)


