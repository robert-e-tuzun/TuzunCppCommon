# MathCommon/test/unit/Combin/Lexicographic/CMakeLists.txt

project(Lexicographic VERSION 1.0 LANGUAGES CXX)

find_package(Boost)

set(EXEC_NAME testLexicographic)

add_executable(${EXEC_NAME}
               src/testLexicographic.cpp
              )

target_link_libraries(${EXEC_NAME}
                      UtilCommon
                      Combin
                      ${BOOST}
                     )

target_include_directories(${EXEC_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

# Install executable in CI testing directory.

set(PATH_FROM_ROOT_TO_DIR DummyValue)
FindPathFromRootToDir(${CMAKE_CURRENT_SOURCE_DIR} PATH_FROM_ROOT_TO_DIR)
set(TEST_EXECUTABLE_DIR
    ${CI_TEST_ROOT}/${CMAKE_PROJECT_NAME}${PATH_FROM_ROOT_TO_DIR})

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION ${TEST_EXECUTABLE_DIR})

