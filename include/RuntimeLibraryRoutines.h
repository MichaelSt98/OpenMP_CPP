#ifndef OPENMP_CPP_RUNTIMELIBRARYROUTINES_H
#define OPENMP_CPP_RUNTIMELIBRARYROUTINES_H

#include <iostream>
#include "omp.h"


/**
 * See [Runtime library routines](https://software.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/optimization-and-programming-guide/openmp-support/openmp-library-support/openmp-run-time-library-routines.html)
 */

/**
 * Runtime routines for monitoring and influencing threads.
 */
void monitor_influence_threads_routines(int debug = 0);

/**
 * Runtime routines for locking threads.
 */
void lock_routines(int debug = 0);

/**
 * Runtime routines for timing.
 */
void timing_routines(int debug = 0);


#endif //OPENMP_CPP_RUNTIMELIBRARYROUTINES_H

