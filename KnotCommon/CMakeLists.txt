# KnotCommon/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

# Set the project name and version.
project(KnotCommon VERSION 1.0.0 LANGUAGES CXX)

# Find packages used.
find_package(UtilCommon
             PATHS ${CMAKE_INSTALL_PREFIX}/lib/cmake/UtilCommon
            )
find_package(Combin
             PATHS ${CMAKE_INSTALL_PREFIX}/lib/cmake/Combin
            )
find_package(MathMisc
             PATHS ${CMAKE_INSTALL_PREFIX}/lib/cmake/MathMisc
            )
#find_package(GraphTheory
#             PATHS ${CMAKE_INSTALL_PREFIX}/lib/cmake/GraphTheory
#            )

# Enable the finding of InstallExportLib.cmake by adding the directory it's
# in to CMAKE_MODULE_PATH.

list(APPEND CMAKE_MODULE_PATH ${MY_MODULES})
include(GNUInstallDirs)
include(InstallExportLib)
include(FindPathFromRootToDir)

# Include Boost.

find_package(Boost REQUIRED)

# Add subdirectories for libraries.

add_subdirectory(InputOutput)
add_subdirectory(KnotGraph)
#add_subdirectory(ReducMoveFinder)
#add_subdirectory(DetInstrucGenerator)
#add_subdirectory(KBInstrucGenerator)

# Add subdirectory for testing.

add_subdirectory(test)

