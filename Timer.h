//
// Created by Kamil Bonkowski on 10/04/2021.
//

#ifndef DATASTRUCTURES_TIMER_H
#define DATASTRUCTURES_TIMER_H

#include <string>

using namespace std;

class Timer {

    static Timer *instance;

    Timer() {

    }

public:
    static Timer *getInstance() {
        if (!instance)
            instance = new Timer;
        return instance;
    }

    double avg_time_addToArrayList_Beginning = 0;
    double avg_time_addToArrayList_Middle = 0;
    double avg_time_addToArrayList_End = 0;
    double avg_time_removeFromArrayList_Beginning = 0;
    double avg_time_removeFromArrayList_Middle = 0;
    double avg_time_removeFromArrayList_End = 0;
    double avg_time_findInArrayList_by_index = 0;
    double avg_time_findInArrayList_by_value = 0;

    double avg_time_addToLinkedList_Beginning = 0;
    double avg_time_addToLinkedList_Middle = 0;
    double avg_time_addToLinkedList_End = 0;
    double avg_time_removeFromLinkedList_Beginning = 0;
    double avg_time_removeFromLinkedList_Middle = 0;
    double avg_time_removeFromLinkedList_End = 0;
    double avg_time_findInLinkedList = 0;

    double avg_time_addToHeap = 0;
    double avg_time_removeFromHeap = 0;
    double avg_time_findInHeap = 0;

    double avg_time_addTo_RB_tree = 0;
    double avg_time_remove_from_RB_tree = 0;
    double avg_time_find_in_RB_tree = 0;


    double elapsed_time_total_arr_1 = 0;
    double visit_counter_arr_1 = 0;

    double elapsed_time_total_arr_2 = 0;
    double visit_counter_arr_2 = 0;

    double elapsed_time_total_arr_3 = 0;
    double visit_counter_arr_3 = 0;

    double elapsed_time_total_arr_4 = 0;
    double visit_counter_arr_4 = 0;

    double elapsed_time_total_arr_5 = 0;
    double visit_counter_arr_5 = 0;

    double elapsed_time_total_arr_6 = 0;
    double visit_counter_arr_6 = 0;

    double elapsed_time_total_arr_7 = 0;
    double visit_counter_arr_7 = 0;

    double elapsed_time_total_arr_8 = 0;
    double visit_counter_arr_8 = 0;

    double elapsed_time_total_list_1 = 0;
    double visit_counter_list_1 = 0;

    double elapsed_time_total_list_2 = 0;
    double visit_counter_list_2 = 0;

    double elapsed_time_total_list_3 = 0;
    double visit_counter_list_3 = 0;

    double elapsed_time_total_list_4 = 0;
    double visit_counter_list_4 = 0;

    double elapsed_time_total_list_5 = 0;
    double visit_counter_list_5 = 0;

    double elapsed_time_total_list_6 = 0;
    double visit_counter_list_6 = 0;

    double elapsed_time_total_list_7 = 0;
    double visit_counter_list_7 = 0;

    double elapsed_time_total_heap_1 = 0;
    double visit_counter_heap_1 = 0;

    double elapsed_time_total_heap_2 = 0;
    double visit_counter_heap_2 = 0;

    double elapsed_time_total_heap_3 = 0;
    double visit_counter_heap_3 = 0;

    double elapsed_time_total_RB_1 = 0;
    double visit_counter_RB_1 = 0;

    double elapsed_time_total_RB_2 = 0;
    double visit_counter_RB_2 = 0;

