//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_MENU_H
#define DATASTRUCTURES_MENU_H

#include "Array.h"
#include "ListTwoDirection.h"
#include "File.h"
#include "Heap.h"

class Menu {
public:

    int mode_interface() {
        clearScreen();
        int mode = 0;
        cout << "-----------------------------------------------" << endl;
        cout << "     Welcome to Data Structures Time Analyzer " << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "               1. Test Mode" << endl;
        cout << "               2. Auto Mode" << endl;
        cout << "               3. Read Mode" << endl;
        cout << "               4. About" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        cout << " Press 0 to Exit" << endl;

        do {
            cin >> mode;
            if (mode >= 0 && mode <= 3) {
                switch (mode) {
                    case 1: {
                        File *file = new File();
                        clearScreen();
                        data_structures_interface();
                    }
                        break;
                    case 2: {
                        File *file = new File(100);
                        clearScreen();
                        data_structures_interface();
                        break;
                    }
                    case 3: {
                        clearScreen();
                        fstream file;
                        file.open("data.txt", ios::in);

                        if (!file.good()) {
                            cout << "File data.txt does not exist !" << endl;
                        }
                        data_structures_interface();
                        break;
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
        } while (mode < 0 || mode > 3);

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
        cout << "   * Auto Mode * - fills a file automatically with     " << endl;
        cout << "   random numbers in range (-1000,1000)                " << endl;
        cout << "-----------------------------------------------------  " << endl;
        cout << "   * Read Mode *  - program creates a file and allows  " << endl;
        cout << "   you to fill it with your own data                   " << endl;
        cout << endl;
        cout << "   [File Pattern]                                      " << endl;
        cout << "   [1-st line] number of elements                      " << endl;
        cout << "   [2-n to n-th line] elements of the array            " << endl;
        cout << "   separated with new line                             " << endl;
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
            if (choice >= 0 && choice <= 6) {
                return choice;
            } else {
                cout << "No operation found try again !" << endl;
            }
        } while (choice < 0 || choice > 6);
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
        cout << "          5. AVL Tree                         " << endl;
        cout << "--------------------------------------------  " << endl;
        cout << endl;
        cout << " Press 0 to Return                            " << endl;


        do {
            cin >> choice;
            if (choice >= 0 && choice <= 5) {
                switch (choice) {
                    case 0: {
                        clearScreen();
                        mode_interface();
                    }
                        // ARRAY DATA STRUCTURE
                    case 1: {
                        clearScreen();
                        Array *array = new Array();
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
                                    visit_count++;

                                    if (visit_count > 0) {
                                        do {
                                            add_more = ' ';
                                            cout << "Do you want to add more numbers [y/n] ?  " << endl;
                                            cin >> add_more;

                                            if (add_more == 'y') {
                                                array->add();
                                            } else if (add_more != 'y' && add_more != 'n') {
                                                cout << "No such option try again !" << endl;
                                            }

                                        } while (add_more == 'y');
                                    }
                                    break;
                                }

                                    //#2 Add to array by index
                                case 2: {
                                    int index = 0;
                                    visit_count++;
                                    cout << "index: ";
                                    cin >> index;

                                    if (index < 0 || index > array->size) {
                                        cout << "Incorrect index !" << endl;
                                    } else {
                                        array->add(index);
                                    }

                                    if (visit_count > 0) {
                                        do {
                                            cout << "Do you want to add more numbers [y/n] ?  " << endl;
                                            cin >> add_more;

                                            if (add_more == 'y') {
                                                cout << "index: ";
                                                cin >> index;

                                                if (index < 0 || index > array->size) {
                                                    cout << "Incorrect index !" << endl;
                                                } else {
                                                    array->add(index);
                                                }
                                            } else if (add_more != 'y' && add_more != 'n') {
                                                cout << "No such option try again !" << endl;
                                            }
                                        } while (add_more == 'y');
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
                        ListTwoDirection *list = new ListTwoDirection();
                        int operation = operations_interface("List");

                        do {
                            int visit_count = 0;
                            char add_more = ' ';
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
                                    visit_count++;

                                    if (visit_count > 0) {
                                        do {
                                            add_more = ' ';
                                            cout << "Do you want to add more numbers [y/n] ?  ";
                                            cin >> add_more;

                                            if (add_more == 'y') {
                                                cout << "list.add(" << list->get_size() << ") = ";
                                                cin >> value;
                                                list->add(value, list->get_size());
                                            } else if (add_more != 'y' && add_more != 'n') {
                                                cout << "No such option try again !" << endl;
                                            }

                                        } while (add_more == 'y');
                                    }
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
                                    visit_count++;

                                    if (visit_count > 0) {
                                        do {
                                            add_more = ' ';
                                            cout << "Do you want to add more numbers [y/n] ?  ";
                                            cin >> add_more;

                                            if (add_more == 'y') {
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
                                            } else if (add_more != 'y' && add_more != 'n') {
                                                cout << "No such option try again !" << endl;
                                            }

                                        } while (add_more == 'y');
                                    }
                                    break;
                                }
                                    //#3 Remove element [LIST]
                                case 3: {

                                    int index = list->get_size() - 1;

                                    if (list->get_size() > 0) {

                                        list->remove(index);
                                        cout << "list.remove(" << index << ") Removed Successfully !" << endl;
                                    } else {
                                        cout << "List is empty !" << endl;
                                    }
                                    break;
                                }
                                    //#4 Remove element by index [LIST]
                                case 4: {
                                    int index = 0;
                                    if (list->get_size() > 0) {
                                        do {
                                            cout << "Index: ";
                                            cin >> index;

                                            if (index < 0 || index > list->get_size()) {
                                                cout << "Incorrect index ! Try again" << endl;
                                            }
                                        } while (index > list->get_size() || index < 0);

                                        list->remove(index);
                                        cout << "list.remove(" << index << ") Removed successfully !" << endl;
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
                                    //#6 Find element by index [LIST]
                                case 6: {
                                    if (list->get_size() > 0) {
                                        int index = 0;
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
                            }
                        } while (operation = operations_interface("List"));
                        data_structures_interface();
                        break;
                    }
//*******************************************************************************************************************

                        //HEAP DATA STRUCTURE
                    case 3: {
                        clearScreen();
                        Heap *heap = new Heap();
                        int operation = operations_interface_tree("Heap");

                        do {
                            int visit_count = 0;
                            char add_more = ' ';
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
                                    heap->find();

                                    break;
                                }
                                    //#5 Find element by index [HEAP]
                                case 5: {
                                    int index = 0;
                                    cout << "Index: ";
                                    cin >> index;

                                    if(index > 0 && index < heap->get_size()){
                                        heap->find(index);
                                    }
                                    break;
                                }
                                    //#6 Show heap [HEAP]
                                case 6:
                                {
                                    char show = 'y';
                                    if(heap->get_size() > 100){
                                        cout<<"There are "<<heap->get_size()<<" values in the heap do you want to continue ? [y/n]"<<endl;

                                        cin>>show;

                                       while(show != 'y' || show != 'n'){
                                           cout<<"Incorrect character. Try again !"<<endl;
                                           cin>>show;
                                       }
                                         if(show == 'y'){
                                             heap->show();
                                         }
                                    }
                                    else {
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

                        operations_interface("Red-Black Tree");
                        break;
                    }
//*******************************************************************************************************************
                        //AVL Tree DATA STRUCTURE
                    case 5: {
                        clearScreen();
                        operations_interface("AVL Tree");
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
//      system("clear");
    }
};


#endif //DATASTRUCTURES_MENU_H
