#include <iostream>


using namespace std;

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
        if(temp != NULL) {
            while (temp != NULL) {
                cout << i++ << ". " << temp->data << endl;
                temp = temp->next;
            }
            cout << "size: " << size << endl;
            cout << "First: " << first->data << endl;
            cout << "Last: " << last->data << endl;
        }
        else{
            cout<<"The List is Empty"<<endl;
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
            cout << "Podano nieprawidłowy index" << endl;
        } else if (index > 0 && index < size - 1) { //usuwanie ze środka
            Element *temp = getPosition(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;

            size--;
        } else if (index == 0) { // usuwanie z pierwszego
            Element *temp = first;
            if(size>1) {
                first = temp->next;
                first->prev = NULL;
                delete temp;
                size--;
            }else {
                first = NULL;
                last = NULL;
                delete temp;
                size--;
            }
        } else if (index == size - 1) { //usuwanie z ostatniego
            Element *temp = last;
            last =last->prev;
            last->next =NULL;
            delete temp;
            size--;
        }
        cout << "Element on the position with index: " << index << " has been deleted" << endl;

    }
    void  removeAll(){
        int i  = size-1;
        while(i >= 0 ){
            remove(i);
            i--;
        }
    }

};
class Menu{
public:
    void interface(){
        int structure_number =0;
        cout<<"--------------------------------------------"<<endl;
        cout<<"     Pick one Data Structure to test "<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"          1. Table"<<endl;
        cout<<"          2. Doubly Linked List"<<endl;
        cout<<"          3. Heap"<<endl;
        cout<<"          4. Red-Black Tree"<<endl;
        cout<<endl;
        cout<<" Press 0 to Exit"<<endl;

        cin>>structure_number;

        switch(structure_number){
            case 1:
                break;
            case 2: {
                ListTwoDirection *list = new ListTwoDirection();
                cout<<"     -------------------------------------------"<<endl;
                cout<<"     Which operations would you like to execute: "<<endl;
                cout<<"     -------------------------------------------"<<endl;
                cout<<"1. Add elements"<<endl;
                cout<<"2. Remove element at index"<<endl;
                cout<<"3. Remove all elements from list"<<endl;
                cout<<"4. Show list"<<endl;
                cout<<"5. Results of time measurement"<<endl;
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
                cout<<"There is not such number on the list. Try Again !"<<endl;
                cout<<"test change"<<endl;
                cout<<"changes made on test branch"<<endl;
        }
    }
};

int main() {
    Menu *menu = new Menu();
    menu->interface();
    return 0;
}
