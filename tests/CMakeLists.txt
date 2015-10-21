set(TEST_NAMES
    bead_type_test vector3d_test molecule_test cgspace_test model_test
    force_field_test
    )

set(GTEST_ROOT $ENV{HOME}/local/gtest)
include_directories(
    ${GTEST_ROOT}/include
    ../src
    )
set(test_libraries
    pthread
    ${GTEST_ROOT}/libgtest.a
    ${GTEST_ROOT}/libgtest_main.a)

foreach(TEST_NAME ${TEST_NAMES})
    add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} mylipid ${test_libraries})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach(TEST_NAME)

