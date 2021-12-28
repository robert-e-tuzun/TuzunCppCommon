# KnotCommon/test/unit/KnotGraph/KnotAdmitChecker/CMakeLists.txt

project(KnotAdmitChecker VERSION 1.0 LANGUAGES CXX)

find_package(Boost)

set(EXEC_NAME testKnotAdmitChecker)

add_executable(${EXEC_NAME}
               src/testKnotAdmitChecker.cpp
              )

target_link_libraries(${EXEC_NAME}
                      UtilCommon
                      KnotGraph
                      InputOutput
                      ${BOOST}
                     )

target_include_directories(${EXEC_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/InputOutput/include
    PRIVATE ${CMAKE_SOURCE_DIR}/KnotGraph/include
)

# Install executable in CI testing directory.

set(PATH_FROM_ROOT_TO_DIR DummyValue)
FindPathFromRootToDir(${CMAKE_CURRENT_SOURCE_DIR} PATH_FROM_ROOT_TO_DIR)
set(TEST_EXECUTABLE_DIR
    ${CI_TEST_ROOT}/${CMAKE_PROJECT_NAME}${PATH_FROM_ROOT_TO_DIR})

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION ${TEST_EXECUTABLE_DIR})

