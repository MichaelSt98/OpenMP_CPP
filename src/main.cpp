#include <iostream>
#include "omp.h"
#include <stdio.h>
#include "../include/hello_world.h"

int main() {

    std::cout << "Exploring OpenMP..." << std::endl;

    int max_threads = omp_get_max_threads();
    std::cout << "Max(available threads) = " << max_threads << std::endl;

    hello_world();

    return 0;
}
