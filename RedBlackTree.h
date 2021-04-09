//
// Created by Kamil Bonkowski on 02/04/2021.
//

#ifndef DATASTRUCTURES_REDBLACKTREE_H
#define DATASTRUCTURES_REDBLACKTREE_H
#include <string>

class Node {
public:
    int data;
    bool isRed;
    Node *parent, *left, *right;


    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        this->isRed = true;
    }
};

class RedBlackTree {
public:
    Node *root = nullptr;

    Node *getNewNode(int data) {
        Node *newNode = new Node(data);
        return newNode;
    }

    void add(){
        int value =0;
        cout<<"Value of a node: "<<endl;
        cin>>value;
        insert(root, getNewNode(value));
    }

    Node *insert(Node *root_node, Node *ptr) {
        // root_node - korzeń główny
        // ptr - to co dodajemy do drzewa


        if (root_node == NULL) {   //  first adding
            return ptr;
        }

        evaluateRoot(root_node);

        if (ptr->data < root_node->data) {   // adding to left subtree
            root_node->left = insert(root_node->left, ptr);
            root_node->left->parent = root_node;
        } else if (ptr->data > root_node->data) { // adding to right subtree
            root_node->right = insert(root_node->right, ptr);
            root_node->right->parent = root_node;
        }

        return root_node;
    }

    void rotateLeft(Node *&root_node, Node *&ptr) {
        // ptr - to co przekazuje (5)
        // ptr_right - prawy potomek tego co przekazuje (10)

        Node *ptr_right = ptr->right;
        ptr->right = ptr_right->left;

        if (ptr->right != NULL) {
            ptr->right->parent = ptr; //
        }
        ptr_right->parent = ptr->parent;
        if (ptr->parent == NULL) {
            root_node = ptr_right;
        } else if (ptr == ptr->parent->left) {
            ptr->parent->left = ptr_right; // podpinanie do rodzica z lewej
        } else {
            ptr->parent->right = ptr_right; // podpinanie do rodzica z prawej
        }
        ptr_right->left = ptr;
        ptr->parent = ptr_right;
    }

    void rotateRight(Node *&root_node, Node *&ptr) {
        Node *ptr_left = ptr->left;
        ptr->left = ptr_left->right;

        if (ptr->left != NULL) {
            ptr->left->parent = ptr;
        }
        ptr_left->parent = ptr->parent;
        if (ptr->parent == NULL) {
            root_node = ptr_left;
        } else if (ptr == ptr->parent->left) {
            ptr->parent->left = ptr_left;
        } else {
            ptr->parent->right = ptr_left;
        }
        ptr_left->right = ptr_left;
        ptr->parent = ptr_left;
    }

    Node *getLeftAunt(Node *root_node) {
        return root_node->parent->left;
    }

    Node *getRightAunt(Node *root_node) {
        return root_node->parent->right;
    }

    void evaluateRoot(Node *node) {
        if (!hasParent(node)) {
            root = node;
        }
    }

    void evaluateTree(Node *node) {
        Node *temp = nullptr;

        if (!root->isRed) {
            temp = node->right;
            if (node->isRed && temp->isRed && hasParent(node)) {
                if (isLeftAuntRed(node)) {
                    cout<<"LEFT AUNT IS RED"<<endl;

                } else {
                    cout<<"LEFT AUNT IS BLACK"<<endl;

                }
            }

            temp = node->left;

            if (node->isRed && temp->isRed && hasParent(node)) {
                if (node->isRed && temp->isRed && hasParent(node)) {
                    if (isRightAuntRed(node)) {
                        cout<<"RIGHT AUNT IS RED"<<endl;

                    } else {
                        cout<<"RIGHT AUNT IS BLACK"<<endl;

                    }
                }
            }


        } else if (root->isRed) {
            evaluateRoot(root);
            evaluateTree(node);
        } else {
            cout << "Tree is Valid " << endl;
        }
    }

    bool hasParent(Node *node) {
        if (node->parent != NULL) return true;
        else return false;
    }

    void colorFlip(Node *root_node) {
        root_node->isRed = false;
        if (root_node->parent->left == root) {
            getRightAunt(root_node)->isRed = false;
        } else if (root_node->parent->right == root) {
            getLeftAunt(root_node)->isRed = false;
        }

    }

    void colorFlipRoot() {
        if (root->isRed)
            root->isRed = false;
    }

    bool isLeftAuntRed(Node *root_node) {
        if (root_node->parent->right == root_node) {
            if (getLeftAunt(root_node) != NULL) {
                // Left Aunt is RED OR BLACK
                return getLeftAunt(root_node)->isRed;
            } else {
                return false;
            }

        }
    }

    bool isRightAuntRed(Node *root_node) {
        if (root_node->parent->left == root_node) {
            if (getRightAunt(root_node) != NULL) {
                //Right Aunt is RED OR BLACK
                return getLeftAunt(root_node)->isRed;
            } else {
                //Right Aunt is BLACK
                return false;
            }
        }

    }

    void fixViolation(Node *root_node, Node *ptr) {
        //RULES
        // NULL = BLACK

        // 1. BLACK AUNT ROTATE

        // right child left subtree : RL rotation
        // right child right subtree : L rotation
        // left child right subtree : LR rotation
        // left child left subtree : R rotation

        // After rotation
        //      BLACK
        //      /   \
        //     RED  RED

        // 2. RED AUNT COLOR FLIP

        // After color flip
        //          RED
        //         /   \
        //      BLACK  BLACK

        //ONLY ONE NODE IN THE TREE


    }

    int rootVisitCounter = 0;
    Node* preOrderTraversal(Node* node){
      //  NLR


      Node* temp = NULL;
     if(rootVisitCounter < 2){

          string result = (node->isRed) ? "RED" : "BLACK";
          cout<<node->data<<" ["<<result<<" ]"<<endl;


      if(node->left != NULL){
          preOrderTraversal(node->left);
      }
      else if (node->right != NULL){
        preOrderTraversal(node);
      }

        if (node->left == NULL && node->right == NULL) {

            do {
                temp = node; //setting actual node value
                node = node->parent; //setting parent value to be current node
                if (node == root)
                    rootVisitCounter++;

            } while (node->right == NULL || temp == node->right);

            preOrderTraversal(node->right);
        }
    }


    }

    bool find(Node *root, int data) {
        if (root == NULL) return false;
        else if (root->data == data) return true;
        else if (data <= root->data) return find(root->left, data);
        else return find(root->right, data);
    }

    void show() {
        cout << "Current Root: " << root->data << endl;
        if (root->left != nullptr)
            cout << "Lewy: " << root->left->data << endl;
        if (root->right != nullptr)
            cout << "Prawy: " << root->right->data << endl;
    }

};


#endif //DATASTRUCTURES_REDBLACKTREE_H
