cmake_minimum_required(VERSION 3.10.0)
project(CppDIY VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR})

add_library(main STATIC CppDIY.cpp)

set_target_properties(main PROPERTIES 
    OUTPUT_NAME "main"
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
)

add_executable(test_safequeue tests/test_safequeue.cpp)
# target_include_directories(test_safequeue PRIVATE ThreadPool/)

set_target_properties(test_safequeue PROPERTIES 
    OUTPUT_NAME "test_safequeue"
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

add_executable(test_threadpool tests/test_threadpool.cpp)
# target_include_directories(test_threadpool PRIVATE ThreadPool/)

set_target_properties(test_threadpool PROPERTIES 
    OUTPUT_NAME "test_threadpool"
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)