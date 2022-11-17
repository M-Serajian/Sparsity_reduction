# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-src"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-build"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/tmp"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src"
  "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/klib-subbuild/klib-populate-prefix/src/klib-populate-stamp/${subDir}")
endforeach()
