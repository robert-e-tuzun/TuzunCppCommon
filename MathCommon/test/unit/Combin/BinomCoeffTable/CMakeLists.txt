# MathCommon/test/unit/Combin/BinomCoeffTable/CMakeLists.txt

project(BinomCoeffTable VERSION 1.0 LANGUAGES CXX)

find_package(Boost)

set(EXEC_NAME testBinomCoeffTable)

add_executable(testBinomCoeffTable
               src/testBinomCoeffTable.cpp
              )

target_link_libraries(testBinomCoeffTable
                      UtilCommon
                      Combin
                      ${BOOST}
                     )

target_include_directories(testBinomCoeffTable
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

# Install executable in CI testing directory.

set(PATH_FROM_ROOT_TO_DIR DummyValue)
FindPathFromRootToDir(${CMAKE_CURRENT_SOURCE_DIR} PATH_FROM_ROOT_TO_DIR)
set(TEST_EXECUTABLE_DIR
    ${CI_TEST_ROOT}/${CMAKE_PROJECT_NAME}${PATH_FROM_ROOT_TO_DIR})

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION ${TEST_EXECUTABLE_DIR})

