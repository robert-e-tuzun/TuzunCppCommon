# UtilCommon/test/unit/Blackboard/CMakeLists.txt

project(testBlackboard VERSION 1.0 LANGUAGES CXX)

set(BOOST_ROOT $ENV{BOOST_ROOT})

# Create executable.

set(EXEC_NAME testBlackboard)

add_executable(${EXEC_NAME}
               src/testBlackboard.cpp
               src/A.cpp
               src/BlackboardTester.cpp
              )

target_link_libraries(${EXEC_NAME}
                      UtilCommon
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
