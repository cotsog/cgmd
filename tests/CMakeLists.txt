set(TEST_NAMES
    vector3d_test space_test model_test space_io_test
    force_field_test langevin_stepper_test
    )

find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ../src
)
set(test_libraries
    pthread
    ${GTEST_BOTH_LIBRARIES}
)

foreach(TEST_NAME ${TEST_NAMES})
    add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} mylipid ${test_libraries})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach(TEST_NAME)

