cmake_minimum_required(VERSION 3.21)

project(
        rtmini
        VERSION 0.0.1
        DESCRIPTION "Ray Tracing Mini-books"
        LANGUAGES CXX
)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH "$(Catch2_SOURCE_DIR)/contrib")

add_executable(rtmini ch02/output_an_image.cxx src/color.cxx)
target_include_directories(rtmini PRIVATE include)
target_compile_features(rtmini PRIVATE cxx_std_23)

if (MSVC)
    target_compile_options(rtmini INTERFACE /W4 /WX /sd1)
else()
    target_compile_options(rtmini INTERFACE -Werror -Wall -Wextra -pedantic)
endif()

add_executable(tests tests/main.cxx)
target_link_libraries(tests PRIVATE Catch2::Catch2)
target_include_directories(tests PRIVATE $(Catch2_INCLUDE_DIRS} tests))
target_compile_features(tests PRIVATE cxx_std_23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (MSVC)
        target_compile_options(tests PRIVATE /Od /MDd)
    else()
        target_compile_options(tests PRIVATE -O0 -g)
    endif()
else()
    if (MSVC)
        target_compile_options(tests PRIVATE /O2 /MD)
    else()
        target_compile_options(tests PRIVATE -O3)
    endif()
endif()

include(CTest)
include(Catch)
catch_discover_tests(tests)
