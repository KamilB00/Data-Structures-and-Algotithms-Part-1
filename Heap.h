//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_HEAP_H
#define DATASTRUCTURES_HEAP_H

#include <iostream>
#include <cmath>


class Heap {
    int size = 0;
    int *items = nullptr;
    int *items_new = nullptr;

    Timer *timer = timer->getInstance();

public:
    Heap(const string &file_name) {
        string amount;
        string element;
        fstream file;

        file.open(file_name, ios::in);

        if (!file.good()) {
            cout << "File "<<file_name<<" does not exist !" << endl;
        }else {

            getline(file, amount);
            items = new int[(atoi(amount.c_str()))];

            size = atoi(amount.c_str());
            for (int i = 0; i < size; i++) {
                getline(file, element);
                items[i] = atoi(element.c_str());
            }
            create_max_heap(size);
        }
    }

public:
    int get_parent_index(int child_index) {
        return (int) ceil((child_index - 2) / 2.0);
    }

public:
    int get_left_child_index(int index) {
        return (index * 2) + 1;
    }

public:
    int get_right_child_index(int index) {
        return (index * 2) + 2;
    }

public:
    bool has_parent(int index) {
        return get_parent_index(index) >= 0;
    }

public:
    bool has_left_child(int index) {
        return get_left_child_index(index) < size;
    }

public:
    int parent(int index) {
        return items[get_parent_index(index)];
    }

public:
    int left_child(int index) {
        return items[get_left_child_index(index)];
    }

public:
    int right_child(int index) {
        return items[get_right_child_index(index)];
    }

public:
    void swap(int parent_index, int child_index) {
        int temp = 0;
        temp = items[parent_index];
        items[parent_index] = items[child_index];
        items[child_index] = temp;

        cout << "Swaped parent index " << parent_index << " with child index " << child_index << endl;
    }

public:
    void heapify_up(int index) {

        while ((parent(index) < items[index]) && get_parent_index(index) >= 0) {
            swap(get_parent_index(index), index);
            index = get_parent_index(index);
        }
    }

public:
    void create_max_heap(int size) {

        for (int i = 0; i < size; i++) {
            heapify_up(i);
        }

    }

public:
    void heapify_down(int index) {
        bool terminate = false;

        while (has_left_child(index) && !terminate) {
            if (left_child(index) > right_child(index)) {
                swap(index, get_left_child_index(index));
                index = get_left_child_index(index);
            } else if (left_child(index) < right_child(index)) {
                swap(index, get_right_child_index(index));
                index = get_right_child_index(index);
            } else if (left_child(index) == right_child(index)) {
                swap(index, get_left_child_index(index));
                index = get_left_child_index(index);
            } else {
                terminate = true;
            }
        }
    }

public:
    int *create_arr(int size) {
        int *arr = new int[size];
        return arr;
    }

public:
    int get_size() {
        this->size = size;
        return size;
    }

public:
    void remove(int index) {
        int times = 0;

        if (index < size && index >= 0) {
            if (size > 0) {
                size--;
                items_new = create_arr(size);
                cout << "How many times should time be measured : ";
                cin >> times;
                for (int i = 0; i < times; i++) {
                    auto start = std::chrono::steady_clock::now();// START [HEAP REMOVE]
                    for (int j = 0; j < index; j++) {
                        items_new[j] = items[j];
                    }
                    items_new[index] = items[size];

                    for (int k = index + 1; k < size; k++) {
                        items_new[k] = items[k];
                    }
                    delete[]items;
                    items = items_new;

                    heapify_down(index);

                    auto end = std::chrono::steady_clock::now();
                    double elapsed_time = double(
                            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
                    timer->calculate_average_elapsed_time(elapsed_time, "REMOVE_FROM_HEAP");
                    timer->showAvgTime("REMOVE_FROM_HEAP");
                }



                cout << "heap[" << index << "] has been removed !" << endl;
            } else {
                cout << "Heap is empty !" << endl;
            }
        } else {
            cout << "No index found !" << endl;
        }

    }

public:
    void add() {
        int times = 0;
        int value = 0;
        size++;
        items_new = create_arr(size);

        cout << "heap.add(" << size - 1 << ") = ";
        cin >> value;


        cout << "How many times should time be measured : ";
        cin >> times;
        for (int i = 0; i < times; i++) {
            auto start = std::chrono::steady_clock::now();// START [HEAP ADD]

            for (int i = 0; i < size - 1; i++) {
                items_new[i] = items[i];
            }
            items_new[size - 1] = value;

            delete[]items;
            items = items_new;


            heapify_up(size - 1);

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            timer->calculate_average_elapsed_time(elapsed_time, "ADD_TO_HEAP");
            timer->showAvgTime("ADD_TO_HEAP");
        }

    }

public:
    void find() {
        int times = 0;

        int value = 0;
        int present = 0;
        cout << "Number you are looking for :" << endl;
        cin >> value;
        cout << "How many times should time be measured : ";
        cin >> times;
        for (int i = 0; i < times; i++) {
            auto start = std::chrono::steady_clock::now();// START [HEAP FIND BY VALUE]
            for (int i = 0; i < size; i++) {
                if (items[i] == value) {
                    present++;
                }
            }
            if (present > 0) {
                cout << "Number " << value << " is in the heap" << endl;
            } else {
                cout << "Number was not found" << endl;
            }
            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_HEAP_BY_VALUE");
            timer->showAvgTime("FIND_IN_HEAP_BY_VALUE");
        }
    }

public:
    void find(int index) {
       int times = 0;
        cout << "How many times should time be measured : ";
        cin >> times;
        for (int i = 0; i < times; i++) {
            auto start = std::chrono::steady_clock::now();// START [HEAP FIND BY INDEX]
            if (index >= 0 && index < size) {
                cout << "Number at index " << index << " : " << items[index] << endl;
            } else {
                cout << "There is no such index" << endl;
            }

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_HEAP_BY_INDEX");
            timer->showAvgTime("FIND_IN_HEAP_BY_INDEX");
        }
    }

public:
    void show() {
        if (size > 0) {
            for (int i = 0; i < size; i++) {
                cout << "heap [" << i << "] : " << items[i] << endl;
            }
            cout << endl;
        }else{
            cout<<"Heap is empty !"<<endl;
        }
    }

};


#endif //DATASTRUCTURES_HEAP_H
