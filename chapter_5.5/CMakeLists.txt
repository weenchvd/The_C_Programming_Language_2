# CMakeList.txt : CMake project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Chapter_5.5")

set (CMAKE_C_STANDARD 99)
set (FILE_NAME chapter_5.5_exercise_5.3)
set (SOURCE_C_LIST ${FILE_NAME}.c getstr.c)
#set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)
set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/..)

# Add source to this project's executable.
add_executable (${FILE_NAME} ${SOURCE_C_LIST})
add_executable (chapter_5.5_exercise_5.4 chapter_5.5_exercise_5.4.c getstr.c)
add_executable (chapter_5.5_exercise_5.5 chapter_5.5_exercise_5.5.c getstr.c)
add_executable (chapter_5.5_exercise_5.6_1 chapter_5.5_exercise_5.6_1.c getop.c getline.c pushpop.c)
add_executable (chapter_5.5_exercise_5.6_2 chapter_5.5_exercise_5.6_2.c)
add_executable (chapter_5.5_exercise_5.6_3 chapter_5.5_exercise_5.6_3.c getstr.c)

# TODO: Add tests and install targets if needed.
install (TARGETS ${FILE_NAME} DESTINATION Build)
install (TARGETS chapter_5.5_exercise_5.4 DESTINATION Build)
install (TARGETS chapter_5.5_exercise_5.5 DESTINATION Build)
install (TARGETS chapter_5.5_exercise_5.6_1 DESTINATION Build)
install (TARGETS chapter_5.5_exercise_5.6_2 DESTINATION Build)
install (TARGETS chapter_5.5_exercise_5.6_3 DESTINATION Build)
