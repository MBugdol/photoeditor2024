cmake_minimum_required(VERSION 3.28)

qt_add_library(PhotoEditorGui STATIC) # TODO: remove when QTBUG-122716 is resolved
qt_add_qml_module(PhotoEditorGui
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
