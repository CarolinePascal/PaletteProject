cmake_minimum_required(VERSION 3.10)
SET(CMAKE_CXX_STANDARD 11)

#Set the project name
project(PaletteProject)

#Add the executable
set(SOURCES
    main.cpp
    KMeans.cpp
    Picture.cpp
    )

set(HEADERS
    KMeans.h
    Picture.h
    )

add_executable(PaletteProject ${SOURCES} ${HEADERS})

#Search packages
find_package(Threads REQUIRED)
target_link_libraries (PaletteProject Threads::Threads)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(PaletteProject ${OpenCV_LIBS})

#Executable generation

