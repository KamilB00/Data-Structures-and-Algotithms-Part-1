#include <iostream>
#include <chrono>
#include <fstream>
#include <random>


using namespace std;

class Array {
public:

    int size = 0;
    int *arr_dyn = create(size);
    int *arr_dyn_new = NULL;
    int value_add = 0;

    int *create(int size) {
        int *arr = new int[size];
        return arr;
    }

    void add(int index) {
        auto start = std::chrono::steady_clock::now();
        int value = 0;
        int temp = 0;
        //adding element at the beginning,    SIZE == ELEMENTS

        if (index == 0) {
            size++;

            arr_dyn_new = create(size);

            cout << "array[" << index << "] = ";
            cin >> value;


            arr_dyn_new[0] = value;

            for (int i = 0; i < size; i++) {
                temp = arr_dyn[i];
                arr_dyn_new[i + 1] = temp;
            }

            arr_dyn = NULL;
            delete[] arr_dyn;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = NULL;
            delete[] arr_dyn_new;

            auto end = std::chrono::steady_clock::now();
            double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            cout << "elapsed Time: " << elapsed_time << endl;

        }

            //adding element in the middle,   SIZE == ELEMENTS
        else if (index <= size - 1 && index > 0) {
            temp = 0;
            size++;
            arr_dyn_new = create(size);

            cout << "array[" << index << "] = ";
            cin >> value;

            for (int i = 0; i < index; i++) {

                arr_dyn_new[i] = arr_dyn[i];
            }
            arr_dyn_new[index] = value;

            for (int i = index; i < size; i++) {
                temp = arr_dyn[i];
                arr_dyn_new[i + 1] = temp;
            }

            delete[] arr_dyn;
            arr_dyn = NULL;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = NULL;
            delete[] arr_dyn_new;
        }


    }

    void add() {
        int value = 0;
        //adding element at the end,   SIZE == ELEMENTS

        size++;
        arr_dyn_new = create(size);

        for (int i = 0; i < size - 1; i++) {
            arr_dyn_new[i] = arr_dyn[i];
        }

        cout << "array[" << size - 1 << "] = ";
        cin >> value;
        arr_dyn_new[size - 1] = value_add;
        value_add++;

        delete[]arr_dyn;
        arr_dyn = NULL;
        arr_dyn = arr_dyn_new;

        arr_dyn_new = NULL;
        delete[] arr_dyn_new;


    }

    void remove(int index) {
        // remove from the beginning
        if (size > 0) {
            if (index == 0) {
                size--;
                arr_dyn_new = create(size);
                for (int i = 1; i < size; i++) {
                    arr_dyn_new[i - 1] = arr_dyn[i];
                }
                arr_dyn = NULL;

                arr_dyn = arr_dyn_new;
                arr_dyn_new = NULL;
                delete[]arr_dyn;
                delete[] arr_dyn_new;

            }
                //remove in the middle
            else if (index <= size - 1 && index > 0) {
                size--;
                arr_dyn_new = create(size);
                for (int i = 0; i < index; i++) {
                    arr_dyn_new[i] = arr_dyn[i];
                }
                for (int i = index; i < size; i++) {
                    arr_dyn_new[i] = arr_dyn[i + 1];
                }
                arr_dyn = NULL;

                arr_dyn = arr_dyn_new;
                arr_dyn_new = NULL;

                delete[]arr_dyn;
                delete[] arr_dyn_new;

            }
        } else {
            cout << "Array is empty !" << endl;
        }
    }

    // remove from the end
    void remove() {

        if (size > 0) {
            size--;
            arr_dyn_new = create(size); //size =4
            for (int i = 0; i < size; i++) {
                arr_dyn_new[i] = arr_dyn[i];
            }

            cout << "Deleting ..." << endl;

            delete[]arr_dyn;
            arr_dyn = NULL;
            arr_dyn = arr_dyn_new;
            arr_dyn_new = NULL;
            delete[] arr_dyn_new;
        } else {
            cout << "Array is empty !" << endl;
        }
    }

    void find(int index) {
        if (size > index && index >= 0) {
            cout << "Element at index " << index << " found: array[" << index << "] = " << arr_dyn[index] << endl;
        } else {
            cout << "No element with the index " << index << " found !" << endl;
        }

    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << endl;
            cout << "array[" << i << "] = " << arr_dyn[i] << endl;
        }
    }


};

class Element {
public:
    int data = 0;
    Element *next = NULL;
    Element *prev = NULL;

