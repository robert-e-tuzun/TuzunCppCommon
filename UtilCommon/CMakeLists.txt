# UtilCommon/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Set the project name and version.
project(UtilCommon VERSION 1.0.0 LANGUAGES CXX)

# Enable the finding of InstallExportLib.cmake by adding the directory it's
# in to CMAKE_MODULE_PATH.

list(APPEND CMAKE_MODULE_PATH ${MY_MODULES})
include(GNUInstallDirs)
include(InstallExportLib)
include(FindPathFromRootToDir)

# Include Boost.

find_package(Boost REQUIRED)

# Set up the library.

set(SOURCE_FILES
    src/Blackboard.cpp
   )

set(HEADER_FILES
    include/UtilCommon/Blackboard.h
    include/UtilCommon/CppDatatypes.h
    include/UtilCommon/sortByRank.h
   )

add_library(UtilCommon STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(UtilCommon
    PUBLIC    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(UtilCommon ${Boost_LIBRARIES})

# Install and export the library.

InstallExportLib(UtilCommon "${CMAKE_INSTALL_LIBDIR}"
                 "${CMAKE_INSTALL_BINDIR}"
                 "${CMAKE_INSTALL_INCLUDEDIR}")

# Add testing related directory.

add_subdirectory(test)
