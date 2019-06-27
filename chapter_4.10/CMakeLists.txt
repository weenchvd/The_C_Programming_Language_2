# CMakeList.txt : CMake project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Chapter_4.6")

set (CMAKE_C_STANDARD 99)
set (FILE_NAME chapter_4.10_exercise_4.12)
set (SOURCE_C_LIST ${FILE_NAME}.c)
#set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)
set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/..)

# Add source to this project's executable.
add_executable (${FILE_NAME} ${SOURCE_C_LIST})
add_executable (chapter_4.10_exercise_4.13 chapter_4.10_exercise_4.13.c)

# TODO: Add tests and install targets if needed.
install (TARGETS ${FILE_NAME} DESTINATION Build)
install (TARGETS chapter_4.10_exercise_4.13 DESTINATION Build)
