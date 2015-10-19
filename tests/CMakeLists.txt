set(GTEST_ROOT $ENV{HOME}/local/gtest)
include_directories(
    ${GTEST_ROOT}/include
    ../src
    )
add_executable(vector3d_test vector3d_test.cpp)
target_link_libraries(vector3d_test
    mylipid
    pthread
    ${GTEST_ROOT}/libgtest.a
    ${GTEST_ROOT}/libgtest_main.a)
add_test(NAME vector3d_test COMMAND vector3d_test)
