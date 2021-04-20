//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_MENU_H
#define DATASTRUCTURES_MENU_H

#include "Array.h"
#include "ListTwoDirection.h"
#include "File.h"
#include "Heap.h"
#include "RedBlackTree.h"

class Menu {

public:
    Timer *timer = timer->getInstance();
    int visit_counter = 0;
    string file_name;
    string file_name_and_extension;
    string path;

    int mode_interface() {
        int mode = 0;

        cout << "-----------------------------------------------" << endl;
        cout << "     Welcome to Data Structures Time Analyzer " << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "               1. Test Mode" << endl;
        cout << "               2. Read Mode" << endl;
        cout << "               3. Show average operations time" << endl;
        cout << "               4. About" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        cout << " Press 0 to Exit" << endl;

        do {
            cin >> mode;
            if (mode >= 0 && mode <= 4) {
                switch (mode) {
                    case 1: {

                        regex reg("[a-zA-Z0-9]+");

                        cout << "File name: ";
                        cin >> file_name;
                        if (regex_match(file_name, reg)) {
                            file_name_and_extension = file_name + ".txt";

                            File *file = new File(file_name_and_extension);
                            timer->clear_data();
                            clearScreen();
                            data_structures_interface();
                        } else {
                            cout << "Incorrect file name syntax" << endl;
                        }
                    }
                        break;
                    case 2: {
                        visit_counter++;
                        char choice;
                        clearScreen();
                        if (visit_counter > 1) {
                            cout << "Do you want to remove previous measurements [y/n]" << endl;
                            do {
                                cin >> choice;
                                if (choice != 'y' && choice != 'n') {
                                    cout << "Incorrect choice. Try again !" << endl;
                                }
                            } while (choice != 'y' && choice != 'n');

                            if (choice == 'y') {
                                timer->clear_data();
                            }
                        }
                        cout << "Type a path to your file directory :" << endl;
                        cin >> path;


                        file_name_and_extension = path;
                        fstream file;
                        file.open(file_name_and_extension, ios::in);

                        if (!file.good()) {
                            cout << "File does not exist !" << endl;
                            mode_interface();

                        } else {
                            cout << file_name_and_extension << endl;
                            cout << "File loaded successfully !" << endl;
                            data_structures_interface();
                        }
                        break;
                    }
                    case 3: {
                        timer->view_data();
                        mode_interface();
                    }
                    case 4: {
                        clearScreen();
                        about_interface();
                        break;
                    }
                    default:
                        exit(1);

                }
            } else {
                cout << "Mode not found try again !" << endl;
            }
        } while (mode < 0 || mode > 4);

    }

    void about_interface() {
        int choice = 0;
        cout << "-----------------------------------------------------  " << endl;
        cout << "                     About                             " << endl;
        cout << "-----------------------------------------------------  " << endl;
        cout << "   * Test Mode * - allows you to specify amount,       " << endl;
        cout << "   lower bounds and upper bounds of randomly           " << endl;
        cout << "   generated numbers                                   " << endl;
        cout << "-----------------------------------------------------  " << endl;
        cout << "   * Read Mode *  - program can read your own .txt file" << endl;
        cout << "   organized with proper pattern                       " << endl;
        cout << endl;
        cout << "                   *File Pattern*                      " << endl;
        cout << "   [1-st line] number of elements                      " << endl;
        cout << "   [2-n to n-th line] elements of the array            " << endl;
        cout << "   separated with new line                             " << endl;
        cout << "-----------------------------------------------------  " << endl;
        cout << "   * Show average operation time * - allow to view     " << endl;
        cout << "   each operation average time                         " << endl;
        cout << "-----------------------------------------------------  " << endl;
        cout << endl;
        cout << " Press 0 to Return" << endl;

        do {
            cin >> choice;
            if (choice == 0) {
                mode_interface();
            } else {
                cout << "Sign not allowed here ! [Press 0 to Return] " << endl;
            }
        } while (choice != 0);
    }

    int select_option() {
        int choice = 0;
        do {
            cin >> choice;
            if (choice >= 0 && choice <= 7) {
                return choice;
            } else {
                cout << "No operation found try again !" << endl;
            }
        } while (choice < 0 || choice > 7);
    };

