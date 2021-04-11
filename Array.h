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
    Array(const string& file_name) {


        string amount;
        string element;
        fstream file;
        file.open(file_name, ios::in);

        cout<<"ARRAY file_name -> "<<file_name<<endl;

        if (!file.good()) {
            cout << "File "<<file_name<<".txt does not exist !" << endl;
        }
        else {
            getline(file, amount);

            arr_dyn = create(atoi(amount.c_str()));
            size = atoi(amount.c_str());
            for (int i = 0; i < size; i++) {
                getline(file, element);
                arr_dyn[i] = atoi(element.c_str());
            }
        }
    }

    int *create(int size) {
        int *arr = new int[size];
        return arr;
    }

    void add(int index) {
int times = 0;
        int value = 0;
        int temp = 0;

        //adding element at the beginning
        if (index == 0) {
            size++;

            arr_dyn_new = create(size);
            cout << "How many times should time be measured : ";
            cin >> times;

            cout << "array[" << index << "] = ";
            cin >> value;
            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now(); // START [ARRAY ADD AT INDEX 0]
                arr_dyn_new[0] = value;

                for (int i = 0; i < size; i++) {
                    temp = arr_dyn[i];
                    arr_dyn_new[i + 1] = temp;
                }

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

                timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_ARRAYLIST_BEGINNING");
                timer->showAvgTime("ADD_TO_ARRAYLIST_BEGINNING");
            }
            arr_dyn = nullptr;
            delete[] arr_dyn;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = nullptr;
            delete[] arr_dyn_new;
        }

            //adding element in the middle
        else if (index <= size - 1 && index > 0) {
            temp = 0;

            size++;
            arr_dyn_new = create(size);

            cout << "How many times should time be measured : ";
            cin >> times;

            cout << "array[" << index << "] = ";
            cin >> value;
            for (int i = 0; i < times; i++) {
                auto start = std::chrono::steady_clock::now();// START [ARRAY ADD TO MIDDLE]

                for (int i = 0; i < index; i++) {

                    arr_dyn_new[i] = arr_dyn[i];
                }
                arr_dyn_new[index] = value;

                for (int i = index; i < size; i++) {
                    temp = arr_dyn[i];
                    arr_dyn_new[i + 1] = temp;
                }

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_ARRAYLIST_MIDDLE");
                timer->showAvgTime("ADD_TO_ARRAYLIST_MIDDLE");
            }
            delete[] arr_dyn;
            arr_dyn = nullptr;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = nullptr;
            delete[] arr_dyn_new;
        }


    }

    void add() {
        int value = 0;
        int times = 0;
        size++;
        arr_dyn_new = create(size);
        cout<<"How many times should time be measured : ";
        cin>>times;
        cout << "array[" << size - 1 << "] = ";
        cin >> value;

        //adding element at the end,   SIZE == ELEMENTS
        for(int i=0;i<times;i++) {
            auto start = std::chrono::steady_clock::now(); //START [ARRAY ADD TO END]
            for (int i = 0; i < size - 1; i++) {
                arr_dyn_new[i] = arr_dyn[i];
            }

            arr_dyn_new[size - 1] = value;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_ARRAYLIST_END");
            timer->showAvgTime("ADD_TO_ARRAYLIST_END");
        }

        delete[]arr_dyn;
        arr_dyn = nullptr;
        arr_dyn = arr_dyn_new;
        arr_dyn_new = nullptr;
        delete[] arr_dyn_new;
    }

    void remove(int index) {
        // remove from the beginning
        int times =0;
        if (size > 0) {
            if (index == 0) {

                size--;
                arr_dyn_new = create(size);
                cout<<"How many times should time be measured : ";
                cin>>times;
                for(int i=0;i<times;i++) {
                    auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM BEGINNING]
                    for (int i = 1; i < size; i++) {
                        arr_dyn_new[i - 1] = arr_dyn[i];
                    }

                    auto end = std::chrono::steady_clock::now();
                    double elapsed_time = double(
                            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                    timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_ARRAYLIST_BEGINNING");
                    timer->showAvgTime("REMOVE_FROM_ARRAYLIST_BEGINNING");
                }
                delete[]arr_dyn;
                arr_dyn = nullptr;
                arr_dyn = arr_dyn_new;
                arr_dyn_new = nullptr;
                delete[] arr_dyn_new;

            }
                //remove in the middle
            else if (index <= size - 1 && index > 0) {

                size--;
                arr_dyn_new = create(size);
                cout<<"How many times should time be measured : ";
                cin>>times;
                for(int i=0;i<times;i++) {
                    auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM MIDDLE]
                    for (int i = 0; i < index; i++) {
                        arr_dyn_new[i] = arr_dyn[i];
                    }
                    for (int i = index; i < size; i++) {
                        arr_dyn_new[i] = arr_dyn[i + 1];
                    }

                    auto end = std::chrono::steady_clock::now();
                    double elapsed_time = double(
                            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                    timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_ARRAYLIST_MIDDLE");
                    timer->showAvgTime("REMOVE_FROM_ARRAYLIST_MIDDLE");
                }

                delete[]arr_dyn;
                arr_dyn = nullptr;
                arr_dyn = arr_dyn_new;
                arr_dyn_new = nullptr;
                delete[] arr_dyn_new;
            }
        } else {
            cout << "Array is empty !" << endl;
        }
    }

    // remove from the end
    void remove() {
        if (size > 0) {
            int times =0;
            size--;
            arr_dyn_new = create(size); //size =4

            cout<<"How many times should time be measured : ";
            cin>>times;
            for(int i =0;i<times;i++) {
                auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM END]
                for (int i = 0; i < size; i++) {
                    arr_dyn_new[i] = arr_dyn[i];
                }

                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_ARRAYLIST_END");
                timer->showAvgTime("REMOVE_FROM_ARRAYLIST_END");
            }
            delete[]arr_dyn;
            arr_dyn = nullptr;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = nullptr;
            delete[] arr_dyn_new;
            cout << "Element deleted !" << endl;

        } else {
            cout << "Array is empty !" << endl;
        }
    }

    void find(int index) {
        int times = 0;
        if (size > index && index >= 0) {
            cout<<"How many times should time be measured : ";
            cin>>times;
            for(int i =0;i<times;i++) {
                auto start = std::chrono::steady_clock::now(); //START [ARRAY REMOVE FROM END]
                cout << "Element at index " << index << " found: array[" << index << "] = " << arr_dyn[index] << endl;
                auto end = std::chrono::steady_clock::now();
                double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_ARRAYLIST_BY_INDEX");
                timer->showAvgTime("FIND_IN_ARRAYLIST_BY_INDEX");
            }
        } else {
            cout << "No element with the index " << index << " found !" << endl;
        }

    }

    void find() {
        int value = 0;

        int times = 0;
        cout << "Number in array you are looking for: ";
        cin >> value;
        cout<<"How many times should time be measured : ";
        cin>>times;
        for(int i =0;i<times;i++) {
            int present = 0;
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
            double elapsed_time = (double) (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_ARRAYLIST_BY_VALUE");
            timer->showAvgTime("FIND_IN_ARRAYLIST_BY_VALUE");
        }
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << endl;
            cout << "array[" << i << "] = " << arr_dyn[i] << endl;
        }
    }

};


#endif //DATASTRUCTURES_ARRAY_H
