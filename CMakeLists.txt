cmake_minimum_required(VERSION 3.26)
project(testinglibr C)
set(CMAKE_C_STANDARD 11)
add_executable(testinglibr main.c)
# Acknowledgment : https://limeoats.com/clion-and-cmake
# create include and lib folders and add all the .h files in the include folder and all the .a files in the lib folder
# copy these folders to the project folder so that following is your project's directory structure:
#    myproject/
#       |-CMakeLists.txt
#       |-source files
#       |-include/
#           |- all header files (.h files)
#       |-lib/
#           |- all libraries (.a files)
# following must be added to the CMakeLists.txt file that CLION builds for the project
# it assumes mohitilities.h and lib.h are two header files and mohit.a and libmylib.a are the two static libraries already
# built and available.
set(FIND_PATHS ${CMAKE_CURRENT_LIST_DIR})  # Look for the resources in the current project folder
find_path(PATH_INCLUDE_DIR mohitilities.h lib.h PATH_SUFFIXES include ) # list down all the header files here
# The location of the include folder (and thus the header files)
# find_path uses the paths we defined above as places to look
# Saves the location of the header files in a variable called MY_INCLUDE_DIR
find_path(MY_INCLUDE_DIR mohitilities.h  lib.h # The variable to store the path in and the names of all the header files
        PATH_SUFFIXES include               # The folder name containing the header files
        PATHS ${FIND_PATHS})       # Where to look (defined above)
# The location of the lib folder (and thus the .a file). Each library included require a separate find_library( ...) statement
# find_library uses the paths we defined above as places to look
# Saves the location of the .a file in a variable called MY_LIBRARY
find_library(MY_LIBRARY1               # The variable to store where it finds the first .a file
        NAMES libmylib                # The name of the first .a file (without the extension and without the 'lib')
        PATH_SUFFIXES lib                   # The folder the .a file is in
        PATHS ${FIND_PATHS})               # Where to look (defined above)
find_library(MY_LIBRARY2               # The variable to store where it finds the next .a file
        NAMES libmohit                # The name of the next .a file (without the extension and without the 'lib')
        PATH_SUFFIXES lib                   # The folder the .a file is in
        PATHS ${FIND_PATHS})               # Where to look (defined above)
include_directories(${MY_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${MY_LIBRARY1} ${MY_LIBRARY2})
