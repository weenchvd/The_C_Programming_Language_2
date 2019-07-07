# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("The C Programming Language Part 2")

set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)

# Include sub-projects.
#add_subdirectory ("chapter_1.0" EXCLUDE_FROM_ALL)
add_subdirectory ("chapter_4.1")
add_subdirectory ("chapter_4.2")
add_subdirectory ("chapter_4.3")
add_subdirectory ("chapter_4.6")
add_subdirectory ("chapter_4.10")
add_subdirectory ("chapter_4.11")
add_subdirectory ("chapter_5.2")
add_subdirectory ("chapter_5.5")
add_subdirectory ("chapter_5.6")
add_subdirectory ("chapter_5.7")
