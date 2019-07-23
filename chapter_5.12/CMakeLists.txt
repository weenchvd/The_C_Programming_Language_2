# CMakeList.txt : CMake project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Chapter_5.12")

set (CMAKE_C_STANDARD 99)
set (FILE_NAME chapter_5.12_exercise_5.18_dcl)
set (SOURCE_C_LIST ${FILE_NAME}.c gettoken.c getch.c)
#set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)
set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/..)

# Add source to this project's executable.
add_executable (${FILE_NAME} ${SOURCE_C_LIST})
add_executable (chapter_5.12_exercise_5.19_undcl chapter_5.12_exercise_5.19_undcl.c gettoken.c getch.c)

# TODO: Add tests and install targets if needed.
install (TARGETS ${FILE_NAME} DESTINATION Build)
install (TARGETS chapter_5.12_exercise_5.19_undcl DESTINATION Build)
