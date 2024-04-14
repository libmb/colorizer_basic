cmake_minimum_required(VERSION 3.12)

project(mb_colorizer_basic)

file(GLOB_RECURSE SOURCES "src/*.c" "src/**/*.c")

add_library(mb_colorizer_basic STATIC ${SOURCES})

target_include_directories(mb_colorizer_basic PUBLIC "include")

set_target_properties(mb_colorizer_basic PROPERTIES
    OUTPUT_NAME "mb_colorizer_basic"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

foreach(CONFIG_TYPE IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE_UPPER)
    set_target_properties(mb_colorizer_basic PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} "${CMAKE_SOURCE_DIR}"
        LIBRARY_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} "${CMAKE_SOURCE_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} "${CMAKE_SOURCE_DIR}"
    )
endforeach()
