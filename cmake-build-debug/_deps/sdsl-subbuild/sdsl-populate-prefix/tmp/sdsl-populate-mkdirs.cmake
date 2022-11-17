# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-src"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-build"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-subbuild/sdsl-populate-prefix"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-subbuild/sdsl-populate-prefix/tmp"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-subbuild/sdsl-populate-prefix/src/sdsl-populate-stamp"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-subbuild/sdsl-populate-prefix/src"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-subbuild/sdsl-populate-prefix/src/sdsl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-subbuild/sdsl-populate-prefix/src/sdsl-populate-stamp/${subDir}")
endforeach()
