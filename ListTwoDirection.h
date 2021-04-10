//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_LISTTWODIRECTION_H
#define DATASTRUCTURES_LISTTWODIRECTION_H

#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>

using namespace std;

class Element {

public:
    int data = 0;
    Element *next = nullptr;
    Element *prev = nullptr;

    Element(int d) {
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class ListTwoDirection {

    Timer *timer = timer->getInstance();

    int size = 0;

public:
    int get_size() {
        this->size = size;
        return size;
    }


    Element *first = nullptr;
    Element *last = nullptr;

    Element *getPosition(unsigned long long int index) { //pozycja numerowna od 0
        Element *temp = first;
        unsigned long long int pos = index;
        int i = 0;

        if (index < 0 || index > size) {
            return nullptr;
        } else {
            while (i++ < pos) {
                temp = temp->next;
            }
            return temp;
        }

    }

    ListTwoDirection() {
        string amount;
        string element;
        fstream file;
        file.open("data.txt", ios::in);

        if (!file.good()) {
            cout << "File data.txt does not exist !" << endl;
        }
        getline(file, amount);


        for (int i = 0; i < atoi(amount.c_str()); i++) {
            getline(file, element);
            add(atoi(element.c_str()), i);
        }
    }

public:
    void show() {
        Element *temp = first;
        int i = 0;
        if (temp != nullptr) {
            while (temp != nullptr) {
                cout << i++ << ". " << temp->data << endl;
                temp = temp->next;
            }
            cout << "size: " << size << endl;
            cout << "First: " << first->data << endl;
            cout << "Last: " << last->data << endl;
        } else {
            cout << "The List is Empty" << endl;
        }
    }

public:
    void add(int d, unsigned long long int index) {


        Element *n = new Element(d);

        if (size == 0) { // nie ma ani jednego elementu
            last = first = n;

        } else if (index == 0) { // na początek

            auto start = std::chrono::steady_clock::now(); //START [LIST ADD VALUE AT INDEX 0]

            first->prev = n;
            n->next = first;
            first = n;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_LINKEDLIST_BEGINNING");
            timer->showAvgTime("ADD_TO_LINKEDLIST_BEGINNING");

        } else if (index == size) { // na końcu
            auto start = std::chrono::steady_clock::now(); //START [LIST ADD VALUE AT THE END]

            last->next = n;
            n->prev = last;
            last = n;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_LINKEDLIST_END");
            timer->showAvgTime("ADD_TO_LINKEDLIST_END");

        } else {
            auto start = std::chrono::steady_clock::now(); //START [LIST ADD VALUE IN THE END]

            Element *temp = getPosition(index);
            Element *before = temp->prev;

            before->next = n;
            temp->prev = n;
            n->next = temp;
            n->prev = before;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_LINKEDLIST_MIDDLE");
            timer->showAvgTime("ADD_TO_LINKEDLIST_MIDDLE");
        }
        size++;
    }

    void remove(unsigned long long int index) {
        auto start = std::chrono::steady_clock::now(); //START [LIST REMOVE VALUE FROM MIDDLE]

        if (index > size || index < 0) {
            cout << "Incorrect index !" << endl;
        } else if (index > 0 && index < size - 1) { //usuwanie ze środka
            Element *temp = getPosition(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;

            size--;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_LINKEDLIST_MIDDLE");
            timer->showAvgTime("REMOVE_FROM_LINKEDLIST_MIDDLE");

        } else if (index == 0) { // deleting from index 0
            auto start = std::chrono::steady_clock::now(); //START [LIST REMOVE VALUE FROM INDEX 0]
            Element *temp = first;
            if (size > 1) {
                first = temp->next;
                first->prev = nullptr;
                delete temp;
                size--;
            } else {
                first = nullptr;
                last = nullptr;
                delete temp;
                size--;
            }
                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_LINKEDLIST_BEGINNING");
                timer->showAvgTime("REMOVE_FROM_LINKEDLIST_BEGINNING");

        } else if (index == size - 1) { //deleting from last index
            auto start = std::chrono::steady_clock::now(); //START [LIST REMOVE VALUE LAST]

            Element *temp = last;
            last = last->prev;
            last->next = nullptr;
            delete temp;
            size--;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_LINKEDLIST_END");
            timer->showAvgTime("REMOVE_FROM_LINKEDLIST_END");
        }
        cout << "Element on the position with index: " << index << " has been deleted" << endl;

    }

public:
    void removeAll() {
        int i = size - 1;
        while (i >= 0) {
            remove(i);
            i--;
        }
    }

public:
    void find() { // find by value


        int value = 0;
        Element *temp = first;
        cout << "Value you are looking for: ";
        cin >> value;
        int found = 0;

        auto start = std::chrono::steady_clock::now(); //START [LIST FIND BY VALUE]
        do {

            if (temp->data == value) {
                cout << "Value " << value << " found in the list" << endl;
                found++;
            } else {

                temp = temp->next;
            }

        } while ((found == 0) && (temp != nullptr));

        if (found == 0) {
            cout << "Value " << value << " was not found in the list " << endl;
        }

        auto end = std::chrono::steady_clock::now();
        double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_LINKEDLIST_BY_VALUE");
        timer->showAvgTime("FIND_IN_LINKEDLIST_BY_VALUE");
    }

public :
    void find(int index) {

        int visit_count = 0;
        Element *temp = first;

        if (visit_count > 0) {
            do {
                cout << "Value index: ";
                cin >> index;
                if (index < 0 || index > size) {
                    cout << "Incorrect index ! Try again" << endl;
                }
            } while (index > size || index < 0);
        }

        auto start = std::chrono::steady_clock::now(); //START [LIST VALUE BY INDEX]

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        cout << "List value at index " << index << " = " << temp->data << endl;

        auto end = std::chrono::steady_clock::now();
        double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_LINKEDLIST_BY_INDEX");
        timer->showAvgTime("FIND_IN_LINKEDLIST_BY_INDEX");
    }

};


#endif //DATASTRUCTURES_LISTTWODIRECTION_H