    int operations_interface_tree(string name) {


        cout << "     -------------------------------------------   " << endl;
        cout << "             Operations on " << name << endl;
        cout << "     -------------------------------------------   " << endl;
        cout << "              1. Add element                       " << endl;
        cout << "              2. Remove element                    " << endl;
        cout << "              3. Remove element by index           " << endl;
        cout << "              4. Find element by value             " << endl;
        cout << "              5. Find element by index             " << endl;
        cout << "              6. Show heap                         " << endl;
        cout << "     -------------------------------------------   " << endl;
        cout << endl;
        cout << " Press 0 to Return                            " << endl;

        return select_option();
    }

    int operations_interface_RB_TREE(string name) {

        cout << "     -------------------------------------------   " << endl;
        cout << "             Operations on " << name << endl;
        cout << "     -------------------------------------------   " << endl;
        cout << "              1. Add element                       " << endl;
        cout << "              2. Remove element                    " << endl;
        cout << "              3. Find element by value             " << endl;
        cout << "              4. Show Red Black Tree               " << endl;
        cout << "     -------------------------------------------   " << endl;
        cout << endl;
        cout << " Press 0 to Return                            " << endl;

        return select_option();
    }

    int operations_interface(string name) {

        cout << "     -------------------------------------------   " << endl;
        cout << "             Operations on " << name << endl;
        cout << "     -------------------------------------------   " << endl;
        cout << "              1. Add element                       " << endl;
        cout << "              2. Add element by index              " << endl;
        cout << "              3. Remove element                    " << endl;
        cout << "              4. Remove element by index           " << endl;
        cout << "              5. Find element by value             " << endl;
        cout << "              6. Find element by index             " << endl;
        cout << "              7. Show " << name << endl;
        cout << "     -------------------------------------------   " << endl;
        cout << endl;
        cout << " Press 0 to Return                            " << endl;

        return select_option();
    }


