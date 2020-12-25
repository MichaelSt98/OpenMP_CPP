#include "../include/hello_world.h"

void hello_world() {

    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("Hello(%d)", ID);
        printf(" World(%d) \n", ID);

        // not working properly in this context
        //std::cout << "Hello (from " << ID << ")" << std::endl;
        //std::cout << "World (from " << ID << ")" << std::endl;
    }

}

