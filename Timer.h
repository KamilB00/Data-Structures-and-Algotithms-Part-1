//
// Created by Kamil Bonkowski on 10/04/2021.
//

#ifndef DATASTRUCTURES_TIMER_H
#define DATASTRUCTURES_TIMER_H
#include <string>
using namespace std;
class Timer {

    double avg_time_addToArrayList_Beginning = 0;
    double avg_time_addToArrayList_Middle = 0;
    double avg_time_addToArrayList_End = 0;
    double avg_time_removeFromArrayList_Beginning = 0;
    double avg_time_removeFromArrayList_Middle = 0;
    double avg_time_removeFromArrayList_End = 0;
    double avg_time_findInArrayList = 0;

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

   void addToArrayList_Beginning(double elapsed_time, string structure) {

        //ARRAY LIST
        if(structure == "ADD_TO_ARRAYLIST_BEGINNING"){ //1
            visit_counter_arr_1++;
            elapsed_time_total_arr_1 += elapsed_time;
            avg_time_addToArrayList_Beginning = (elapsed_time_total_arr_1/visit_counter_arr_1);
        }else if(structure == "ADD_TO_ARRAYLIST_MIDDLE"){ //2
            visit_counter_arr_2++;
            elapsed_time_total_arr_2 +=elapsed_time;
            avg_time_addToArrayList_Middle = (elapsed_time_total_arr_2/visit_counter_arr_2);
        }else if(structure == "ADD_TO_ARRAYLIST_END"){ //3

        }
        else if(structure == "REMOVE_FROM_ARRAYLIST_BEGINNING"){ //4

        }
        else if(structure == "REMOVE_FROM_ARRAYLIST_MIDDLE"){ //5

        }
        else if(structure == "REMOVE_FROM_ARRAYLIST_END"){ //6

        }
        else if(structure == "FIND_IN_ARRAYLIST"){ //7

        }
        //LINKED LIST
        else if(structure == "ADD_TO_LINKEDLIST_BEGINNING"){ //1

        }
        else if(structure == "ADD_TO_LINKEDLIST_MIDDLE"){ //2

        }
        else if(structure == "ADD_TO_LINKEDLIST_END"){ //3

        }
        else if(structure == "REMOVE_FROM_LINKEDLIST_BEGINNING"){ //4

        }
        else if(structure == "REMOVE_FROM_LINKEDLIST_MIDDLE"){ //5

        }
        else if(structure == "REMOVE_FROM_LINKEDLIST_END"){ //6

        }
        else if(structure == "FIND_IN_LINKEDLIST"){ //7

        }
        //HEAP
        else if(structure == "ADD_TO_HEAP"){ //1

        }
        else if(structure == "REMOVE_FROM_HEAP"){ //2

        }
        else if(structure == "FIND_IN_HEAP"){ //3

        }
        //RED BLACK TREE
        else if(structure == "ADD_TO_RED_BLACK_TREE"){ //1

        }
        else if(structure == "REMOVE_FROM_RED_BLACK_TREE"){ //2

        }
        else if(structure == "FIND_IN_RED_BLACK_TREE"){ //3

        }


    }

    void showAvgTime(string structure){
        if(structure == "ADD_TO_ARRAYLIST_BEGINNING"){ //1
            cout<<"Average Time ["<<structure<<"] : "<< avg_time_addToArrayList_Beginning<<" ns"<<endl;
        }else if(structure == "ADD_TO_ARRAYLIST_MIDDLE"){ //2

        }else if(structure == "ADD_TO_ARRAYLIST_END"){ //3

        }
        else if(structure == "REMOVE_FROM_ARRAYLIST_BEGINNING"){ //4

        }
        else if(structure == "REMOVE_FROM_ARRAYLIST_MIDDLE"){ //5

        }
        else if(structure == "REMOVE_FROM_ARRAYLIST_END"){ //6

        }
        else if(structure == "FIND_IN_ARRAYLIST"){ //7

        }
            //LINKED LIST
        else if(structure == "ADD_TO_LINKEDLIST_BEGINNING"){ //1

        }
        else if(structure == "ADD_TO_LINKEDLIST_MIDDLE"){ //2

        }
        else if(structure == "ADD_TO_LINKEDLIST_END"){ //3

        }
        else if(structure == "REMOVE_FROM_LINKEDLIST_BEGINNING"){ //4

        }
        else if(structure == "REMOVE_FROM_LINKEDLIST_MIDDLE"){ //5

        }
        else if(structure == "REMOVE_FROM_LINKEDLIST_END"){ //6

        }
        else if(structure == "FIND_IN_LINKEDLIST"){ //7

        }
            //HEAP
        else if(structure == "ADD_TO_HEAP"){ //1

        }
        else if(structure == "REMOVE_FROM_HEAP"){ //2

        }
        else if(structure == "FIND_IN_HEAP"){ //3

        }
            //RED BLACK TREE
        else if(structure == "ADD_TO_RED_BLACK_TREE"){ //1

        }
        else if(structure == "REMOVE_FROM_RED_BLACK_TREE"){ //2

        }
        else if(structure == "FIND_IN_RED_BLACK_TREE"){ //3

        }
   }



};


#endif //DATASTRUCTURES_TIMER_H
