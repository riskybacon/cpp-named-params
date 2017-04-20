cmake_minimum_required(VERSION 2.8)

enable_testing()

set(TESTS
    function
    constructor
    template_named_values
)

foreach(TEST_NAME ${TESTS})
    set(SOURCE_FILES ${TEST_NAME}.cpp)
    proj_add_executable(${TEST_NAME} SRC ${SOURCE_FILES})
    add_test(NAME ${TEST_NAME} COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}
    )
endforeach()
