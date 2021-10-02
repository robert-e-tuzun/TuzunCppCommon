# KnotCommon/InputOutput/CMakeLists.txt

# Set the project name and version.
project(InputOutput VERSION 1.0 LANGUAGES CXX)

set(SOURCE_FILES
    src/EmbedReader.cpp
    src/getNumPolyh.cpp
    src/PolyhedronReader.cpp
   )

add_library(InputOutput ${SOURCE_FILES})

target_include_directories(InputOutput
    PRIVATE include
)

target_link_libraries(InputOutput UtilCommon)

# Install and export the library.

InstallExportLib(InputOutput
                 "${CMAKE_INSTALL_LIBDIR}"
                 "${CMAKE_INSTALL_BINDIR}"
                 "${CMAKE_INSTALL_INCLUDEDIR}"
                )

