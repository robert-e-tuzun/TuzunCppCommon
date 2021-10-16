# MathCommon/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

# --------------------------------------------------------
#
# Set the project name and version.
#

project(MathCommon VERSION 6.0 LANGUAGES CXX)

# --------------------------------------------------------
#
# Find libraries.
#

find_package(UtilCommon
             PATHS ${CMAKE_INSTALL_PREFIX}/lib/cmake/UtilCommon
            )

# --------------------------------------------------------
#
# Include third party libraries.
#

find_package(Boost REQUIRED)

# --------------------------------------------------------
#
# Add subdirectories in order of dependence (lower may depend on upper, but
# not vice versa).
#

enable_testing()

#add_subdirectory(MathMisc)
add_subdirectory(Combin)
#add_subdirectory(GraphTheory)

add_subdirectory(test)

