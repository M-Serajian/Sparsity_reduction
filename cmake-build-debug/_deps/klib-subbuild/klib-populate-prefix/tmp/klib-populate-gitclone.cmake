# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitclone-lastrun.txt" AND EXISTS "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitinfo.txt" AND
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" 
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/attractivechaos/klib" "klib-src"
    WORKING_DIRECTORY "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/attractivechaos/klib'")
endif()

execute_process(
  COMMAND "/usr/bin/git" 
          checkout "master" --
  WORKING_DIRECTORY "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitinfo.txt" "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/klib-populate-gitclone-lastrun.txt'")
endif()
