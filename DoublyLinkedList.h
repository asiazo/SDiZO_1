#ifndef SDIZO1_DOUBLYLINKEDLIST_H
#define SDIZO1_DOUBLYLINKEDLIST_H


#include "ListNode.h"

class DoublyLinkedList {

public:
    int size;

    ListNode *head;
    ListNode *tail;

    DoublyLinkedList();

    ~DoublyLinkedList();

    void insertHead(int val);

    void insertTail(int val);

    void insert(int val, int index);

    void removeHead();

    void removeTail();

    void remove(int index);

    void displayList();

    bool checkIfExist(int val);
};


#endif //SDIZO1_DOUBLYLINKEDLIST_H
