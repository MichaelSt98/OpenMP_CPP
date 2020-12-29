#include <iostream>
#include "omp.h"
#include <stdio.h>

#include "../include/hello_world.h"
#include "../include/Basics.h"
#include "../include/RuntimeLibraryRoutines.h"

int main() {

    std::cout << "Exploring OpenMP..." << std::endl;

    int max_threads = omp_get_max_threads();
    std::cout << "Max(available threads) = " << max_threads << std::endl << std::endl;

    std::cout << "CALLING: hello_world() from hello_world.cpp ..." << std::endl;
    hello_world();

    std::cout << std::endl;
    std::cout << "CALLING: parallel_construct() from Basics.cpp ..." << std::endl;
    std::cout << "number of threads = default" << std::endl;
    parallel_construct();
    std::cout << "number of threads = 2" << std::endl;
    parallel_construct(2);

    std::cout << std::endl;
    std::cout << "CALLING: for_construct() from Basics.cpp ..." << std::endl;
    for_construct();
    for_construct(2);

    std::cout << std::endl;
    std::cout << "CALLING: sections_construct() from Basics.cpp ..." << std::endl;
    sections_construct();

    std::cout << std::endl;
    std::cout << "CALLING: simd_construct() from Basics.cpp ..." << std::endl;
    simd_construct();


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "CALLING: monitor_influence_threads_routines() from RuntimeLibraryRoutines.cpp ..." << std::endl;
    monitor_influence_threads_routines(1);

    std::cout << std::endl;
    std::cout << "CALLING: lock_routines() from RuntimeLibraryRoutines.cpp ..." << std::endl;
    lock_routines(1);

    std::cout << std::endl;
    std::cout << "CALLING: lock_routines() from RuntimeLibraryRoutines.cpp ..." << std::endl;
    timing_routines(1);

    return 0;
}
