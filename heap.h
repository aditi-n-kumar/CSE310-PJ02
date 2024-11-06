#ifndef HEAP_H
#define HEAP_H 1

#include "data_structures.h"

// Function prototypes
void swapElements(HEAP *pHeap, ELEMENT **V, int i, int j);
void heapify(HEAP *pHeap, ELEMENT **V, int i);
void buildHeap(HEAP* pHeap, ELEMENT **V);
void insert(HEAP *pHeap, ELEMENT **V, int index);
//void extractMin(HEAP *pHeap, ELEMENT **V);
ELEMENT *extractMin(HEAP *heap, ELEMENT **elementsArray);
void decreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey);

#endif // HEAP_H

/*
P *pHeap, ELEMENT **V, int index, double key);

void buildHeap(HEAP *pHeap, ELEMENT **V, int n);
void insert(HEAP *pHeap, ELEMENT **V, int index);
void extractMin(HEAP *pHeap, ELEMENT **V);
void decreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey);
void heapify(HEAP *pHeap, ELEMENT **V, int i);

#endif // HEAP_H */
