#ifndef _data_structures_h
#define _data_structures_h 1

//LOOK AT THIS AGAIN
    
typedef struct TAG_ELEMENT{
    int index; // index of the element
    double key; // key value of the element
    int pos; // index in the heap-array, 0 if not in the heap

    }ELEMENT;

typedef struct TAG_HEAP{
    int capacity; // capacity of the heap
    int size; // current size of the heap
    int *H; // array of pointers to indices of the ELEMENT array
    }HEAP;


#endif
