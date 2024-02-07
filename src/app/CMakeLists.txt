cmake_minimum_required(VERSION 3.28)

set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(PhotoEditorApp PRIVATE
    ${SOURCEDIR}/main.cpp
)
