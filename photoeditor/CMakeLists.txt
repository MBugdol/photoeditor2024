cmake_minimum_required(VERSION 3.28)

qt_add_executable(PhotoEditorApp)

set(QML
    main.qml
    qml/AppMenuBar.qml
)

set(SOURCES
    main.cpp
    src/editorstate.cpp
    src/editorstate.h
    src/appstate.cpp
    src/appstate.h
    src/backend.cpp
    src/backend.h
    src/editorapplication.cpp
    src/editorapplication.h
    src/project/project.cpp
    src/project/project.h
    src/project/projectimageprovider.cpp
    src/project/projectimageprovider.h
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
    RESOURCES
        ${IMAGES}
)

target_include_directories(PhotoEditorApp PUBLIC src)

target_link_libraries(PhotoEditorApp PRIVATE
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets # used by Qt.labs.platform QML module
)
