#include "common_defs.h"
#include"memory_manager.h"

void* memory;
size_t memorySize;
int nrofBlocks;

memoryBlock *TheBlocks; // <--- dynamisk array senare

void mem_init(size_t size){
    TheBlocks = malloc(size * sizeof(memoryBlock));
    memory = malloc(size);
    TheBlocks[0] = (memoryBlock){memory, size, false};
    nrofBlocks = 1;
    memorySize = size;
}

void* mem_alloc(size_t size){
    if(size > memorySize){printf("no space here for that");}

    int i = 0;
    while (i< nrofBlocks && (TheBlocks[i].taken == true || TheBlocks[i].blocksize < size)){i++;}

    if(i >= nrofBlocks) return NULL;

    if(TheBlocks[i].blocksize == size){
        TheBlocks[i].taken = true;
        return TheBlocks[i].start;
    }

    else{
        void* newStart = (void*)((char*)TheBlocks[i].start + size + 1);
        TheBlocks[nrofBlocks]=(memoryBlock){newStart, TheBlocks[i].blocksize - size, false};

        TheBlocks[i].blocksize = size;
        TheBlocks[i].taken = true;
        nrofBlocks++;
        return TheBlocks[i].start;
    }
}

void mem_free(void* block){
    int i =0;
    while(i < nrofBlocks && TheBlocks[i].start != block) {i++;}
    if(i>= nrofBlocks){return;}
    TheBlocks[i].taken = false;
}

void* mem_resize(void* block, size_t size){
    mem_free(block);
    return mem_alloc(size);
}

void mem_deinit(){
    free(memory);
}
