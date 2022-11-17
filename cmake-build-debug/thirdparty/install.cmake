MESSAGE(STATUS "Installing sdsl.")
execute_process(COMMAND ./install.sh ${CMAKE_INSTALL_PREFIX}
                WORKING_DIRECTORY /s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/_deps/sdsl-src 
                OUTPUT_FILE /s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/thirdparty/logs/sdsl.log
                ERROR_FILE /s/nut/a/homes/m.serajian/projects/Sparsity_reduction/cmake-build-debug/thirdparty/logs/sdsl.log)
