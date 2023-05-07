//
// Created by radziu2402 on 10.03.2023.
//
#include <iostream>
#include "DynamicArray.h"

using namespace std;

// konstruktor bezargumentowy, inicjujący wskaźnik na null i rozmiar na zero
DynamicArray::DynamicArray() {
    DynamicArray::head = nullptr;
    DynamicArray::size = 0;

}
// destruktor, usuwa tablice
DynamicArray::~DynamicArray() {
    delete[]head;
}

// wstawia element na początku tablicy dynamicznej
void DynamicArray::insertHead(int value) {
    // tworzy nową tablicę dynamiczną z rozmiarem zwiększonym o jeden
    int *newHead = new int[size + 1];
    newHead[0] = value;

    // kopiowanie elementów starej tablicy dynamicznej do nowej
    for (int i = 0; i < size; i++) {
        newHead[i + 1] = head[i];
    }

    // usuwa starą tablicę dynamiczną i przypisuje nową do wskaźnika head
    delete head;
    head = newHead;

    // zwiększa rozmiar tablicy dynamicznej
    size++;
}
// wstawia element na końcu tablicy dynamicznej
void DynamicArray::insertTail(int value) {
    // tworzy nową tablicę dynamiczną z rozmiarem zwiększonym o jeden
    int *newHead = new int[size + 1];
    newHead[size] = value;

    // kopiowanie elementów starej tablicy dynamicznej do nowej
    for (int i = 0; i < size; i++) {
        newHead[i] = head[i];
    }

    // usuwa starą tablicę dynamiczną i przypisuje nową do wskaźnika head
    delete[] head;
    head = newHead;

    // zwiększa rozmiar tablicy dynamicznej
    size++;
}

// wstawia element pod wybrany index tablicy dynamicznej
void DynamicArray::insert(int value, int index) {
// sprawdzenie, czy podany index jest poprawny
    if (index < 0 || index > size) {
        cout << "There is no element with index: [" << index << "]!" << endl;
    } else {
// utworzenie nowej tablicy dynamicznej z dodatkowym elementem
        int *newHead = new int[size + 1];
        newHead[index] = value;

        // skopiowanie elementów z tablicy oryginalnej do nowej
        for (int i = 0; i < index; i++) {
            newHead[i] = head[i];
        }
        for (int i = index; i < size; i++) {
            newHead[i + 1] = head[i];
        }

        // zwolnienie pamięci po starej tablicy i przypisanie nowej tablicy do wskaźnika head
        delete[] head;
        head = newHead;

        // zwiększenie licznika elementów
        size++;
    }
}

// usuwa element na początku tablicy dynamicznej
void DynamicArray::removeHead() {
// sprawdzenie, czy tablica nie jest pusta
    if (size > 0) {
// utworzenie nowej tablicy dynamicznej bez pierwszego elementu
        int *newHead = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newHead[i] = head[i + 1];
        }

        // zwolnienie pamięci po starej tablicy i przypisanie nowej tablicy do wskaźnika head
        delete[] head;
        head = newHead;

        // zmniejszenie licznika elementów
        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}

// usuwa element na końcu tablicy dynamicznej
void DynamicArray::removeTail() {
// sprawdzenie, czy tablica nie jest pusta
    if (size > 0) {
// utworzenie nowej tablicy dynamicznej bez ostatniego elementu
        int *newHead = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newHead[i] = head[i];
        }

        // zwolnienie pamięci po starej tablicy i przypisanie nowej tablicy do wskaźnika head
        delete[] head;
        head = newHead;

        // zmniejszenie licznika elementów
        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}
// usuwa element pod wybranym indexem tablicy dynamicznej
void DynamicArray::remove(int index) {
    // Sprawdzamy czy istnieje co najmniej jeden element w tablicy i czy podany indeks jest poprawny
    if (size > 0 && index >= 0 && index < size) {
        // Tworzymy nowy dynamiczny bufor o rozmiarze size-1
        int *newHead = new int[size - 1];

        // Kopiujemy elementy z head do newHead do indeksu włącznie
        for (int i = 0; i < index; i++) {
            newHead[i] = head[i];
        }

        // Kopiujemy elementy z head do newHead od indeksu+1 do końca
        for (int i = index; i < size - 1; i++) {
            newHead[i] = head[i + 1];
        }

        // Usuwamy stary dynamiczny bufor head
        delete[] head;

        // Przypisujemy nowy dynamiczny bufor newHead do head
        head = newHead;

        // Zmniejszamy rozmiar tablicy
        size--;
    } else {
        cout << "There is no element with index: [" << index << "]!" << endl;
    }
}


// Metoda do wyświetlania tablicy
void DynamicArray::displayArray() {
    if (size > 0) {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << head[i] << ", ";   // Wypisuje wartość elementu na indeksie i
        }
        cout << "]" << endl;
    } else {
        cout << "Array is empty" << endl;   // Wypisuje informację, że tablica jest pusta
    }
}

// Metoda sprawdzająca, czy element o podanej wartości istnieje w tablicy
int DynamicArray::checkIfExist(int value) {
    for (int i = 0; i < size; i++) {
        if (head[i] == value) {    // Jeśli wartość elementu na indeksie i jest równa wartości value, to zwraca index
            return i;
        }
    }
    return -1;
}