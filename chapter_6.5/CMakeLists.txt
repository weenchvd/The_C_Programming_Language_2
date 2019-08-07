# CMakeList.txt : CMake project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Chapter_6.5")

set (CMAKE_C_STANDARD 99)
set (FILE_NAME chapter_6.5_exercise_6.2)
set (SOURCE_C_LIST ${FILE_NAME}.c ftree.c alloc.c getword.c getch.c)
#set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)
set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/..)

# Add source to this project's executable.
add_executable (${FILE_NAME} ${SOURCE_C_LIST})
add_executable (chapter_6.5_exercise_6.3 chapter_6.5_exercise_6.3.c ftree2.c alloc2.c getword2.c getch.c)
add_executable (chapter_6.5_exercise_6.4 chapter_6.5_exercise_6.4.c ftree3.c alloc3.c getword3.c getch.c)

# TODO: Add tests and install targets if needed.
install (TARGETS ${FILE_NAME} DESTINATION Build)
install (TARGETS chapter_6.5_exercise_6.3 DESTINATION Build)
install (TARGETS chapter_6.5_exercise_6.4 DESTINATION Build)
