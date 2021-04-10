//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_ARRAY_H
#define DATASTRUCTURES_ARRAY_H
#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>
#include "Timer.h"

using namespace std;

class Array {
public:
    int size = 0;
    int *arr_dyn = nullptr;
    int *arr_dyn_new = nullptr;

    Timer* timer = timer->getInstance();


public:
    Array() {


        string amount;
        string element;
        fstream file;
        file.open("data.txt", ios::in);

        if (!file.good()) {
            cout << "File data.txt does not exist !" << endl;
        }
        getline(file, amount);

        arr_dyn = create(atoi(amount.c_str()));
        size = atoi(amount.c_str());
        for (int i = 0; i < size; i++) {
            getline(file, element);
            arr_dyn[i] = atoi(element.c_str());
        }
    }

    int *create(int size) {
        int *arr = new int[size];
        return arr;
    }

    void add(int index) {

        int value = 0;
        int temp = 0;

        //adding element at the beginning
        if (index == 0) {
            size++;

            arr_dyn_new = create(size);

            cout << "array[" << index << "] = ";
            cin >> value;
            auto start = std::chrono::steady_clock::now(); // START [ARRAY ADD AT INDEX 0]
            arr_dyn_new[0] = value;

            for (int i = 0; i < size; i++) {
                temp = arr_dyn[i];
                arr_dyn_new[i + 1] = temp;
            }

            arr_dyn = nullptr;
            delete[] arr_dyn;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = nullptr;
            delete[] arr_dyn_new;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            cout << "elapsed time [Array add at index 0]: " << elapsed_time << " ns"
                 << endl; //END [ARRAY ADD AT INDEX 0]

        }

            //adding element in the middle
        else if (index <= size - 1 && index > 0) {
            temp = 0;
            size++;
            arr_dyn_new = create(size);

            cout << "array[" << index << "] = ";
            cin >> value;
            auto start = std::chrono::steady_clock::now();// START [ARRAY ADD TO MIDDLE]

            for (int i = 0; i < index; i++) {

                arr_dyn_new[i] = arr_dyn[i];
            }
            arr_dyn_new[index] = value;

            for (int i = index; i < size; i++) {
                temp = arr_dyn[i];
                arr_dyn_new[i + 1] = temp;
            }

            delete[] arr_dyn;
            arr_dyn = nullptr;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = nullptr;
            delete[] arr_dyn_new;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            cout << "elapsed time [Array add to middle]: " << elapsed_time << " ns"
                 << endl;//END [ARRAY ADD TO MIDDLE]
        }


    }

    void add() {
        int value = 0;
        size++;
        arr_dyn_new = create(size);

        cout << "array[" << size - 1 << "] = ";
        cin >> value;

        //adding element at the end,   SIZE == ELEMENTS

        auto start = std::chrono::steady_clock::now(); //START [ARRAY ADD TO END]
        for (int i = 0; i < size - 1; i++) {
            arr_dyn_new[i] = arr_dyn[i];
        }

        arr_dyn_new[size - 1] = value;

        delete[]arr_dyn;
        arr_dyn = nullptr;
        arr_dyn = arr_dyn_new;
        arr_dyn_new = nullptr;
        delete[] arr_dyn_new;

        auto end = std::chrono::steady_clock::now();
        double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        timer->addToArrayList_Beginning(elapsed_time,"ADD_TO_ARRAYLIST_BEGINNING");
        timer->showAvgTime("ADD_TO_ARRAYLIST_BEGINNING");

    }

    void remove(int index) {
        // remove from the beginning
        if (size > 0) {
            if (index == 0) {

                auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM BEGINNING]
                size--;
                arr_dyn_new = create(size);
                for (int i = 1; i < size; i++) {
                    arr_dyn_new[i - 1] = arr_dyn[i];
                }
                delete[]arr_dyn;
                arr_dyn = nullptr;
                arr_dyn = arr_dyn_new;
                arr_dyn_new = nullptr;
                delete[] arr_dyn_new;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                cout << "elapsed time [Array remove from beginning]: " << elapsed_time << " ns"
                     << endl; //END [ARRAY REMOVE FROM BEGINNING]

            }
                //remove in the middle
            else if (index <= size - 1 && index > 0) {
                auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM MIDDLE]
                size--;
                arr_dyn_new = create(size);
                for (int i = 0; i < index; i++) {
                    arr_dyn_new[i] = arr_dyn[i];
                }
                for (int i = index; i < size; i++) {
                    arr_dyn_new[i] = arr_dyn[i + 1];
                }

                delete[]arr_dyn;
                arr_dyn = nullptr;
                arr_dyn = arr_dyn_new;
                arr_dyn_new = nullptr;
                delete[] arr_dyn_new;

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                cout << "elapsed time [Array remove from middle]: " << elapsed_time << " ns"
                     << endl; //END [ARRAY REMOVE FROM MIDDLE]
            }
        } else {
            cout << "Array is empty !" << endl;
        }
    }

    // remove from the end
    void remove() {
        if (size > 0) {
            auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM END]
            size--;
            arr_dyn_new = create(size); //size =4
            for (int i = 0; i < size; i++) {
                arr_dyn_new[i] = arr_dyn[i];
            }
            delete[]arr_dyn;
            arr_dyn = nullptr;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = nullptr;
            delete[] arr_dyn_new;
            cout << "Element deleted !" << endl;
            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            cout << "elapsed time [Array remove from end]: " << elapsed_time << " ns"
                 << endl; //END [ARRAY REMOVE FROM END]

        } else {
            cout << "Array is empty !" << endl;
        }
    }

    void find(int index) {
        if (size > index && index >= 0) {
            auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM END]
            cout << "Element at index " << index << " found: array[" << index << "] = " << arr_dyn[index] << endl;
            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            cout << "elapsed time [Array find by index]: " << elapsed_time << " ns"
                 << endl; //END [ARRAY FIND BY INDEX]

        } else {
            cout << "No element with the index " << index << " found !" << endl;
        }

    }

    void find() {
        int value = 0;
        int present = 0;
        cout << "Number in array you are looking for: ";
        cin >> value;
        auto start = std::chrono::steady_clock::now(); //START [ARRAY FIND BY VALUE]

        for (int i = 0; i < size; i++) {
            if (arr_dyn[i] == value) {
                present++;
            }
        }
        if (present != 0) {
            cout << value << " found in the array" << endl;
        } else {
            cout << "There is no such value in this array" << endl;
        }

        auto end = std::chrono::steady_clock::now();
        long double elapsed_time = (long double) (std::chrono::duration_cast<std::chrono::nanoseconds>(
                end - start).count());

        cout << "elapsed time [Array find by value]: " << (long double) (elapsed_time) << " ns"
             << endl; //END [ARRAY FIND BY VALUE]
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << endl;
            cout << "array[" << i << "] = " << arr_dyn[i] << endl;
        }
    }

};


#endif //DATASTRUCTURES_ARRAY_H
