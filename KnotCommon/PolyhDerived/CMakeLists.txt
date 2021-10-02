# KnotCommon/PolyhDerived/CMakeLists.txt

# Set the project name and version.
project(PolyhDerived VERSION 1.0 LANGUAGES CXX)

set(SOURCE_FILES
    src/PolyhDerivedManager.cpp
   )

add_library(PolyhDerived ${SOURCE_FILES})

target_include_directories(PolyhDerived
    PRIVATE include
)

target_link_libraries(PolyhDerived UtilCommon)

# Install and export the library.

InstallExportLib(PolyhDerived
                 "${CMAKE_INSTALL_LIBDIR}"
                 "${CMAKE_INSTALL_BINDIR}"
                 "${CMAKE_INSTALL_INCLUDEDIR}"
                )

