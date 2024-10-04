#include <stdbool.h>
#include "common_defs.h"

typedef struct memoryBlock{  // strukt of the layout of a block
    void* start; // points to where the memory block starts
    size_t blocksize; // the size of memory
    bool taken; // if it is occupied
} memoryBlock; 

//declaration of functions
void mem_init(size_t size);
void* mem_alloc(size_t size);
void mem_free(void* block);
void* mem_resize(void* block, size_t size);
void mem_deinit();
