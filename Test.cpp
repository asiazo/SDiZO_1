#include <iostream>
#include <fstream>
#include "Test.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "BinaryHeap.h"
#include "RedAndBlackTree.h"

using namespace std;

void Test::testArray() {
    CountTime time;
    DynamicArray a;
    int choice = 99, val, entry;
    string inputFileName;
    string  outputFileName;
    ifstream inputFile;
    ofstream outputFile;

    while (choice != 0) {
        cout << "Wybierz funkcje tablicy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj w dowolne miejsce" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun dowolny element" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablice" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;
        cout << "Z jakiego pliku chcesz wziac dane:  ";
        cin >> inputFileName;
        cout << "Plik z wynikami testu: ";
        cin >> outputFileName;

        inputFile.open(inputFileName);
        outputFile.open(outputFileName, fstream::out);

        if (inputFile.is_open()) {
            cout << "Zawartosc otwartego pliku: " << inputFileName << endl;
        } else {
            cout << "Nie udalo sie otworzyc pliku " << endl;
            return;
        }
        if(outputFile.is_open())
        {
            cout<<"Otworzono plik"<<endl;
        }else
        {
            cout<<"Nie udalo sie otworzyc pliku wyjsciowego"<<endl;
            return;
        }
        inputFile >> val;
        int size = val;
        while (inputFile >> val) {
            a.insertTail(val);
        }
        if(size != a.size){
            cout << "Rozmiar pliku nie jest zgodny z iloscia elementow " << endl;
            return;
        }
        a.displayArray();
        switch (choice) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                a.insertHead(val);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime()<< "ns" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                a.insertTail(val);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime()<< "ns" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << "Podaj pozycje: ";
                cin >> entry;
                time.timeStart();
                a.insert(val, entry);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime()<< "ns" << endl;
                break;

            case 4:
                time.timeStart();
                a.removeHead();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 5:
                time.timeStart();
                a.removeTail();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 6:
                cout << "Podaj pozycje: ";
                cin >>entry;
                time.timeStart();
                a.remove(entry);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 7:
                cout << "Podaj wartosc: ";
                cin >>val;
                time.timeStart();
                a.checkIfExist(val);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 8:
                time.timeStart();
                a.displayArray();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;
        }

    }
}

void Test::testLinkedList() {
    CountTime time;
    DoublyLinkedList linkedList;
    int choice = 99;
    int val, entry;

    while (choice != 0) {
        cout << "Wybierz funkcje listy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj na dowolne miejsce" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun dowolny element" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj liste" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;
        switch (choice) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                linkedList.insertHead(val);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                linkedList.insertTail(val);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> val;
                cout << "Podaj pozycje: ";
                cin >> entry;
                time.timeStart();
                linkedList.insert(val,entry);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                linkedList.removeHead();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 5:
                time.timeStart();
                linkedList.removeTail();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 6:
                cout << "Podaj pozycje: ";
                cin >> entry;
                time.timeStart();
                linkedList.remove(entry);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 7:
                cout << "Podaj wartosc: ";
                cin >> entry;
                time.timeStart();
                linkedList.checkIfExist(val);
                time.timeStop();
                if (linkedList.checkIfExist(val)!=-1) {
                    cout << "Ten element znajduje sie w liscie " << endl;
                } else {
                    cout << "Ten element nie znajduje sie w liscie " << endl;
                }
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 8:
                time.timeStart();
                linkedList.displayList();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

        }

    }
}

void Test::testBinaryHeap() {
    CountTime time;
    BinaryHeap heap;
    int choice = 99;
    int val;
    while (choice != 0) {
        cout << "Wybierz funkcje kopca binarnego:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;
        switch (choice) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                heap.insert(val);
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                heap.deleteRoot();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                heap.checkIfExist(val);
                time.timeStop();
                if (heap.checkIfExist(val)!=-1) {
                    cout << "Ten element znajduje sie w kopcu " << endl;
                } else {
                    cout << "Ten element nie znajduje sie w kopcu " << endl;
                }
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                heap.displayHeap();
                time.timeStop();
                cout << "Czas wykonania: " <<  time.workingTime() << "ns" << endl;
                break;
        }

    }
}
void Test::testRedAndBlackTree() {
    CountTime time;
    RedAndBlackTree tree;
    int choice = -100, val;
    NodePtr nodeptr;
    while (choice != 0) {
        cout << "Wybierz funkcje drzewa czerwono-czarnego:" << endl;
        cout << "    1. Dodaj wartosc" << endl;
        cout << "    2. Usun wartosc" << endl;
        cout << "    3. Sprawdz czy dana wartosc istnieje" << endl;
        cout << "    4. Wydrukuj drzewo czerwono-czarne" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;
        switch (choice) {
            default:
                cout << "Wybrales zla cyfre!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                tree.insert(val);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                tree.printTree();
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                tree.deleteNode(val);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime()<< "ns" << endl;
                tree.printTree();
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> val;
                time.timeStart();
                nodeptr = tree.searchTree(val);
                time.timeStop();
                if (nodeptr != nullptr) {
                    cout << "Ten element wystepuje w drzewie czerwono-czarnym" << endl;
                } else {
                    cout << "Ten element nie wystepuje w drzewie czerwono-czarnym" << endl;
                }
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                tree.printTree();
                time.timeStop();
                cout << endl;
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                break;
        }
    }
}

