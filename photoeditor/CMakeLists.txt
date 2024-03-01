cmake_minimum_required(VERSION 3.28)

qt_add_executable(PhotoEditorApp)

set(QML
    main.qml
    qml/AppMenuBar.qml
)

set(SOURCES
    main.cpp
    editorstate.cpp
)

set(HEADERS
    editorstate.h
)

set(IMAGES
    img/cm_mesh.png
)

qt_add_qml_module(PhotoEditorApp
    URI photoeditor
    VERSION 1.0
    NO_RESOURCE_TARGET_PATH
    QML_FILES
        ${QML}
    SOURCES
        ${SOURCES}
        ${HEADERS}
    RESOURCES
        ${IMAGES}
)

target_link_libraries(PhotoEditorApp PRIVATE
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets # used by Qt.labs.platform QML module
    PhotoEditorTools
)
