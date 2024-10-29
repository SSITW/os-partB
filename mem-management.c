#include <stdio.h>
#include <stdlib.h>

// Global variables
int init_global1 = 1;
int init_global2 = 2;

int uninit_global1;
int uninit_global2;

// Local variables
void function(int n) {

    if (n > 3) {
        return ;
    }

    int local = n;
    printf("Address of local%d : %p\n", n, (void*)&local);
    function(n + 1);
}

int main() {

    // Global variable
    printf("\n");
    printf("Initialized Global\n");
    printf("Address of init_global1: %p\n", (void*)&init_global1);
    printf("Address of init_global2: %p\n", (void*)&init_global2);

    printf("Uninitialized Global\n");
    printf("Address of uninit_global1: %p\n", (void*)&uninit_global1);
    printf("Address of uninit_global2: %p\n", (void*)&uninit_global2);
    
    printf("--------------------------------------------\n");

    // Heap memory
    int *heap1 = (int*)malloc(sizeof(int));
    int *heap2 = (int*)malloc(sizeof(int));
    int *heap3 = (int*)malloc(sizeof(int));
    
    printf("Heap Memory\n");
    printf("Address of heap1: %p\n", (void*)heap1);
    printf("Address of heap2: %p\n", (void*)heap2);
    printf("Address of heap3: %p\n", (void*)heap3);

    printf("--------------------------------------------\n");

    // Stack memory
    printf("Stack Memory\n");
    function(1);

    printf("\n");

    // Free heap memory
    free(heap1);
    free(heap2);
    free(heap3);

    return 0;
}
