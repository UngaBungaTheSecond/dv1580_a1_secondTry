#include <stdbool.h>
#include "common_defs.h"

typedef struct memoryBlock{
    void* start;
    size_t blocksize;
    bool taken;
} memoryBlock; 

void mem_init(size_t size);
void* mem_alloc(size_t size);
void mem_free(void* block);
void* mem_resize(void* block, size_t size);
void mem_deinit();
