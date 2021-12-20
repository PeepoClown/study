cmake_minimum_required(VERSION 3.17)
project(fileProcessor)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(fileProcessor main.cpp MainWindow.cpp MainWindow.h FileProcessor.h FileProcessor.cpp Worker.h Worker.cpp WorkerModel.h WorkerModel.cpp InsertWindow.h InsertWindow.cpp DeleteWindow.h DeleteWindow.cpp UpdateWindow.h UpdateWindow.cpp)

target_link_libraries(fileProcessor Qt5::Core)
target_link_libraries(fileProcessor Qt5::Widgets)
