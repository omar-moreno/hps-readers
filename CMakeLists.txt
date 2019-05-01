# Add support for building in conda environment
if (DEFINED ENV{CONDA_PREFIX})
   set(CMAKE_PREFIX_PATH "$ENV{CONDA_PREFIX}")
   link_directories($ENV{CONDA_PREFIX}/lib)
endif()

# Check cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
include(InstallRequiredSystemLibraries)

# Set the project name and enable C/C++
project (hps_readers LANGUAGES CXX)

# C/C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-deprecated")

#####################################
# Find Rogue & Support Libraries
#####################################
if (DEFINED ENV{ROGUE_DIR})
   set(Rogue_DIR $ENV{ROGUE_DIR}/lib)
else()
   set(Rogue_DIR ${CMAKE_PREFIX_PATH}/lib)
endif()
find_package(Rogue)

#####################################
# Setup build
#####################################

# Include Rogue headers files
include_directories(${ROGUE_INCLUDE_DIRS})

# Add the reader subdirectory
include_directories("include/readers")
add_subdirectory("src/readers")

# Set output directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Compile each source
#file(GLOB APP_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
#foreach (srcFile ${APP_SOURCES})
#   get_filename_component(binName ${srcFile} NAME_WE)
#   add_executable(${binName} ${srcFile})
#   TARGET_LINK_LIBRARIES(${binName} LINK_PUBLIC ${ROGUE_LIBRARIES})
#endforeach ()
