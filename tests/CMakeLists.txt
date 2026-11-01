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

# Compile-time check that the struct layouts computed by the code generator
# (and documented in MoMTemplate.h) match what this compiler produces.
if(Python3_Interpreter_FOUND)
    set(RTGT_LAYOUT_CHECK ${CMAKE_CURRENT_BINARY_DIR}/layout_check.cpp)
    add_custom_command(
        OUTPUT ${RTGT_LAYOUT_CHECK}
        COMMAND Python3::Interpreter ${PROJECT_SOURCE_DIR}/scripts/generate_code.py
                --layout-check ${RTGT_LAYOUT_CHECK}
        DEPENDS ${PROJECT_SOURCE_DIR}/scripts/generate_code.py
                ${PROJECT_SOURCE_DIR}/MoMModel/MoMTemplate.h
                ${PROJECT_SOURCE_DIR}/Platform/MoMCommon.h
        COMMENT "Generating struct layout checks"
        VERBATIM)
    target_sources(rtgt_tests PRIVATE ${RTGT_LAYOUT_CHECK})
endif()

# Tests in the "live" suite need a running game in DOSBox; they are skipped
# by default. Run them by hand with: rtgt_tests --no-skip
add_test(NAME rtgt_tests COMMAND rtgt_tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# The user interface, run headless with the Dear ImGui "null" backends
if(TARGET rtgt_ui)
    add_executable(rtgt_ui_tests
        test_main.cpp
        test_rtgt_ui.cpp
        ${RTGT_IMGUI_SOURCE_DIR}/backends/imgui_impl_null.cpp)
    target_include_directories(rtgt_ui_tests PRIVATE ${PROJECT_SOURCE_DIR}/doctest-2.4.11)
    target_compile_definitions(rtgt_ui_tests PRIVATE RTGT_TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data/")
    target_link_libraries(rtgt_ui_tests PRIVATE rtgt_ui)
    add_test(NAME rtgt_ui_tests COMMAND rtgt_ui_tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()
