#Add executables
set(SRC
    main.cpp
    KMeans.cpp
    Picture.cpp
    )

add_executable(PaletteGenerator ${SRC})

#Search packages
#find_package(Threads REQUIRED)
#target_link_libraries (PaletteGenerator Threads::Threads)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(PaletteGenerator ${OpenCV_LIBS})