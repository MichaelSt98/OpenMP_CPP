#ifndef OPENMP_CPP_BASICS_H
#define OPENMP_CPP_BASICS_H

#include "omp.h"
#include <iostream>
#include <stdio.h>

void parallel_construct(int number_of_threads = 4);
void for_construct(int number_of_threads = 4);
void sections_construct();
//SIMD (Single-Instruction, Multiple-Data)
void simd_construct();

#endif //OPENMP_CPP_BASICS_H
