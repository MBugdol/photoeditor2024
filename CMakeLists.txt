# CMake supports C++20 modules from version 3.28 onwards
cmake_minimum_required(VERSION 3.28)
project(PhotoEditor VERSION 2.0)

# Qt supports defining QML modules in CMake from Qt6.2 onwards
find_package(Qt6 6.4 COMPONENTS
    Quick
    Gui
    Widgets
    REQUIRED
)
qt_standard_project_setup()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)
add_subdirectory(photoeditor)
