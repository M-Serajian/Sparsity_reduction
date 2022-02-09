# -----------------------------------------------------------------------------
# @brief  : Root cmake file.
# @author : Mohammadali Serajian
# @create : 02/09/2022
# @update : 02/09/2022
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Set the minimum CMake version, the project name and default build type.
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.1...3.18)

# Set the project name.
project(Sparsity_reduction)

# Set the default build type to Debug.
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
endif()

# Configure thirdparty
# ------------------------------------------------------------------------------
set(CMAKE_INSTALL_INCLUDEDIR "include") # This is an hack because include(GUIInstallDirs) doesn't work

add_subdirectory(thirdparty)

# -----------------------------------------------------------------------------
# Set the compilation flags.
# -----------------------------------------------------------------------------
# Set C++ Standard.
set(CMAKE_CXX_STANDARD 17)

# Set the actual flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")

    message(STATUS "Disabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

elseif (CMAKE_BUILD_TYPE STREQUAL "Release")

    message(STATUS "Enabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

# -----------------------------------------------------------------------------
# Add the C++ Executable.
# -----------------------------------------------------------------------------
add_executable(
    Sparsity_reduction
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

# -----------------------------------------------------------------------------
# Inlcude header directories and set the library.
# -----------------------------------------------------------------------------
# target_include_directories(
#     approximath PRIVATE
#     # Include project directories.
#     ${CMAKE_SOURCE_DIR}/include/
# )

# -----------------------------------------------------------------------------
# Add executable libraries (if required).
# -----------------------------------------------------------------------------
target_link_libraries(
   Sparsity_reduction
   sdsl
   divsufsort
   divsufsort64
)
