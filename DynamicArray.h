//
// Created by radziu2402 on 10.03.2023.
//

#ifndef SDIZO1_DYNAMICARRAY_H
#define SDIZO1_DYNAMICARRAY_H

class DynamicArray {

public:
    int *head;
    int size;

    DynamicArray();

    ~DynamicArray();

    void insertHead(int value);

    void insertTail(int value);

    void insert(int value, int index);

    void removeHead();

    void removeTail();

    void remove(int index);

    void displayArray();

    int checkIfExist(int value);
};


#endif //SDIZO1_DYNAMICARRAY_H
