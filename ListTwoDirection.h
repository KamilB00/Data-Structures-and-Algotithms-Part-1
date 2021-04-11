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
    int list_size = 0;
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

        list_size = atoi(amount.c_str());
        for (int i = 0; i < atoi(amount.c_str()); i++) {
            getline(file, element);
           fillTheList(atoi(element.c_str()));
        }
        cout<<"List filled with data !"<<endl;
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

        int times = 0;

        Element *n = new Element(d);

        if (size == 0) { // no element in the List
            last = first = n;

        } else if (index == 0) { // addin at the beginning
            cout << "How many times should time be measured : ";
            cin >> times;
            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now(); //START [LIST ADD VALUE AT INDEX 0]

                first->prev = n;
                n->next = first;
                first = n;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

                timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_LINKEDLIST_BEGINNING");
                timer->showAvgTime("ADD_TO_LINKEDLIST_BEGINNING");
            }

        } else if (index == size) { //adding  at the end
            cout << "How many times should time be measured : ";
            cin >> times;
            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now(); //START [LIST ADD VALUE AT THE END]

                last->next = n;
                n->prev = last;
                last = n;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

                timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_LINKEDLIST_END");
                timer->showAvgTime("ADD_TO_LINKEDLIST_END");
            }

        } else {

            Element *temp = getPosition(index);
            Element *before = temp->prev;
            cout << "How many times should time be measured : ";
            cin >> times;
            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now(); //START [LIST ADD VALUE IN THE MIDDLE]
                before->next = n;
                temp->prev = n;
                n->next = temp;
                n->prev = before;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

                timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_LINKEDLIST_MIDDLE");
                timer->showAvgTime("ADD_TO_LINKEDLIST_MIDDLE");
            }
        }
        size++;
    }

    void fillTheList(int d){
        Element *n = new Element(d);
        if (size == 0) { // no element in the List
            last = first = n;
            size++;
        }else {
            last->next = n;
            n->prev = last;
            last = n;
            size++;
        }
    }

    void remove(unsigned long long int index) {

        int times = 0;

        if (index > size || index < 0) {
            cout << "Incorrect index !" << endl;
        } else if (index > 0 && index < size - 1) { //usuwanie ze środka


            Element *temp = getPosition(index);
            cout << "How many times should time be measured : ";
            cin >> times;
            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now(); //START [LIST REMOVE VALUE FROM MIDDLE]
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;


                size--;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

                timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_LINKEDLIST_MIDDLE");
                timer->showAvgTime("REMOVE_FROM_LINKEDLIST_MIDDLE");
            }
            delete temp;
        } else if (index == 0) { // deleting from index 0


            Element *temp = first;
            auto start = std::chrono::steady_clock::now(); //START [LIST REMOVE VALUE FROM INDEX 0]
            cout << "How many times should time be measured : ";
            cin >> times;
            for (int i = 0; i < times; i++) {
                if (size > 1) {
                    first = temp->next;
                    first->prev = nullptr;
                    size--;
                } else {
                    first = nullptr;
                    last = nullptr;
                    size--;
                }
                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_LINKEDLIST_BEGINNING");
                timer->showAvgTime("REMOVE_FROM_LINKEDLIST_BEGINNING");
            }
            delete temp;

        } else if (index == size - 1) { //deleting from last index

            Element *temp = last;
            cout << "How many times should time be measured : ";
            cin >> times;

            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now(); //START [LIST REMOVE VALUE LAST]
                last = last->prev;
                last->next = nullptr;
                size--;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_LINKEDLIST_END");
                timer->showAvgTime("REMOVE_FROM_LINKEDLIST_END");
            }
            delete temp;
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
        int times = 0;

        int value = 0;
        Element *temp = first;
        cout << "Value you are looking for: ";
        cin >> value;
        int found = 0;
        cout << "How many times should time be measured : ";
        cin >> times;
        for (int i = 0; i < times; i++) {
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
    }

public :
    void find(int index) {
        int times = 0;
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
        cout << "How many times should time be measured : ";
        cin >> times;
        for (int i = 0; i < times; i++) {
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
    }

};


#endif //DATASTRUCTURES_LISTTWODIRECTION_H
