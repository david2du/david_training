set(BINARY ${CMAKE_PROJECT_NAME}_tst)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
message("build with debug mode")
message("${TEST_SOURCES}")
include_directories(
        "E:/8A_libs/googletest-distribution/include"
        "${PROJECT_SOURCE_DIR}/src"
        )
link_directories(
    "E:/8A_libs/googletest-distribution/lib"
)
        
set(SOURCES ${TEST_SOURCES})
add_executable(${BINARY} ${TEST_SOURCES})
#add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC   gmock_maind gmockd gtestd)


