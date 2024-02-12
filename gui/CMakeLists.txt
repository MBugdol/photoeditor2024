cmake_minimum_required(VERSION 3.28)

qt6_add_qml_module(PhotoEditorGui
    URI editor.gui
    VERSION 1.0
    RESOURCE_PREFIX / # this is a module internal to this project; no need for special prefix
    QML_FILES
        main.qml
        AppMenuBar.qml
    SOURCES
        editorstate.h
        editorstate.cpp
)
