#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    DoublyLinkedList::head = NULL;
    DoublyLinkedList::tail = NULL;
    DoublyLinkedList::size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != tail) {
        head = head->next;
        delete head->prev;
    }
    delete tail;
}
//Dodaj na poczatek
void DoublyLinkedList::insertHead(int val) {
    ListNode *node = new ListNode(val, NULL, head);
    //sprawdz czy istnieje element poczatkowy
    if (head != NULL) {
        head->prev = node;
    } else {
        //
        tail = node;
    }
    head = node;
    //zwieksz rozmiar listy
    size++;
}
//Dodaj na koniec
void DoublyLinkedList::insertTail(int val) {
    ListNode *node = new ListNode(val, tail, NULL);
    if (tail != NULL) {
        tail->next = node;
    } else {
        head = node;
    }
    tail = node;
    size++;
}
//Dodaj gdziekolwiek
void DoublyLinkedList::insert(int val, int index) {
    //Sprawdz  czy w liscie istnieje pozycja podana przez uzytkownika
    if (index < 0 || index > size) {
        cout << "Nie ma elementu o tym indeksie: [" << index << "]" << endl;
        return;
    }
    //Sprawdz czy wybrana pozycja jest pierwsza
    if (index == 0) {
        insertHead(val);
        return;
    }
    //Sprawdz czy wybrana pozycja jest ostatnia
    if (index==size) {
        insertTail(val);
        return;

    }
    ListNode *prev_node = head;
        for (int i = 0; i < index - 1; i++) {
            prev_node = prev_node->next;
        }
    // Znajdź element znajdujący się po wybranej pozycji
    ListNode *next_node = prev_node->next;
    // Stwórz nowy element listy z podanymi parametrami
    ListNode *node = new ListNode(val, prev_node, next_node);
    prev_node->next = node;
    next_node->prev = node;

    size++;
}
//usun pierwszy element
void DoublyLinkedList::removeHead() {
    if (head != NULL) {
        if(size>1)
        {
            head->next->prev = NULL;
            head = head->next;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        size--;

    } else {
        cout << "Lista jest pusta" << endl;
    }
}
//usun ostatni element
void DoublyLinkedList::removeTail() {
    if (tail != NULL) {
        if(size>1)
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        size--;
    } else {
        cout << "Lista jest pusta" << endl;
    }
}
//usun dowolny element z listy
void DoublyLinkedList::remove(int index) {
    //Sprawdz czy w liscie istnieje pozycja podana przez uzytkownika
    if (index < 0 || index > size) {
        cout << "Nie ma elementu o takim indeksie: [" << index << "]" << endl;
        return;
    }
    //Sprawdz czy wybrana pozycja jest pierwsza
    if (index == 0) {
        removeHead();
        return;
    }
    //Sprawdz czy wybrana pozycja jest ostatnia
    if (index == size - 1) {
        removeTail();
        return;
    }
    ListNode* node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    size--;
}
//wyswietlanie listy
void DoublyLinkedList::displayList() {
    if (head != NULL) {
        ListNode *tempNode = head;
        while (tempNode != NULL) {
            cout << tempNode->val << " ";
            //Przypisz kolejny element listy jako aktualny
            tempNode = tempNode->next;
        }
        cout << endl;
    } else {
        cout << "Lista jest pusta" << endl;
    }
}
//sprawdzanie czy dany element istnieje
bool DoublyLinkedList::checkIfExist(int val) {
    if (head != NULL) {
        ListNode *tempNode = head;
        while (tempNode->val!= val) {
            tempNode = tempNode->next;
            if (!tempNode) {
                return false;
            }
        }
        cout << "Wartosc znajduje sie w liscie" << endl;
        return true;
    } else {
        cout << "Lista jest pusta" << endl;
        return false;
    }
}

