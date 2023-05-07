#include "FileTests.h"
#include "CountTime.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "BinaryHeap.h"
#include "RedAndBlackTree.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

void FileTests::DoublyLinkedListTest(){
    CountTime countTime;
    DoublyLinkedList list;
    int choice = -100;
    int value, randNum, randIndex, findIndex, n=100;
    string inputFileName;
    string  outputFileName;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Z jakiego pliku chcesz wziac dane:  ";
    cin >> inputFileName;
    cout << "Plik z wynikami testu: ";
    cin >> outputFileName;

    inputFile.open( inputFileName);
    outputFile.open( outputFileName, fstream::out);

    if (inputFile.is_open()) {
        cout << "Otworzono plik: " << inputFileName << endl;
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
    inputFile >> value;
    int size = value;
    while (inputFile >> value) {
        list.insertTail(value);
    }
    if(size != list.size){
        cout << "Ilosc elementow w pliku nie odpowiada zadeklarowanej wartosc!"<< endl;
        return;
    }
    inputFile.close();
    //list.displayList();

    while (choice != 0) {
        cout << "Co chcesz zrobic:" << endl;
        cout << "   1. Dodaj pierwszy element" << endl;
        cout << "   2. Dodaj ostatni element" << endl;
        cout << "   3. Dodaj element na dowolna pozycje" << endl;
        cout << "   4. Usun pierwszy element" << endl;
        cout << "   5. Usun ostatni element" << endl;
        cout << "   6. Usun dowolny element" << endl;
        cout << "   7. Sprawdz czy podany element istneje" << endl;
        cout << "   8. Wyswietl liste" << endl;
        cout << "   9. Wykonaj wszystkie operacje automatycznie" << "\n";
        cout << "   0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
            default:
                cout << "Zle wybrales cyfre!" << endl;
                break;

            case 0:
                outputFile.close();
                break;

            case 1:
                cout << "Wartosc: ";
                cin >> randNum;
                countTime.timeStart();
                list.insertHead(randNum);
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                list.displayList();

                break;

            case 2:
                cout << "Wartosc: ";
                cin >> randNum;
                countTime.timeStart();
                list.insertTail(randNum);
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                list.displayList();
                break;

            case 3:
                cout << "Wartosc: ";
                cin >> randNum;
                cout << "Indeks: ";
                cin >> randIndex;
                countTime.timeStart();
                list.insert(randNum, randIndex);
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                list.displayList();
                break;

            case 4:
                countTime.timeStart();
                list.removeHead();
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                list.displayList();
                break;

            case 5:
                countTime.timeStart();
                list.removeTail();
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                list.displayList();
                break;

            case 6:
                cout << "Indeks: ";
                cin >> randIndex;
                countTime.timeStart();
                list.remove(randIndex);
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                list.displayList();
                break;

            case 7:
                cout << "Wartosc: ";
                cin >> randNum;
                countTime.timeStart();
                findIndex = list.checkIfExist(randNum);
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                if(findIndex!=-1){
                    cout << "Ten element znajduje sie na liscie na indeksie [" << findIndex << "]" << endl;
                }
                else cout << "Ten element nie znajduje sie na liscie" << endl;
                break;

            case 8:
                countTime.timeStart();
                list.displayList();
                countTime.timeStop();
                cout << "Czas wykonania: " << countTime.workingTime() << "ns" << endl;
                outputFile << countTime.workingTime() <<endl;
                break;
                //9 case jest funkcja potrzebna przy automatycznym testowaniu
            case 9:
                int n=100, num, x=2;
                DoublyLinkedList list2;
                long double avg=0;
                ofstream oFile;
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\lista\\wyniki_d_p.txt");

                for (int l = 1000; l < 200000; l=l*2) {
                  //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            list2.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        countTime.timeStart();
                        list2.insertHead(num);
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                        for(int k=0; k<l+1; k++)
                        {
                            list2.removeHead();
                        }
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\lista\\wyniki_d_k.txt");

                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            srand(time(NULL)); // inicjalizacja generatora liczb
                            num = (int) rand() % (250000 - 1 + 1)+1;
                            list2.insertTail(num);
                        }
                        num = (int) rand()  % (250000 - 1 + 1)+1;
                        countTime.timeStart();
                        list2.insertTail(num);
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                        for(int k=0; k<l+1; k++)
                        {
                            list2.removeHead();
                        }
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();

                 */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\lista\\wyniki_d_d.txt");

                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            srand(time(NULL)); // inicjalizacja generatora liczb
                            num = (int) rand() % (250000 - 1 + 1)+1;
                            list2.insertTail(num);
                        }
                        //num = rand()  % l;
                        int a=0;
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(a, l-1);
                        int num = dist(gen);
                        //cout<<num<<endl;
                        countTime.timeStart();
                        list2.insert(69, num);
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                        for(int k=0; k<l+1; k++)
                        {
                            list2.removeHead();
                        }
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                 */
                /*

                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\lista\\wyniki_u_p.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            list2.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        countTime.timeStart();
                        list2.removeHead();
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();

                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\lista\\wyniki_u_k.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            list2.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        countTime.timeStart();
                        list2.removeTail();
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\lista\\wyniki_u_d.txt");
                for (int l = 1000; l < 2000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 25000);
                            int num = dist(gen);
                            list2.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        countTime.timeStart();
                        list2.remove(num);
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */

                oFile.open("wyniki_if.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 25000);
                            int num = dist(gen);
                            list2.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        countTime.timeStart();
                        list2.checkIfExist(num);
                        countTime.timeStop();
                        avg = avg + countTime.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();

                break;
        }
    }
}

