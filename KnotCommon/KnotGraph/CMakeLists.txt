# KnotCommon/KnotGraph/CMakeLists.txt

# Set the project name and version.
project(KnotGraph VERSION 1.0 LANGUAGES CXX)

set(SOURCE_FILES
    src/KnotAdmitChecker.cpp
   )

add_library(KnotGraph ${SOURCE_FILES})

target_include_directories(KnotGraph
    PRIVATE include
)

target_link_libraries(KnotGraph InputOutput UtilCommon)

# Install and export the library.

InstallExportLib(KnotGraph
                 "${CMAKE_INSTALL_LIBDIR}"
                 "${CMAKE_INSTALL_BINDIR}"
                 "${CMAKE_INSTALL_INCLUDEDIR}"
                )

