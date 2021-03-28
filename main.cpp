#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>


using namespace std;

class Array {

public:
    int size = 0;
    int *arr_dyn = nullptr;
    int *arr_dyn_new = nullptr;

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
        cout << "elapsed time [Array add to end]: " << elapsed_time << " ns" << endl; //END [ARRAY ADD TO END]
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
            cout<<"Element deleted !"<<endl;
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

class Element {
public:
    int data = 0;
    Element *next = nullptr;
    Element *prev = nullptr;

    Element(int d) {
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class ListTwoDirection {
    int size = 0;
    Element *first = nullptr;
    Element *last = nullptr;

    Element *getPosition(unsigned long long int index) { //pozycja numerowna od 0
        Element *temp = first;
        unsigned long long int pos = index;
        int i = 0;

        if (index < 0 || index > size) {
            return nullptr;
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
        if (temp != nullptr) {
            while (temp != nullptr) {
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
                first->prev = nullptr;
                delete temp;
                size--;
            } else {
                first = nullptr;
                last = nullptr;
                delete temp;
                size--;
            }
        } else if (index == size - 1) { //usuwanie z ostatniego
            Element *temp = last;
            last = last->prev;
            last->next = nullptr;
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


        cout << "How many numbers should be created ? :";
        cin >> amount;

        do {
            cout << "Lower Bounds: ";
            cin >> lower;
            cout << "Upper Bounds: ";
            cin >> upper;

            if (lower >= upper) {
                cout << "Incorrect range, please try again !" << endl;
            }
        } while (lower >= upper);

        fstream file;
        file.open("data.txt", ios::out);
        cout << "File created successfully" << endl;
        file << amount << endl;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(lower, upper);

        cout << "Please wait, values are being loaded to the file..." << endl;
        for (int i = 0; i < amount; i++) {
            file << (int) dis(gen) << endl;
        }
        file.close();
        cout << "Filling accomplished successfully !" << endl;

    }

    File(int amount) {

        fstream file;
        file.open("data.txt", ios::out);
        cout << "File created successfully" << endl;
        file << amount << endl;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1000, 1000);
        cout << "Please wait, values are being loaded to the file..." << endl;
        for (int i = 0; i < amount; i++) {
            file << (int) dis(gen) << endl;
        }
        file.close();

        cout << "Filling accomplished successfully !" << endl;
    }


};

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
        cout << "               3. About" << endl;
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

    int operations_interface(string name) {
        int choice = 0;

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

        do {
            cin >> choice;
            if (choice >= 0 && choice <= 6) {
                return choice;
            } else {
                cout << "No operation found try again !" << endl;
            }
        } while (choice < 0 || choice > 6);
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

                                    //#1 Add to table
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

                                    //#2 Add to table by index
                                case 2: {
                                    int index = 0;
                                    visit_count++;
                                    cout << "index: ";
                                    cin >> index;
                                    array->add(index);

                                    if (visit_count > 0) {
                                        do {
                                            cout << "Do you want to add more numbers [y/n] ?  " << endl;
                                            cin >> add_more;

                                            if (add_more == 'y') {
                                                cout << "index: ";
                                                cin >> index;
                                                array->add(index);
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
                                    int index =0;
                                    cout<<"Index of the value: ";
                                    cin>>index;

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
                       int  operation =  operations_interface("List");

                        switch(operation){
                            //List OPTIONS

                            //#0 Return to previous screen
                            case 0:
                            {
                                break;
                            }

                        }

                        break;
                    }
//*******************************************************************************************************************

                        //HEAP DATA STRUCTURE
                    case 3: {
                        clearScreen();
                        operations_interface("Heap");
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


int main() {
    Menu *menu = new Menu();
    menu->mode_interface();

    return 0;
}
