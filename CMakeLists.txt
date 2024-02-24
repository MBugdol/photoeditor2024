# CMake supports C++20 modules from version 3.28 onwards
cmake_minimum_required(VERSION 3.28)
project(PhotoEditor VERSION 2.0)

# Qt supports defining QML modules in CMake from Qt6.2 onwards
find_package(Qt6 6.2 COMPONENTS
    Quick
    Gui
    Widgets
    REQUIRED
)
qt_standard_project_setup()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

qt_add_executable(PhotoEditorApp)
add_subdirectory(src/app)
add_subdirectory(editor/gui)

target_link_libraries(PhotoEditorApp PRIVATE
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets # used by Qt.labs.platform QML module
    PhotoEditorGuiplugin # TODO: link to target instead of plugin when QTBUG-122716 is resolved
)

