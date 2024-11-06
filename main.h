#ifndef MAIN_H
#define MAIN_H

#include "data_structures.h"
#include "util.h"
#include "heap.h"
#include <string>

// Function declarations
void initHeap(HEAP* pHeap, ELEMENT** V, int capacity);
void printHeap(HEAP* pHeap, ELEMENT** V);
void printArray(HEAP* pHeap, ELEMENT** V);
void read(HEAP* pHeap, ELEMENT**& V, const std::string& inputFileName, bool isFromMain);
void write(HEAP* pHeap, ELEMENT** V, const std::string outputFileName);
void stop();
void unknownInstruction();
void intructionType(HEAP* pHeap, ELEMENT** V, const std::string& inputFileName, const std::string outputFileName);

#endif // MAIN_H
