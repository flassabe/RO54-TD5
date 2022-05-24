cmake_minimum_required(VERSION 3.0.2)
project(landuse)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(GDAL REQUIRED)
## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  GDAl_INCLUDE_DIR
)
# Crée des variables avec les fichiers à compiler
set(SRCS
    conversion.cpp
    landuse_computation.cpp
    landuse.cpp
    mesh.cpp
    readsources.cpp
    )
set(HEADERS
    conversion.h
    landuse_computation.h
    mesh.h
    readsources.h
    ) 
# Notre exécutable
add_executable(landuse ${SRCS} ${HEADERS})
## Specify libraries to link a library or executable target against
target_link_libraries(landuse gdal)