void FileTests::ArrayTest() {
    srand(time(NULL));
    CountTime time;
    DynamicArray array;
    int choice = -100;
    int value, randNum, randIndex, findIndex;
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Z jakiego pliku chcesz wziac dane:  ";
    cin >> inputFileName;
    cout << "Plik z wynikami testu: ";
    cin >> outputFileName;

    inputFile.open( inputFileName);
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
    inputFile >> value;
    int size = value;

    while (inputFile >> value) {
        array.insertTail(value);
    }
    if(size != array.size){
        cout << "Ilosc elementow w pliku nie odpowiada zadeklarowanej wartosc!" << endl;
        return;
    }
    inputFile.close();
    //array.displayArray();

    while (choice != 0) {
        cout << "Co chcesz zrobic:" << endl;
        cout << "   1. Dodaj pierwszy element" << endl;
        cout << "   2. Dodaj ostatni element" << endl;
        cout << "   3. Dodaj element na dowolna pozycje" << endl;
        cout << "   4. Usun pierwszy element" << endl;
        cout << "   5. Usun ostatni element" << endl;
        cout << "   6. Usun dowolny element" << endl;
        cout << "   7. Sprawdz czy podany element istneje" << endl;
        cout << "   8. Wyswietl tablice" << endl;
        cout << "   9. Wykonaj wszystkie operacje automatycznie" << "\n";
        cout << "   0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
            default:
                cout << "Zle wybrales cyfre!" << endl;
                break;

            case 0:
                outputFile.close();
                break;

            case 1:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                array.insertHead(randNum);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                array.displayArray();
                break;

            case 2:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                array.insertTail(randNum);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                array.displayArray();
                break;

            case 3:
                cout << "Wartosc: ";
                cin >> randNum;
                cout << "Index: ";
                cin >> randIndex;
                time.timeStart();
                array.insert(randNum, randIndex);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                array.displayArray();
                break;

            case 4:
                time.timeStart();
                array.removeHead();
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                array.displayArray();
                break;

            case 5:
                time.timeStart();
                array.removeTail();
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                array.displayArray();
                break;

            case 6:
                cout << "Index: ";
                cin >> randIndex;
                time.timeStart();
                array.remove(randIndex);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                array.displayArray();
                break;

            case 7:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                findIndex = array.checkIfExist(randNum);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                if(findIndex!=-1){
                    cout << "Ten element znajduje sie w tablicy na pozycji o indeksie [" << findIndex << "]" << endl;
                }
                else cout << "Ten element nie znajduje sie w tablicy  " << endl;
                break;

            case 8:
                time.timeStart();
                array.displayArray();
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                break;
                //case 9 jest uzywany przy automatycznym testowaniu tablicy do wykonania wykresow
            case 9:
                int n=2, num, x=2;
                DynamicArray array1;
                long double avg=0;
                ofstream oFile;
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_d_p.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        array1.insertHead(num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                        for(int k=0; k<l+1; k++)
                        {
                            array1.removeHead();
                        }
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_d_k.txt");

                for (int l = 1000; l < 2000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        array1.insertTail(num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                        for(int k=0; k<l+1; k++)
                        {
                            array1.removeHead();
                        }
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                 */

                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_d_d.txt");

                for (int l = 1000; l < 1000000; l=l*2) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, l-1);
                        int num = dist(gen);
                        time.timeStart();
                        array1.insert(69, num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                        for(int k=0; k<l+1; k++)
                        {
                            array1.removeHead();
                        }
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_u_p.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        array1.removeHead();
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_u_k.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        array1.removeTail();
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */
                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_u_d.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 25000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        array1.remove(num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */

                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\tablica\\wyniki_if.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 25000);
                            int num = dist(gen);
                            array1.insertTail(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        array1.checkIfExist(num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();

                break;
        }
    }
}

void FileTests::BinaryHeapTest() {
    srand(time(NULL));
    CountTime time;
    BinaryHeap binaryHeap;
    int choice = -100;
    int value, randNum, randIndex, findIndex;
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Z jakiego pliku chcesz wziac dane:  ";
    cin >> inputFileName;
    cout << "Plik z wynikami testu: ";
    cin >> outputFileName;

    inputFile.open( inputFileName);
    outputFile.open( outputFileName, fstream::out);


    if (inputFile.is_open()) {
        cout << "Zawartosc otwartego pliku: " << inputFileName << endl;
    } else {
        cout << "Nie udalo sie otworzyc pliku " << endl;
        return;
    }
    inputFile >> value;
    int size = value;
    while (inputFile >> value) {
        binaryHeap.insert(value);
    }
    if(size != binaryHeap.size){
        cout << "Ilosc elementow w pliku nie odpowiada zadeklarowanej wartosc!" << endl;
        return;
    }
    inputFile.close();
    //binaryHeap.displayHeap();

    while (choice != 0) {
        cout << "Co chcesz zrobic:" << endl;
        cout << "    1. Dodaj wartosc do kopca" << endl;
        cout << "    2. Usun korzen" << endl;
        cout << "    3. Sprawdz czy wartosc istnieje" << endl;
        cout << "    4. Wyswietl kopiec binarny" << endl;
        cout << "    5. Wykonaj automatyczne testy" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
            default:
                cout << "Zle wybrales cyfre!" << endl;
                break;

            case 0:
                outputFile.close();
                break;

            case 1:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                binaryHeap.insert(randNum);
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                binaryHeap.displayHeap();
                break;

            case 2:
                time.timeStart();
                binaryHeap.deleteRoot();
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                binaryHeap.displayHeap();
                break;

            case 3:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                binaryHeap.checkIfExist(randNum);
                time.timeStop();
                if (binaryHeap.checkIfExist(randNum)!=-1) {
                    cout << "Ten element znajduje sie w kopcu " << endl;
                } else {
                    cout << "Ten element nie znajduje sie w kopcu " << endl;
                }
                cout << "Czas wykonania test: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                break;

            case 4:
                time.timeStart();
                binaryHeap.displayHeap();
                time.timeStop();
                cout << "Czas wykonania: " << time.workingTime() << "ns" << endl;
                outputFile << time.workingTime() <<endl;
                break;
                //case 5 uzywany jest przy automatycznych testach kopca do wykonania wykresow
            case 5:
                int n=2;
                BinaryHeap binaryHeap1;
                long double avg=0.0;
                ofstream oFile;
                /*
                 oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\kopiec\\wyniki_add.txt");
                 for (int l = 1000; l < 1000000; l=l*2) {
                   //  cout<<l<<endl;
                     for (int i = 0; i < n; i++) {
                         for (int j = 0; j < l; j++) {
                             random_device rd;
                             mt19937 gen(rd());
                             uniform_int_distribution<int> dist(0, 1000);
                             int num = dist(gen);
                             binaryHeap1.insert(num);
                         }
                         random_device rd;
                         mt19937 gen(rd());
                         uniform_int_distribution<int> dist(0, 1000);
                         int num = dist(gen);
                         time.timeStart();
                         binaryHeap1.insert(num);
                         time.timeStop();
                         avg = avg + time.workingTime();
                     }
                     avg = avg/n;
                     cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                     oFile <<avg<< "\n";
                 }
                 oFile.close();
                 */
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\kopiec\\wyniki_delete.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            binaryHeap1.insert(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        binaryHeap1.deleteRoot();
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();


                /*
               oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\kopiec\\wyniki_if.txt");
               for (int l = 1000; l < 1000000; l=l*2) {
                   for (int i = 0; i < n; i++) {
                       for (int j = 0; j < l; j++) {
                           random_device rd;
                           mt19937 gen(rd());
                           uniform_int_distribution<int> dist(0, 25000);
                           int num = dist(gen);
                           binaryHeap1.insert(num);
                       }
                       random_device rd;
                       mt19937 gen(rd());
                       uniform_int_distribution<int> dist(0, 1000);
                       int num = dist(gen);
                       time.timeStart();
                       binaryHeap1.checkIfExist(num);
                       time.timeStop();
                       avg = avg + time.workingTime();
                   }
                   avg = avg/n;
                   cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                   oFile <<avg<< "\n";
               }
               oFile.close();
                 */

                break;
        }
    }
}
void FileTests::RedBlackTreeTest() {
    CountTime time;
    RedAndBlackTree tree;
    int choice = -100, value, randNum;
    NodePtr nodePtr;
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Z jakiego pliky chcesz wziac dane:  ";
    cin >> inputFileName;
    cout << "Plik z wynikami testu: ";
    cin >> outputFileName;

    inputFile.open( inputFileName);
    outputFile.open( outputFileName, fstream::out);


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
    inputFile >> value;
    int size = value;
    while (inputFile >> value) {
        tree.insert(value);
    }
    if(size != tree.size){
        cout << "Ilosc elementow w pliku nie odpowiada zadeklarowanej wartosc!" << endl;
        return;
    }
    inputFile.close();
    //tree.printTree();

    while (choice != 0) {
        cout << "Co chcesz zrobic:" << endl;
        cout << "    1. Dodaj wartosc" << endl;
        cout << "    2. Usun wartosc" << endl;
        cout << "    3. Sprawdz czy podana wartosc istnieje " << endl;
        cout << "    4. Wypisz drzewo czerwono-czarne" << endl;
        cout << "    5. Wykonaj testy automatycznie" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
            default:
                cout << "Zle wybrales cyfre!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                tree.insert(randNum);
                time.timeStop();
                cout << "Czas wykonywania: " << time.workingTime() << "ns" << endl;
                tree.printTree();
                break;

            case 2:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                tree.deleteNode(randNum);
                time.timeStop();
                cout << "Czas wykonywania: " << time.workingTime() << "ns" << endl;
                tree.printTree();
                break;

            case 3:
                cout << "Wartosc: ";
                cin >> randNum;
                time.timeStart();
                nodePtr = tree.searchTree(randNum);
                time.timeStop();
                if (nodePtr != nullptr) {
                    cout << "Podany element istnieje w drzewie czerwono-czarnym " << endl;
                } else {
                    cout << "Podany element nie istnieje w drzewie czerwono-czarnym " << endl;
                }
                cout << "Czas wykonywania: " << time.workingTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                tree.printTree();
                time.timeStop();
                cout << endl;
                cout << "Czas wykonywania: " << time.workingTime() << "ns" << endl;
                break;
                //case 5 uzuwany jest przy automatycznych testach drzewa do wykonania wykresow
            case 5:
                int n=20;
                RedAndBlackTree tree1;
                long double avg=0.0;
                ofstream oFile;

                /*
                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\drzewo\\wyniki_add.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 1000);
                            int num = dist(gen);
                            tree1.insert(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        tree1.insert(num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                */


               oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\drzewo\\wyniki_delete.txt");
               for (int l = 1000; l < 1000000; l=l*2) {
                   //  cout<<l<<endl;
                   for (int i = 0; i < n; i++) {
                       for (int j = 0; j < l; j++) {
                           random_device rd;
                           mt19937 gen(rd());
                           uniform_int_distribution<int> dist(0, 1000);
                           int num = dist(gen);
                           tree1.insert(num);
                       }
                       random_device rd;
                       mt19937 gen(rd());
                       uniform_int_distribution<int> dist(0, 1000);
                       int num = dist(gen);
                       time.timeStart();
                       tree1.deleteNode(num);
                       time.timeStop();
                       avg = avg + time.workingTime();
                   }
                   avg = avg/n;
                   cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                   oFile <<avg<< "\n";
               }
               oFile.close();

                oFile.open("C:\\Users\\Joanna\\Desktop\\Sdizo1\\pliki wyjsciowe\\drzewo\\wyniki_if.txt");
                for (int l = 1000; l < 1000000; l=l*2) {
                    //  cout<<l<<endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<int> dist(0, 25000);
                            int num = dist(gen);
                            tree1.insert(num);
                        }
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> dist(0, 1000);
                        int num = dist(gen);
                        time.timeStart();
                        tree1.searchTree(num);
                        time.timeStop();
                        avg = avg + time.workingTime();
                    }
                    avg = avg/n;
                    cout<<"l: "<<l<<" srednia po podzieleniu: "<<avg<<endl;
                    oFile <<avg<< "\n";
                }
                oFile.close();
                break;

        }
    }
}