    double elapsed_time_total_RB_3 = 0;
    double visit_counter_RB_3 = 0;

public:
    void showAvgTime(string operation
    ) {
        if (operation == "ADD_TO_ARRAYLIST_BEGINNING") {
            cout << "Average Time [" << operation << "] : " << avg_time_addToArrayList_Beginning << " ns" << endl;
        } else if (operation == "ADD_TO_ARRAYLIST_MIDDLE") {
            cout << "Average Time [" << operation << "] : " << avg_time_addToArrayList_Middle << " ns" << endl;
        } else if (operation == "ADD_TO_ARRAYLIST_END") {
            cout << "Average Time [" << operation << "] : " << avg_time_addToArrayList_End << " ns" << endl;
        } else if (operation == "REMOVE_FROM_ARRAYLIST_BEGINNING") {
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromArrayList_Beginning << " ns" << endl;
        } else if (operation == "REMOVE_FROM_ARRAYLIST_MIDDLE") {
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromArrayList_Middle << " ns" << endl;
        } else if (operation == "REMOVE_FROM_ARRAYLIST_END") {
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromArrayList_End << " ns" << endl;
        } else if (operation == "FIND_IN_ARRAYLIST_BY_INDEX") {

            cout << "Average Time [" << operation << "] : " << avg_time_findInArrayList_by_index << " ns" << endl;

        }
            //LINKED LIST
        else if (operation == "ADD_TO_LINKEDLIST_BEGINNING") {
            cout << "Average Time [" << operation << "] : " << avg_time_addToLinkedList_Beginning << " ns" << endl;
        } else if (operation == "ADD_TO_LINKEDLIST_MIDDLE") {
            cout << "Average Time [" << operation << "] : " << avg_time_addToLinkedList_Middle << " ns" << endl;
        } else if (operation == "ADD_TO_LINKEDLIST_END") {
            cout << "Average Time [" << operation << "] : " << avg_time_addToLinkedList_End << " ns" << endl;
        } else if (operation == "REMOVE_FROM_LINKEDLIST_BEGINNING") {
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromLinkedList_Beginning << " ns" << endl;

        } else if (operation == "REMOVE_FROM_LINKEDLIST_MIDDLE") {
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromLinkedList_Middle << " ns" << endl;
        } else if (operation == "REMOVE_FROM_LINKEDLIST_END") {
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromLinkedList_End << " ns" << endl;
        } else if (operation == "FIND_IN_LINKEDLIST") {
            cout << "Average Time [" << operation << "] : " << avg_time_findInLinkedList << " ns" << endl;
        }
            //HEAP
        else if (operation == "ADD_TO_HEAP") { //1
            cout << "Average Time [" << operation << "] : " << avg_time_addToHeap << " ns" << endl;
        } else if (operation == "REMOVE_FROM_HEAP") { //2
            cout << "Average Time [" << operation << "] : " << avg_time_removeFromHeap << " ns" << endl;
        } else if (operation == "FIND_IN_HEAP") { //3
            cout << "Average Time [" << operation << "] : " << avg_time_findInHeap << " ns" << endl;
        }
            //RED BLACK TREE
        else if (operation == "ADD_TO_RED_BLACK_TREE") {
            cout << "Average Time [" << operation << "] : " << avg_time_addTo_RB_tree << " ns" << endl;

        } else if (operation == "REMOVE_FROM_RED_BLACK_TREE") {
            cout << "Average Time [" << operation << "] : " << avg_time_remove_from_RB_tree << " ns" << endl;

        } else if (operation == "FIND_IN_RED_BLACK_TREE") {
            cout << "Average Time [" << operation << "] : " << avg_time_find_in_RB_tree << " ns" << endl;

        }
    }


public:
    void calculate_average_elapsed_time(double elapsed_time, string operation) {

        //ARRAY LIST
        if (operation == "ADD_TO_ARRAYLIST_BEGINNING") { //1
            visit_counter_arr_1++;
            elapsed_time_total_arr_1 += elapsed_time;
            avg_time_addToArrayList_Beginning = (elapsed_time_total_arr_1 / visit_counter_arr_1);
        } else if (operation == "ADD_TO_ARRAYLIST_MIDDLE") { //2
            visit_counter_arr_2++;
            elapsed_time_total_arr_2 += elapsed_time;
            avg_time_addToArrayList_Middle = (elapsed_time_total_arr_2 / visit_counter_arr_2);
        } else if (operation == "ADD_TO_ARRAYLIST_END") { //3
            visit_counter_arr_3++;
            elapsed_time_total_arr_3 += elapsed_time;
            avg_time_addToArrayList_End = (elapsed_time_total_arr_3 / visit_counter_arr_3);

        } else if (operation == "REMOVE_FROM_ARRAYLIST_BEGINNING") { //4
            visit_counter_arr_4++;
            elapsed_time_total_arr_4 += elapsed_time;
            avg_time_removeFromArrayList_Beginning = (elapsed_time_total_arr_4 / visit_counter_arr_4);

        } else if (operation == "REMOVE_FROM_ARRAYLIST_MIDDLE") { //5
            visit_counter_arr_5++;
            elapsed_time_total_arr_5 += elapsed_time;
            avg_time_removeFromArrayList_Middle = (elapsed_time_total_arr_5 / visit_counter_arr_5);

        } else if (operation == "REMOVE_FROM_ARRAYLIST_END") { //6
            visit_counter_arr_6++;
            elapsed_time_total_arr_6 += elapsed_time;
            avg_time_removeFromArrayList_End = (elapsed_time_total_arr_6 / visit_counter_arr_6);
        } else if (operation == "FIND_IN_ARRAYLIST_BY_INDEX") { //7
            visit_counter_arr_7++;
            elapsed_time_total_arr_7 += elapsed_time;
            avg_time_findInArrayList_by_index = (elapsed_time_total_arr_7 / visit_counter_arr_7);
        }
        else if (operation == "FIND_IN_ARRAYLIST_BY_VALUE") { //8
            visit_counter_arr_8++;
            elapsed_time_total_arr_8 += elapsed_time;
            avg_time_findInArrayList_by_value = (elapsed_time_total_arr_8 / visit_counter_arr_8);
        }
            //LINKED LIST
        else if (operation == "ADD_TO_LINKEDLIST_BEGINNING") { //1
            visit_counter_list_1++;
            elapsed_time_total_list_1 += elapsed_time;
            avg_time_addToLinkedList_Beginning = (elapsed_time_total_list_1 / visit_counter_list_1);

        } else if (operation == "ADD_TO_LINKEDLIST_MIDDLE") { //2
            visit_counter_list_2++;
            elapsed_time_total_list_2 += elapsed_time;
            avg_time_addToLinkedList_Middle = (elapsed_time_total_list_2 / visit_counter_list_2);

        } else if (operation == "ADD_TO_LINKEDLIST_END") { //3
            visit_counter_list_3++;
            elapsed_time_total_list_3 += elapsed_time;
            avg_time_addToLinkedList_End = (elapsed_time_total_list_3 / visit_counter_list_3);
        } else if (operation == "REMOVE_FROM_LINKEDLIST_BEGINNING") { //4
            visit_counter_list_4++;
            elapsed_time_total_list_4 += elapsed_time;
            avg_time_removeFromLinkedList_Beginning = (elapsed_time_total_list_4 / visit_counter_list_4);

        } else if (operation == "REMOVE_FROM_LINKEDLIST_MIDDLE") { //5
            visit_counter_list_5++;
            elapsed_time_total_list_5 += elapsed_time;
            avg_time_removeFromLinkedList_Middle = (elapsed_time_total_list_5 / visit_counter_list_5);

        } else if (operation == "REMOVE_FROM_LINKEDLIST_END") { //6
            visit_counter_list_6++;
            elapsed_time_total_list_6 += elapsed_time;
            avg_time_removeFromLinkedList_End = (elapsed_time_total_list_6 / visit_counter_list_6);
        } else if (operation == "FIND_IN_LINKEDLIST") { //7
            visit_counter_list_7++;
            elapsed_time_total_list_7 += elapsed_time;
            avg_time_findInLinkedList = (elapsed_time_total_list_7 / visit_counter_list_7);
        }
            //HEAP
        else if (operation == "ADD_TO_HEAP") { //1
            visit_counter_heap_1++;
            elapsed_time_total_heap_1 += elapsed_time;
            avg_time_addToHeap = (elapsed_time_total_heap_1 / visit_counter_heap_1);

        } else if (operation == "REMOVE_FROM_HEAP") { //2
            visit_counter_heap_2++;
            elapsed_time_total_heap_2 += elapsed_time;
            avg_time_removeFromHeap = (elapsed_time_total_heap_2 / visit_counter_heap_2);

        } else if (operation == "FIND_IN_HEAP") { //3
            visit_counter_heap_3++;
            elapsed_time_total_heap_3 += elapsed_time;
            avg_time_findInHeap = (elapsed_time_total_heap_3 / visit_counter_heap_3);
        }
            //RED BLACK TREE
        else if (operation == "ADD_TO_RED_BLACK_TREE") { //1
            visit_counter_RB_1++;
            elapsed_time_total_RB_1 += elapsed_time;
            avg_time_addTo_RB_tree = (elapsed_time_total_RB_1 / visit_counter_RB_1);

        } else if (operation == "REMOVE_FROM_RED_BLACK_TREE") { //2
            visit_counter_RB_2++;
            elapsed_time_total_RB_2 += elapsed_time;
            avg_time_remove_from_RB_tree = (elapsed_time_total_RB_2 / visit_counter_RB_2);

        } else if (operation == "FIND_IN_RED_BLACK_TREE") { //3
            visit_counter_RB_3++;
            elapsed_time_total_RB_3 += elapsed_time;
            avg_time_find_in_RB_tree = (elapsed_time_total_RB_3 / visit_counter_RB_3);

        }


    }
};


#endif //DATASTRUCTURES_TIMER_H
