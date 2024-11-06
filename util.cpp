#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "util.h"
#include <iostream>
#include <fstream>

using namespace std;
/*
void printArray(ELEMENT **V, int n) {
    cout << "Instruction: PrintArray\n";
    if (!V) {
        cerr << "Error: array is NULL\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " " << V[i]->key << " " << V[i]->pos << endl;
    }
}

void printHeap(HEAP *pHeap, ELEMENT **V) {
    cout << "Instruction: PrintHeap\n";
    if (!pHeap) {
        cerr << "Error: heap is NULL\n";
        return;
    }
    for (int i = 1; i <= pHeap->size; i++) {
        cout << i << " " << V[pHeap->H[i]]->key << " " << V[pHeap->H[i]]->pos << endl;
    }
}

void writeFile(const char *filename, ELEMENT **V, int n) {
    cout << "Instruction: Write\n";
    ofstream ofs(filename);
    if (!ofs) {
        cerr << "Error: cannot open file " << filename << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        ofs << i << " " << V[i]->key << " " << V[i]->pos << endl;
    }
    ofs.close();
}

*/



