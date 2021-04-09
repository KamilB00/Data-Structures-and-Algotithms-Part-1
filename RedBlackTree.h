//
// Created by Kamil Bonkowski on 02/04/2021.
//

#ifndef DATASTRUCTURES_REDBLACKTREE_H
#define DATASTRUCTURES_REDBLACKTREE_H

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



    Node *insert(Node *root_node, Node *ptr) {
        // root_node - korzeń
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

    void rotateLeft(Node *&root, Node *&ptr) {
        // ptr - to co przekazuje (5)
        // ptr_right - prawy potomek tego co przekazuje (10)

        Node *ptr_right = ptr->right;
        ptr->right = ptr_right->left;

        if (ptr->right != NULL) {
            ptr->right->parent = ptr; //
        }
        ptr_right->parent = ptr->parent;
        if (ptr->parent == NULL) {
            root = ptr_right;
        } else if (ptr == ptr->parent->left) {
            ptr->parent->left = ptr_right; // podpinanie do rodzica z lewej
        } else {
            ptr->parent->right = ptr_right; // podpinanie do rodzica z prawej
        }
        ptr_right->left = ptr;
        ptr->parent = ptr_right;
    }

    void rotateRight(Node *&root, Node *&ptr) {
        Node *ptr_left = ptr->left;
        ptr->left = ptr_left->right;

        if (ptr->left != NULL) {
            ptr->left->parent = ptr;
        }
        ptr_left->parent = ptr->parent;
        if (ptr->parent == NULL) {
            root = ptr_left;
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

    void evaluateRoot(Node* node){
        if(!hasParent(node)){
            root = node;
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
        if (root_node->parent == NULL) {
            root_node->isRed = false;
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