    void data_structures_interface() {

        int choice = 0;

        cout << "--------------------------------------------  " << endl;
        cout << "           Pick one Data Structure            " << endl;
        cout << "--------------------------------------------  " << endl;
        cout << "          1. Table                            " << endl;
        cout << "          2. Doubly Linked List               " << endl;
        cout << "          3. Heap                             " << endl;
        cout << "          4. Red-Black Tree                   " << endl;
        cout << "--------------------------------------------  " << endl;
        cout << endl;
        cout << " Press 0 to Return                            " << endl;


        do {
            cin >> choice;
            if (choice >= 0 && choice <= 4) {
                switch (choice) {
                    case 0: {
                        clearScreen();
                        mode_interface();
                    }
                        // ARRAY DATA STRUCTURE
                    case 1: {
                        clearScreen();
                        Array *array = new Array(file_name_and_extension);
                        char add_more = ' ';

                        int operation = operations_interface("Array");
                        do {
                            int visit_count = 0;
                            switch (operation) {
                                //Array OPTIONS

                                //#0 Return to previous window
                                case 0: {
                                    clearScreen();
                                    data_structures_interface();
                                    delete array;
                                    array = nullptr;

                                }
                                    //#1 Add to array
                                case 1: {
                                    array->add();
                                    break;
                                }

                                    //#2 Add to array by index
                                case 2: {
                                    int index = 0;

                                    cout << "index: ";
                                    cin >> index;

                                    if (index < 0 || index > array->size) {
                                        cout << "Incorrect index !" << endl;
                                    } else {
                                        array->add(index);
                                    }

                                    break;
                                }
                                    //#3 Remove element
                                case 3: {
                                    array->remove();
                                    break;
                                }
                                    //#4 Remove element by index
                                case 4: {
                                    int index = 0;
                                    cout << "Index of removing element: ";
                                    cin >> index;
                                    array->remove(index);
                                    break;
                                }
                                    //#5 Find element by value
                                case 5: {
                                    array->find();
                                    break;
                                }
                                    //#6 Find element by index
                                case 6: {
                                    int index = 0;
                                    cout << "Index of the value: ";
                                    cin >> index;

                                    array->find(index);
                                    break;
                                }
                                case 7: {
                                    array->show();
                                    break;
                                }
                                default:
                                    cout << "No option found try again ! [Press 0 to Return]" << endl;
                            }

                        } while (operation = operations_interface("Array"));
                        data_structures_interface();
                        break;
                    }

//*******************************************************************************************************************

                        //LIST DATA STRUCTURE
                    case 2: {

                        clearScreen();
                        ListTwoDirection *list = new ListTwoDirection(file_name_and_extension);
                        int operation = operations_interface("List");

                        do {

                            switch (operation) {
                                //List OPTIONS

                                //#0 Return to previous screen
                                case 0: {
                                    clearScreen();
                                    data_structures_interface();
                                    delete list;
                                    list = nullptr;
                                }
                                    //#1 Add to list [LIST]
                                case 1: {
                                    int value = 0;

                                    cout << "list.add(" << list->get_size() << ") = ";
                                    cin >> value;

                                    list->add(value, list->get_size());

                                    break;
                                }
                                    // #2 Add to list by index [LIST]
                                case 2: {
                                    int value = 0;
                                    int index = 0;


                                    do {
                                        cout << "Index: ";
                                        cin >> index;

                                        if (index < 0 || index > list->get_size()) {
                                            cout << "Incorrect index ! Try again" << endl;
                                        }

                                    } while (index > list->get_size() || index < 0);

                                    cout << "list.add(" << index << ") = ";
                                    cin >> value;

                                    list->add(value, index);

                                    break;
                                }
                                    //#3 Remove element [LIST]
                                case 3: {

                                    int index = list->get_size() - 1;
                                    int times = 0;
                                    if (list->get_size() > 0) {
                                        cout << "How many times do you want to delete :" << endl;
                                        cin >> times;
                                        if (times <= list->get_size()) {
                                            list->delete_manager(index, times);
                                        } else {
                                            cout << "There are only " << list->get_size() << " elements in the list"
                                                 << endl;
                                        }

                                    } else {
                                        cout << "List is empty !" << endl;
                                    }
                                    break;
                                }
                                    //#4 Remove element by index [LIST]
                                case 4: {
                                    int index = 0;
                                    int times = 0;
                                    if (list->get_size() > 0) {
                                        do {
                                            cout << "Index: ";
                                            cin >> index;

                                            if (index < 0 || index > list->get_size()) {
                                                cout << "Incorrect index ! Try again" << endl;
                                            }
                                        } while (index > list->get_size() || index < 0);
                                        cout << "How many times do you want to delete :" << endl;
                                        cin >> times;

                                        if (times <= list->get_size()) {
                                            list->delete_manager(index, times);
                                        } else {
                                            cout << "There are only " << list->get_size() << " elements in the list"
                                                 << endl;
                                        }

                                    } else {
                                        cout << "List is empty !" << endl;
                                    }
                                    break;
                                }
                                    // #5 Find element [LIST]
                                case 5: {
                                    if (list->get_size() > 0) {
                                        list->find();
                                    } else {
                                        cout << "List is empty nothing to find !" << endl;
                                    }
                                    break;
                                }
                                    //#6 Find by index
                                case 6: {
                                    int index = 0;
                                    if (list->get_size() > 0) {
                                        do {
                                            cout << "Value index: ";
                                            cin >> index;
                                            if (index < 0 || index > list->get_size()) {
                                                cout << "Incorrect index ! Try again" << endl;
                                            }
                                        } while (index > list->get_size() || index < 0);

                                        list->find(index);
                                    } else {
                                        cout << "List is empty nothing to find !" << endl;
                                    }
                                    break;
                                }
                                    //#7 Show List
                                case 7: {
                                    list->show();
                                    break;
                                }
                                default:
                                    cout<<"No operation found !"<<endl;

                            }
                        } while (operation = operations_interface("List"));
                        data_structures_interface();
                        break;
                    }
//*******************************************************************************************************************

                        //HEAP DATA STRUCTURE
                    case 3: {
                        clearScreen();
                        Heap *heap = new Heap(file_name_and_extension);
                        int operation = operations_interface_tree("Heap");

                        do {
                            switch (operation) {
                                //Heap OPTIONS

                                //#0 Return to previous screen
                                case 0: {
                                    clearScreen();
                                    data_structures_interface();
                                    delete heap;
                                    heap = nullptr;
                                }
                                    //#1 Add to heap [HEAP]
                                case 1: {
                                    heap->add();

                                    break;
                                }
                                    //#2 Remove element [HEAP]
                                case 2: {

                                    heap->remove(heap->get_size() - 1);
                                    break;
                                }
                                    //#3 Remove element by index [HEAP]
                                case 3: {
                                    int index = 0;
                                    cout << "Index: ";
                                    cin >> index;
                                    heap->remove(index);
                                    break;
                                }
                                    // #4 Find element [HEAP]
                                case 4: {
                                    if (heap->get_size() > 0) {
                                        heap->find();
                                    } else {
                                        cout << "Heap is empty nothing to find !" << endl;
                                    }

                                    break;
                                }
                                    //#5 Find element by index [HEAP]
                                case 5: {
                                    int index = 0;
                                    if (heap->get_size() > 0) {
                                        cout << "Index: ";
                                        cin >> index;

                                        if (index >= 0 && index < heap->get_size()) {
                                            heap->find(index);
                                        }
                                    } else {
                                        cout << "Heap is empty nothing to find !" << endl;
                                    }
                                    break;
                                }
                                    //#6 Show heap [HEAP]
                                case 6: {
                                    char show = 'y';
                                    if (heap->get_size() > 100) {
                                        cout << "There are " << heap->get_size()
                                             << " values in the heap do you want to continue ? [y/n]" << endl;

                                        cin >> show;

                                        while (show != 'y' || show != 'n') {
                                            cout << "Incorrect character. Try again !" << endl;
                                            cin >> show;
                                        }
                                        if (show == 'y') {
                                            heap->show();
                                        }
                                    } else {
                                        heap->show();
                                    }
                                    break;
                                }
                            }
                        } while (operation = operations_interface_tree("Heap"));
                        data_structures_interface();

                        break;
                    }
//*******************************************************************************************************************
                        //Red-Black Tree DATA STRUCTURE
                    case 4: {
                        clearScreen();
                        RedBlackTree *rbt = new RedBlackTree(file_name_and_extension);

                        int operation = operations_interface_RB_TREE("Red-Black Tree");
                        do {
                            switch (operation) {

                                case 0: {
                                    clearScreen();
                                    data_structures_interface();
                                    delete rbt;
                                    rbt = nullptr;
                                }

                                case 1: {
                                    //Add value to R-B-tree
                                    int data = 0;
                                    cout << "Type a value you want to add: ";
                                    cin >> data;

                                    rbt->addNode(data);

                                    break;
                                }
                                case 2: {
                                    //Remove value from R-B-tree
                                    int data = 0;
                                    int tmp = 0;
                                    cout << "Type a value you want to delete: ";
                                    cin >> data;

                                    rbt->deleteNode(data);

                                    break;
                                }
                                case 3: {
                                    //Find in R-B-tree by value

                                    int data = 0;
                                    cout << "Type a value you are looking for: ";
                                    cin >> data;

                                    int times = 0;
                                    cout << "How many times should time be measured: " << endl;
                                    cin >> times;
                                    for (int i = 0; i < times; i++) {
                                        auto start = std::chrono::steady_clock::now(); //START [LIST FIND BY VALUE]
                                        if (rbt->find(rbt->getRoot(), data)) {
                                            cout << "Value " << data << " is in the RED BLACK TREE" << endl;
                                        } else {
                                            cout << "Value not found" << endl;
                                        }

                                        auto end = std::chrono::steady_clock::now();
                                        double elapsed_time = double(
                                                std::chrono::duration_cast<std::chrono::nanoseconds>(
                                                        end - start).count());
                                        timer->calculate_average_elapsed_time(elapsed_time, "FIND_IN_RED_BLACK_TREE");
                                        timer->showAvgTime("FIND_IN_RED_BLACK_TREE");
                                    }
                                    break;
                                }
                                case 4: {
                                    //Show R-B-tree
                                    rbt->preorderTraversal(rbt->getRoot());
                                }
                            }

                        } while (operation = operations_interface_RB_TREE("Red-Black Tree"));
                        data_structures_interface();

                        break;
                    }

//*******************************************************************************************************************
                }
            } else {
                cout << "No structure found try again !" << endl;
            }
        } while ((choice < 0 || choice > 5));

    }

    void clearScreen() {
        cout << "\033[2J\033[1;1H";
    }
};


#endif //DATASTRUCTURES_MENU_H
