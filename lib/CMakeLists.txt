cmake_minimum_required(VERSION 3.28)

qt_add_library(PhotoEditorTools)

set(SOURCEDIR "${CMAKE_CURRENT_SOURCE_DIR}/photoeditortools")

target_include_directories(PhotoEditorTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(PhotoEditorTools PRIVATE
    ${SOURCEDIR}/editorapplication.cpp
    ${SOURCEDIR}/editorapplication.h
    ${SOURCEDIR}/backend.cpp
    ${SOURCEDIR}/backend.h
    ${SOURCEDIR}/appstate.cpp
    ${SOURCEDIR}/appstate.h
    ${SOURCEDIR}/project/project.cpp
    ${SOURCEDIR}/project/project.h
    ${SOURCEDIR}/project/projectimageprovider.cpp
    ${SOURCEDIR}/project/projectimageprovider.h
)

target_link_libraries(PhotoEditorTools PRIVATE
    Qt6::Gui
    Qt6::Quick
    Qt6::Widgets
)
