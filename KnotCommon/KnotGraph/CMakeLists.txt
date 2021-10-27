# KnotCommon/KnotCommon/CMakeLists.txt

# Set the project name and version.
project(KnotCommon VERSION 1.0 LANGUAGES CXX)

set(SOURCE_FILES
    src/KnotAdmitChecker.cpp
   )

add_library(KnotCommon ${SOURCE_FILES})

target_include_directories(KnotCommon
    PRIVATE include
)

target_link_libraries(KnotCommon UtilCommon)

# Install and export the library.

InstallExportLib(KnotCommon
                 "${CMAKE_INSTALL_LIBDIR}"
                 "${CMAKE_INSTALL_BINDIR}"
                 "${CMAKE_INSTALL_INCLUDEDIR}"
                )

