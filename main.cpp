#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "main.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>




void initializeHeap(HEAP* pHeap, ELEMENT** V, int capacity) {
    
    pHeap->capacity = capacity;
    pHeap->H = new int[capacity + 1];
    pHeap->size = 0;
    for (int i = 1; i <= capacity; i++) {
        V[i] = new ELEMENT;
        V[i]->key = std::numeric_limits<double>::infinity(); 
        V[i]->pos = 0;
    }
}


void printHeap(HEAP* pHeap, ELEMENT** V) {
        std::cout << "Instruction: PrintHeap\n";
        std::cout << "Capacity = " << pHeap->capacity << ", size = " << pHeap->size << std::endl;

        if (pHeap->size > 0) {
            for (int i = 1; i <= pHeap->size; i++) {
                std::cout << "H[" << i << "] = " << pHeap->H[i] << std::endl;
            }
        }
    }

void printArray(HEAP* pHeap, ELEMENT** V) {
    std::cout << "Instruction: PrintArray\n";
    for (int i = 1; i <= pHeap->capacity; i++) {
        std::cout << i << " " << std::fixed << std::setprecision(6) 
                << V[i]->key << " " << V[i]->pos << std::endl;
    }
}


void read(HEAP* pHeap, ELEMENT**& V, const std::string& inFile, bool isFromMain) {
    if (isFromMain) {
        std::cout << "Instruction: Read\n";
    }
    std::ifstream inputFile(inFile);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file.\n";
        return;
    } 
    int size;
    inputFile >> size;
    
    pHeap->capacity = size;
    V = new ELEMENT*[size + 1];
    pHeap->H = new int[size + 1];  
    for (int i = 1; i <= size; i++) {
        V[i] = new ELEMENT;
        inputFile >> V[i]->key;
        V[i]->pos = 0;
        pHeap->H[i] = 0;
    }
    inputFile.close();
}

void write(HEAP* pHeap, ELEMENT** V, const std::string outFile) {
    std::cout << "Instruction: Write\n";
    std::ofstream outputFile(outFile);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file.\n";
        return;
    }
    
    for (int i = 1; i <= pHeap->capacity; i++) {
        outputFile << i << " " << std::fixed << std::setprecision(6) 
                << V[i]->key << " " << V[i]->pos << std::endl;
    }
    outputFile.close();
}

void stop() {
    std::cout << "Instruction: Stop\n";
    exit(0); 
}

void unknownInstruction() {
    std::cerr << "Error: Unknown instruction.\n";
}

void intructionType(HEAP* pHeap, ELEMENT** V, const std::string& inFile, const std::string outFile) {
    std::string cmmd;
    int index;
    double keyN;

    while (std::cin >> cmmd) {
        if (cmmd == "Insert") {
            std::cin >> index;
            insert(pHeap, V, index);
        } else if (cmmd == "ExtractMin") {
            ELEMENT* minEl = extractMin(pHeap, V);
            if (minEl != nullptr) {
                //needed condition but nothing needs to happen?
                }
        } else if (cmmd == "BuildHeap") {
            buildHeap(pHeap, V);
        } else if (cmmd == "DecreaseKey") {
            std::cin >> index >> keyN;
            decreaseKey(pHeap, V, index, keyN);
        } else if (cmmd == "PrintHeap") {
            printHeap(pHeap, V);
        } else if (cmmd == "PrintArray") {
            printArray(pHeap, V);
        } else if (cmmd == "Read") {
            read(pHeap, V, inFile, false);
            //std::cout << "Instruction: Read\n";
        } else if (cmmd == "Write") {
            write(pHeap, V, outFile);
        } else if (cmmd == "Stop") {
            stop();
        } else {
            unknownInstruction();
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./PJ2 <I-File> <O-File>\n";
        return 1;
    }

    std::string inFile = argv[1];
    std::string outFile = argv[2];
    HEAP pHeap;
    ELEMENT** V = nullptr;
    
    initializeHeap(&pHeap, V, pHeap.capacity);
    read(&pHeap, V, inFile, true);
    intructionType(&pHeap, V, inFile, outFile);
    
    for (int i = 1; i <= pHeap.capacity; i++) {
        delete V[i];
    }
    delete[] V;
    delete[] pHeap.H;

    return 0;
}

