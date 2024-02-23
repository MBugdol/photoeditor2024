cmake_minimum_required(VERSION 3.28)

set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(PhotoEditorApp PRIVATE ${SOURCEDIR})

target_sources(PhotoEditorApp PRIVATE
    ${SOURCEDIR}/main.cpp
    ${SOURCEDIR}/editorapplication.cpp
    ${SOURCEDIR}/editorapplication.h
    ${SOURCEDIR}/backend.cpp
    ${SOURCEDIR}/backend.h
    ${SOURCEDIR}/project/project.cpp
    ${SOURCEDIR}/project/project.h
    ${SOURCEDIR}/project/projectimageprovider.cpp
    ${SOURCEDIR}/project/projectimageprovider.h
)
