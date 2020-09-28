cmake_minimum_required(VERSION 3.10)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

project(Bomberman)

set(${CXX_STANDARD} 17)
set(${CXX_STANDARD_REQUIRED} ON)

# Now simply link against gtest or gtest_main as needed. Eg

set(SRC_LIST
  src/Board.cpp
  src/Player.cpp
  src/Bomb.cpp
  src/Enemy.cpp 
  src/GameController.cpp
  src/Movable.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/inc)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_library(SRC ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp)
add_executable(${PROJECT_NAME}-ut tests/test.cpp)
target_link_libraries(${PROJECT_NAME}-ut gtest_main SRC)
target_link_libraries(${PROJECT_NAME} SRC)

enable_testing()
add_test(NAME bomberman_test COMMAND ${PROJECT_NAME}-ut)

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
