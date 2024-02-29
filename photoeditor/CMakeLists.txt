cmake_minimum_required(VERSION 3.28)

qt_add_executable(PhotoEditorApp)
target_sources(PhotoEditorApp PRIVATE main.cpp)

qt_add_qml_module(PhotoEditorApp
    URI photoeditor
    VERSION 1.0
    RESOURCE_PREFIX / # this is a module internal to this project; no need for special prefix
    QML_FILES
        main.qml
        AppMenuBar.qml
    SOURCES
        editorstate.h
        editorstate.cpp
    RESOURCES
        img/cm_mesh.png
)

target_link_libraries(PhotoEditorApp PRIVATE
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets # used by Qt.labs.platform QML module
    PhotoEditorTools
)
