# Unit tests for rtgt_core (doctest)

add_executable(rtgt_tests
    test_main.cpp
    test_momcombat.cpp
    test_momgamebase.cpp
    test_utility.cpp
)
target_include_directories(rtgt_tests PRIVATE ${PROJECT_SOURCE_DIR}/doctest-2.4.11)
target_compile_definitions(rtgt_tests PRIVATE
    RTGT_TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data/")
target_link_libraries(rtgt_tests PRIVATE rtgt_core)

# Tests in the "live" suite need a running game in DOSBox; they are skipped
# by default. Run them by hand with: rtgt_tests --no-skip
add_test(NAME rtgt_tests COMMAND rtgt_tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
