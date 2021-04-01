//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_HEAP_H
#define DATASTRUCTURES_HEAP_H

#include <iostream>
#include <math.h>

class Heap {
    int size = 0;
    int *items = nullptr;
    int *items_new = nullptr;
public:
    Heap() {
        string amount;
        string element;
        fstream file;
        file.open("data.txt", ios::in);

        if (!file.good()) {
            cout << "File data.txt does not exist !" << endl;
        }
        getline(file, amount);

        items = new int[(atoi(amount.c_str()))];

        size = atoi(amount.c_str());
        for (int i = 0; i < size; i++) {
            getline(file, element);
            items[i] = atoi(element.c_str());
        }
        create_max_heap(size);
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
    bool has_right_child(int index) {
        return get_right_child_index(index) < size;
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

        while ((parent(index) < items[index]) && has_parent(index)) {
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
        bool not_terminate = true;

        while (has_left_child(index) && not_terminate) {
            if(left_child(index) > right_child(index)){
                swap(index, get_left_child_index(index));
                index = get_left_child_index(index);
            }else if(left_child(index) < right_child(index)){
                swap(index, get_right_child_index(index));
                index = get_right_child_index(index);
            }
            else if(left_child(index) == right_child(index) && items[index] < left_child(index)){
                swap(index, get_left_child_index(index));
                index = get_left_child_index(index);
            }
            else {
                not_terminate = false;
            }
        }

    }

public:
    int *create_arr(int size) {
        int *arr = new int[size];
        return arr;
    }

public:
    void remove(int index) {

        if (size > 0) {
            size--;
            items_new = create_arr(size);

            for (int i = 0; i < index; i++) {
                items_new[i] = items[i];
            }
            items_new[index] = items[size];

            for (int i = index + 1; i < size; i++) {
                items_new[i] = items[i];
            }
            delete[]items;
            items = nullptr;
            items = items_new;
            items_new = nullptr;
            delete[] items_new;

            heapify_down(index);
        }



    }

public:
    void show() {
        for (int i = 0; i < size; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }


};


#endif //DATASTRUCTURES_HEAP_H
