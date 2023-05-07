#include <iostream>
#include "BinaryHeap.h"

using namespace std;

BinaryHeap::BinaryHeap() {
    BinaryHeap::array = NULL;
    BinaryHeap::size = 0;
}

BinaryHeap::~BinaryHeap() {
    if (BinaryHeap::size > 0) {
        delete[]array;
    }
}
//Dodawanie wartosci do kopca
void BinaryHeap::insert(int val) {
    if (size == 0) {
        array = new int[1];
        array[0] = val;
        size++;
        return;
    }
    //Stworz nowa tablice wieksza o jeden elemen
    int *newArray = new int[size+1];
    //Przepisanie danych ze starej tablicy do nowej
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    //Dodanie wybranej wartosci do kopca
    newArray[size] = val;
    //Usuneicie starej tablicy
    delete[]array;
    //Zastapienie starej tablicy nowa
    array = newArray;
    //Zwiekszamy rozmiar kopca o 1
    size++;
    //Wywolanie funkcji
    heapify(size-1);
}

void BinaryHeap::deleteRoot() {
    if (size == 0){
        cout << "Kopiec jest pusty" <<endl;
        return;
    }
    int index = checkIfExist(array[0]);
    if (size != 0) {
        //Nowa tablica pomniejszona o jeden element
        int *newArray = new int[size - 1];
        //Przepisujemy pozostale elementy przesuniete o jedna pozycje
        for (int k = 1; k < size; k++) {
            newArray[k - 1] = array[k];
        }
        //usuwamy stara tablice i przepisujemy na jej miejsce nowa
        delete[]array;
        array = newArray;
        heapify(index);
        //zmniejsz rozmiar tablicy
        size--;
        heapify(index);

    }
}
//funkcja sprawdza czy istnieje dana wartosc
int BinaryHeap::checkIfExist(int val) {
    if(size==0)
    {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        //jesli wartosc wystepuje zwraca indeks
        if (array[i] == val) {
            return i;
        }
    }
    return -1;
}

void BinaryHeap::displayHeap() {
    if (array != NULL) {
        printHeap(array, size, 0, 2);
    } else {
        cout << "Heap is empty" << endl;
    }
}

//funkcja poprawia strukture kopca
void BinaryHeap::heapify(int index) {
    int parent, leftChild, rightChild, maxChild;
    for (int i = size - 1; i >= 0; i--) {
        parent = i;
        while (true) {
            leftChild = 2 * parent + 1;
            rightChild = 2 * parent + 2;
            if (leftChild >= size) {
                break;
            }
            maxChild = leftChild;
            if (rightChild < size && array[rightChild] > array[leftChild]) {
                maxChild = rightChild;
            }
            if (array[parent] >= array[maxChild]) {
                break;
            }
            swap(array[parent], array[maxChild]);
            parent = maxChild;
        }
    }
}
//funkcja drukuje kopiec
void BinaryHeap::printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent) {
    if (currentNodeIndex >= heapSize)
        return;

    int indentIncrease = 4;
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 2, levelIndent + indentIncrease);

    for (int j = 0; j < levelIndent; j++)
        cout << " ";
    cout << heapArray[currentNodeIndex] << endl;

    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 1, levelIndent + indentIncrease);
}




