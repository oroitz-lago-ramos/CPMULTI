cmake_minimum_required(VERSION 3.10)
project(CPMULTI)

find_package(OpenCV REQUIRED)

add_executable(CPMULTI src/main.cpp
        src/Filters.cpp
        include/Filters.h
        src/ImageLoader.cpp
        include/ImageLoader.h
        src/Transformations.cpp
        include/Transformations.h
        include/PerformanceAnalyzer.h
        src/PerformanceAnalizer.cpp
        include/ThreadPool.h
        src/ThreadPool.cpp
        include/ImageSplitter.h
        src/ImageSplitter.cpp)
target_link_libraries(CPMULTI ${OpenCV_LIBS})