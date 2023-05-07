#include <iostream>
#include "Test.h"
#include "FileTests.h"

using namespace std;

int main() {
    Test test;
    FileTests fileTests;
    int choice = -100;
    string fromFile;

    while (choice != 0) {
        cout << "Projekt 1 Joanna Zoglowek 264452" << endl;
        cout << "Wybierz strukture danych:" << endl;
        cout << "   1. Lista dwukierunkowa" << endl;
        cout << "   2. Tablica dynamiczna" << endl;
        cout << "   3. Kopiec binarny" << endl;
        cout << "   4. Drzewo czerwono-czarne" << endl;
        cout << "   0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;
        cout << "Chcesz uzyc danych z pliku? Napisz tak lub nie: ";
        cin >> fromFile;
        switch (choice) {
            case 0:
                return 0;
            case 1:
                if (fromFile == "tak") {
                    fileTests.DoublyLinkedListTest();
                } else
                    test.testLinkedList();
                break;
            case 2:
                if (fromFile == "tak") {
                    fileTests.ArrayTest();
                } else
                    test.testArray();
                break;
            case 3:
                if (fromFile == "tak") {
                    fileTests.BinaryHeapTest();
                } else
                    test.testBinaryHeap();
                break;
            case 4:
                if (fromFile == "tak") {
                   fileTests.RedBlackTreeTest();
                } else
                    test.testRedAndBlackTree();
                    break;
            default:
                cout << "Zly wybor!" << endl;
                break;
        }
    }
    return 0;
}


