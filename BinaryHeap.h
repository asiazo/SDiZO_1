#ifndef SDIZO1_BINARYHEAP_H
#define SDIZO1_BINARYHEAP_H

class BinaryHeap {
public:
    int *array;
    int size;

    BinaryHeap();

    ~BinaryHeap();

    void insert(int value);

    void deleteRoot();

    int checkIfExist(int value);

    void displayHeap();

private:
    void heapify(int index);

    void printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent);

    bool heapTest();
};

#endif //SDIZO1_BINARYHEAP_H

