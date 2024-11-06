#include "heap.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

void swap(HEAP *heap, ELEMENT **elementsArray, int index1, int index2) {
    int tempIndex = heap->H[index1];
    heap->H[index1] = heap->H[index2];
    heap->H[index2] = tempIndex;

    elementsArray[heap->H[index1]]->pos = index1;  
    elementsArray[heap->H[index2]]->pos = index2;
}

void heapify(HEAP *heap, ELEMENT **elementsArray, int nodeIndex) {
    int smallest = nodeIndex;
    int leftChild = 2 * nodeIndex;    
    int rightChild = 2 * nodeIndex + 1;

    if (leftChild <= heap->size && elementsArray[heap->H[leftChild]]->key < elementsArray[heap->H[smallest]]->key) {
        smallest = leftChild;
    }

    if (rightChild <= heap->size && elementsArray[heap->H[rightChild]]->key < elementsArray[heap->H[smallest]]->key) {
        smallest = rightChild;
    }

    if (smallest != nodeIndex) {
        swap(heap, elementsArray, nodeIndex, smallest);
        heapify(heap, elementsArray, smallest);
    }
}

void buildHeap(HEAP *heap, ELEMENT **V) {
    std::cout << "Instruction: BuildHeap\n";

    heap->size = heap->capacity;

    for (int i = 1; i <= heap->capacity; i++) { 
        if (V[i] == nullptr) {
            V[i] = new ELEMENT;
            V[i]->key = std::numeric_limits<double>::infinity();
            V[i]->pos = 0;  
        }
        V[i]->pos = i;
        heap->H[i] = i;
    }

    for (int i = heap->size / 2; i >= 1; i--) {
        heapify(heap, V, i);
    }
}

void insert(HEAP *heap, ELEMENT **elementsArray, int newIndex) {
    std::cout << "Instruction: Insert " << newIndex << "\n";

    if (newIndex < 1 || newIndex > heap->capacity) {
        std::cerr << "Error: index out of bounds\n";
        return;
    }

    if (elementsArray[newIndex]->pos != 0) {
        std::cerr << "Error: Element already in the heap\n";
        return;
    }

    heap->size++;
    heap->H[heap->size] = newIndex;
    elementsArray[newIndex]->pos = heap->size;

    int currentIndex = heap->size;
    while (currentIndex > 1 && elementsArray[heap->H[currentIndex]]->key < elementsArray[heap->H[currentIndex / 2]]->key) {
        swap(heap, elementsArray, currentIndex, currentIndex / 2);
        currentIndex /= 2;
    }

    std::cout << "Element " << "V[" << newIndex << "]" << " inserted into the heap\n";
}

ELEMENT *extractMin(HEAP *heap, ELEMENT **elementsArray) {
    std::cout << "Instruction: ExtractMin\n";

    int minIndex = heap->H[1];
    ELEMENT *minElement = elementsArray[minIndex];

    heap->H[1] = heap->H[heap->size];
    elementsArray[heap->H[1]]->pos = 1;
    heap->size--;
    heapify(heap, elementsArray, 1);

    minElement->pos = 0;

    return minElement;
}

void decreaseKey(HEAP* heap, ELEMENT** elementsArray, int elementIndex, double newKey) {
    std::cout << "Instruction: DecreaseKey " << elementIndex << " " << newKey << "\n";
    if (elementIndex < 1 || elementIndex > heap->capacity || newKey >= elementsArray[elementIndex]->key) {
        std::cerr << "Error: invalid call to DecreaseKey\n";
        return;
    }
    if (elementsArray[elementIndex]->pos == 0) {
        std::cerr << "Error: Element not in the heap\n";
        return;
    }
    
    elementsArray[elementIndex]->key = newKey;

    int currentIndex = elementsArray[elementIndex]->pos;
    while (currentIndex > 1 && elementsArray[heap->H[currentIndex]]->key < elementsArray[heap->H[currentIndex / 2]]->key) {
        swap(heap, elementsArray, currentIndex, currentIndex / 2);
        currentIndex /= 2;
    }
}
