cmake_minimum_required(VERSION 3.10.0)
project(Ary VERSION 0.1.0 LANGUAGES C CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(BINARY ${CMAKE_PROJECT_NAME})

# Set the flags for both release and debug builds
if (MSVC)
    # Use /MT for release builds and /MTd for debug builds
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()


# Build

include(CPack)

include_directories(include)

file(GLOB SOURCE "src/*.cpp")
file(GLOB HEADERS "include/*.h")
file(GLOB TESTS "test/*.cpp")

add_executable(${BINARY} ${SOURCE})
add_library(${BINARY}_lib STATIC ${SOURCE})

target_include_directories(${BINARY}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${BINARY}_lib
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(lib/googletest)
add_subdirectory(lib/spdlog)
add_subdirectory(lib/argparse)
add_subdirectory(test)

target_link_libraries(${BINARY} PRIVATE spdlog::spdlog argparse)
target_link_libraries(${BINARY}_lib PRIVATE spdlog::spdlog argparse)

# Custom target to run cpplint before building
add_custom_target(run_cpplint
    COMMAND python ${CMAKE_SOURCE_DIR}/tools/cpplint/cpplint.py ${SOURCE} ${HEADERS} ${TESTS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running cpplint"
)
