//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_HEAP_H
#define DATASTRUCTURES_HEAP_H

#include <iostream>
#include <math.h>

class Heap {
    int size = 10;
    //int *items  = new int [size];
    int items[10] = {1,2,8,4,7,7,1,20,14,3};

public:
    int get_parent_index(int child_index) {
        return  (int) ceil((child_index - 2) / 2.0);
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

        cout<<"Swaped parent index "<<parent_index<<" with child index "<<child_index<<endl;
    }

public:
    void heapify_up(int index) {

        while ((parent(index) < items[index]) && has_parent(index)) {
            swap(get_parent_index(index), index);
            index = get_parent_index(index);
        }
    }
public:
    void create_max_heap(int size){
        int sum = 0;
        int p = 0;

        while(sum < size){
            sum += pow(2,p);
            p++;
        }

        sum -= pow(2,p-1);
       for(int i=sum; i<size;i++){
           heapify_up(i);
       }

    }

public:
    void heapify_down(int index) {

    }
public:
   void show(){
        for(int i=0;i<size;i++){
            cout<<items[i]<<" ,";
        }
    }


};


#endif //DATASTRUCTURES_HEAP_H
