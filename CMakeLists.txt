cmake_minimum_required(VERSION 3.16)

project(labor1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#set(CMAKE_CXX_CLANG_TIDY 
#  clang-tidy;
#  -header-filter=.;
#  -checks=*;)



set(DEPENDENCY_LIBS state game player card logger)
set(TEST_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/State/state_test.cpp
)

add_subdirectory(lib)
find_package( Boost REQUIRED COMPONENTS unit_test_framework )

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Game
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Player
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Card
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/State
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Util
)
add_executable( run main.cpp )
target_link_libraries(run ${Boost_LIBRARIES} ${DEPENDENCY_LIBS})

add_executable(run_test ${TEST_SRCS})
target_link_libraries(run_test ${Boost_LIBRARIES} ${DEPENDENCY_LIBS})