    Element(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

class ListTwoDirection {
    int size = 0;
    Element *first = NULL;
    Element *last = NULL;

    Element *getPosition(unsigned long long int index) { //pozycja numerowna od 0
        Element *temp = first;
        unsigned long long int pos = index;
        int i = 0;

        if (index < 0 || index > size) {
            return NULL;
        } else {
            while (i++ < pos) {
                temp = temp->next;
            }
            return temp;
        }

    }

public:
    void show() {
        Element *temp = first;
        int i = 0;
        if (temp != NULL) {
            while (temp != NULL) {
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

        Element *n = new Element(d);

        if (size == 0) { // nie ma ani jednego elementu
            last = first = n;

        } else if (index == 0) { // na początek
            first->prev = n;
            n->next = first;
            first = n;

        } else if (index == size) { // na końcu
            last->next = n;
            n->prev = last;
            last = n;
        } else {
            Element *temp = getPosition(index);
            Element *before = temp->prev;

            before->next = n;
            temp->prev = n;
            n->next = temp;
            n->prev = before;
        }
        cout << "Element has been added on the position with index: " << index << endl;
        size++;
    }

    void remove(unsigned long long int index) {

        if (index > size || index < 0) {
            cout << "Incorrect index !" << endl;
        } else if (index > 0 && index < size - 1) { //usuwanie ze środka
            Element *temp = getPosition(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;

            size--;
        } else if (index == 0) { // usuwanie z pierwszego
            Element *temp = first;
            if (size > 1) {
                first = temp->next;
                first->prev = NULL;
                delete temp;
                size--;
            } else {
                first = NULL;
                last = NULL;
                delete temp;
                size--;
            }
        } else if (index == size - 1) { //usuwanie z ostatniego
            Element *temp = last;
            last = last->prev;
            last->next = NULL;
            delete temp;
            size--;
        }
        cout << "Element on the position with index: " << index << " has been deleted" << endl;

    }

    void removeAll() {
        int i = size - 1;
        while (i >= 0) {
            remove(i);
            i--;
        }
    }

};

class File {
public:

    File() {
        int amount = 0;
        int lower = 0;
        int upper = 0;
        fstream file;
        file.open("data.txt", ios::out);
        cout << "How many numbers should be created ? :";
        cin >> amount;
        cout << "Lower Bounds: ";
        cin >> lower;
        cout << "Upper Bounds: ";
        cin >> upper;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(lower, upper);

        for (int i = 0; i < amount; i++) {
            file << (int) dis(gen) << endl;
        }
        file.close();

    }

    File(int amount) {

        fstream file;
        file.open("data.txt", ios::out);
        file << amount << endl;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1000, 1000);

        for (int i = 0; i < amount; i++) {
            file << (int) dis(gen) << endl;
        }
        file.close();

    }


};

class Menu {
public:

    void mode_interface() {
        cout << "-----------------------------------------------" << endl;
        cout << "     Welcome to Data Structures Time Analyzer " << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "               1. Test Mode" << endl;
        cout << "               2. Auto Mode" << endl;
        cout << "               3. About" << endl;
        cout << endl;
        cout << " Press 0 to Exit" << endl;
    }

    void about_interface() {
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
    }

    void interface() {
        int structure_number = 0;
        cout << "--------------------------------------------  " << endl;
        cout << "           Pick one Data Structure            " << endl;
        cout << "--------------------------------------------  " << endl;
        cout << "          1. Table                            " << endl;
        cout << "          2. Doubly Linked List               " << endl;
        cout << "          3. Heap                             " << endl;
        cout << "          4. Red-Black Tree                   " << endl;
        cout << endl;
        cout << " Press 0 to Return                            " << endl;

        cin >> structure_number;

        switch (structure_number) {
            case 1:
                break;
            case 2: {
                ListTwoDirection *list = new ListTwoDirection();
                cout << "     -------------------------------------------   " << endl;
                cout << "     Which operations would you like to execute:   " << endl;
                cout << "     -------------------------------------------   " << endl;
                cout << "              1. Add elements                      " << endl;
                cout << "              2. Remove element by index           " << endl;
                cout << "              3. Remove all elements from list     " << endl;
                cout << "              4. Find element by index             " << endl;

            }
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                exit(1);
                break;

            default:
                cout << "There is not such number on the list. Try Again !" << endl;

        }
    }
};

int main() {
    Menu *menu = new Menu();
    // menu->interface();
    // Array *array = new Array();
//
//    for (int i = 0; i < 100000; i++) {
//        array->add();
//    }
//
//    for (int i = 0; i < 99950; i++) {
//        array->remove();
//    }
    menu->about_interface();
    File *file = new File(20);


    //array->show();
    //array->add(0);
    //array->add();
    // array->find(49998);
    //   array->show();

    return 0;
}
