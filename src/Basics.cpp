//
// Created by Michael Staneker on 26.12.20.
//

#include "../include/Basics.h"

void parallel_construct(int number_of_threads) {

    #pragma omp parallel num_threads(number_of_threads)
    {
        int ID = omp_get_thread_num();
        printf("Thread = %d\n", ID);
    }
}

void for_construct(int number_of_threads) {

    #pragma omp parallel for num_threads(number_of_threads)
    {
        for (int n = 0; n < 10; ++n) {
            int ID = omp_get_thread_num();
            printf(" %d (from %d)  ", n, ID);
        }
    }

    printf(".\n");

}

void sections_construct() {
    #pragma omp parallel
    {
    #pragma omp sections
        {
            {
                int ID = omp_get_thread_num();
                printf("sections (ID = %d)\n", ID);
            }
    #pragma omp section
            {
                int ID = omp_get_thread_num();
                printf("section 1 line 1 (ID = %d)\n", ID);
                printf("section 1 line 2 (ID = %d)\n", ID);
            }
    #pragma omp section
            {
                int ID = omp_get_thread_num();
                printf("section 2 line 1 (ID = %d)\n", ID);
                printf("section 2 line 2 (ID = %d)\n", ID);
            }
        }
        int ID = omp_get_thread_num();
        printf("parallel (ID = %d)\n", ID);
    }
}

void simd_construct() {
    //float a[8], b[8];
    //a[0] = 5, a[1] = 4, b[1] = 1, b[2] = 14, a[3] = 12, b[4] = 11, a[5] = 1, b[6] = 9, a[7] = 3;
    float a[6] = {1, 5, 3, 5, 6, 3};
    float b[6] = {4, 3, 7, 3, 9, 1};

    #pragma omp simd
        {
            for (int n = 0; n < 6; ++n) {
                a[n] += b[n];
                int ID = omp_get_thread_num();
                printf("simd for n = %d (ID = %d)  a[%d] = %f\n", n, ID, n, a[n]);

                b[n] -= a[n];
                ID = omp_get_thread_num();
                printf("simd for n = %d (ID = %d)  b[%d] = %f\n", n, ID, n, a[n]);
                //printf("simd for n = %d  a[%d] = %f\n", n, n, a[n]);
            }
        }

}
