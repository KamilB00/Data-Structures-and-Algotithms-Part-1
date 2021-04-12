//
// Created by Kamil Bonkowski on 02/04/2021.
//

#ifndef DATASTRUCTURES_REDBLACKTREE_H
#define DATASTRUCTURES_REDBLACKTREE_H
#include <iostream>

#define BLACK 0
#define RED 1
#define BOTH_BLACK 2

using namespace std;


class Node {
    int color;
    int data;

public:
    Node *parent;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        parent = left = right = NULL;
        color = RED;
    }

    Node(int data, int color) {
        this->data = data;
        this->color = color;
        parent = left = right = NULL;
    }

    void setColor(int color) {
        this->color = color;
    }

    int getColor() {
        return this->color;
    }

    int getData() {
        return this->data;
    }

    void setData(int data) {
        this->data = data;
    }

};

Node *AddToTree(Node *root, Node *node) {
    if (root == NULL)
        return node;
    if (root->getData() > node->getData()) {
        root->left = AddToTree(root->left, node);
        root->left->parent = root;
    } else if (root->getData() < node->getData()) {
        root->right = AddToTree(root->right, node);
        root->right->parent = root;
    }
    return root;

}

class RedBlackTree {

    Node *root;

public:
    RedBlackTree(const string &file_name) {
        string amount;
        string element;
        fstream file;
        file.open(file_name, ios::in);

        if (!file.good()) {
            cout << "File" << file_name << ".txt does not exist ! [RB TREE]" << endl;
        } else {
            getline(file, amount);

            for (int i = 0; i < atoi(amount.c_str()); i++) {
                getline(file, element);
                addNode(atoi(element.c_str()));
            }
            cout << "RB Tree filled with data !" << endl;
        }
    }

    Node *getRoot() {
        return root;
    }

    //Swapping nodes color
    void swapNodeColor(Node *node1, Node *node2) {
        int tempColor = node1->getColor();
        node1->setColor(node2->getColor());
        node2->setColor(tempColor);

    }

    void fillTheTree(int data){
        Node *newNode = new Node(data);
        this->root = AddToTree(this->root, newNode);
        fixInsertViolation(newNode);
    }

    int getBlackHeight(Node *root) {
        if (root == NULL || root->getData() == -1)
            return 0;
        if (root->getColor() == BLACK) {
            return 1 + max(getBlackHeight(root->left), getBlackHeight(root->right));
        } else
            return max(getBlackHeight(root->left), getBlackHeight(root->right));
    }

    Node *getMaxValueNode(Node *root) {
        if (root == NULL)
            return NULL;
        else if (root->right == NULL)
            return root;
        else
            return getMaxValueNode(root->right);
    }


    Node *getGrandParent(Node *node) {
        if ((node != NULL) && (node->parent != NULL))
            return node->parent->parent;
        return NULL;

    }

    void rotateLeft(Node *&node) {
        Node *rightNode = node->right;
        Node *nodeParent = node->parent;
        node->right = rightNode->left;

        if (node->right != NULL)
            node->right->parent = node;

        rightNode->parent = nodeParent;

        if (node->parent == NULL)
            this->root = rightNode;
        else if (node == node->parent->left)
            node->parent->left = rightNode;
        else
            node->parent->right = rightNode;

        rightNode->left = node;
        node->parent = rightNode;
    }

    void rotateRight(Node *&node) {
        Node *nodeLeft = node->left;
        node->left = nodeLeft->right;

        if (node->left != NULL)
            node->left->parent = node;

        nodeLeft->parent = node->parent;

        if (node->parent == NULL)
            this->root = nodeLeft;
        else if (node == node->parent->left)
            node->parent->left = nodeLeft;
        else
            node->parent->right = nodeLeft;

        nodeLeft->right = node;
        node->parent = nodeLeft;

    }


    void fixInsertViolation(Node *&node) {

        Node *parentNode = NULL;
        Node *grandParentNode = NULL;

        //if node is root then color node to black
        //if node is red then it's parent can not be red
        while ((node != root) && (node->getColor() != BLACK) && (node->parent->getColor() == RED)) {

            parentNode = node->parent;
            grandParentNode = getGrandParent(node);


            //  NODE IS PARENT LEFT CHILD
            if (parentNode == grandParentNode->left) {

                Node *uncleNode = grandParentNode->right;

                /* Case: 1
                   The aunt of node is also red  FLIP COLORS
                   */
                if (uncleNode != NULL && uncleNode->getColor() == RED) {
                    grandParentNode->setColor(RED);
                    parentNode->setColor(BLACK);
                    uncleNode->setColor(BLACK);
                    node = grandParentNode;
                } else {
                    /* Case : 2
                       node is right child of its parent ROTATE LEFT
                       */
                    if (node == parentNode->right) {
                        rotateLeft(parentNode);

                        node = parentNode;
                        parentNode = node->parent;
                    }

                    /* Case : 3
                       node is left child of its parent ROTATE RIGHT
                      */
                    rotateRight(grandParentNode);
                    swapNodeColor(parentNode, grandParentNode);
                    node = parentNode;
                }
            }

                // NODE IS PARENT RIGHT CHILD

            else {
                Node *uncleNode = grandParentNode->left;

                /*  Case : 1
                    The aunt of node is also red FLIP COLOR */
                if ((uncleNode != NULL) && (uncleNode->getColor() == RED)) {
                    grandParentNode->setColor(RED);
                    parentNode->setColor(BLACK);
                    uncleNode->setColor(BLACK);
                    node = grandParentNode;
                } else {
                    /* Case : 2
                       node is left child of its parent ROTATE RIGHT
                        */
                    if (node == parentNode->left) {
                        rotateRight(parentNode);
                        node = parentNode;
                        parentNode = node->parent;
                    }

                    /* Case : 3
                       node is right child of its parent ROTATE LEFT
                        */
                    rotateLeft(grandParentNode);
                    swapNodeColor(parentNode, grandParentNode);
                    node = parentNode;
                }
            }
        }

        root->setColor(BLACK);
    }

    void addNode(int data) {
        Node *newNode = new Node(data);

        this->root = AddToTree(this->root, newNode);

        fixInsertViolation(newNode);

    }

    Node *getDeletingNodePosition(Node *root, int value) {
        if (root == NULL)
            return root;
        //if value is in right subtree
        if (value > root->getData())
            return getDeletingNodePosition(root->right, value);

            //if value is in left subtree
        else if (value < root->getData())
            return getDeletingNodePosition(root->left, value);

        //if value is in root
        if (root->left == NULL or root->right == NULL)
            return root;

        Node *temp = getMaxValueNode(root->left);
        root->setData(temp->getData());
        return getDeletingNodePosition(root->left, temp->getData());
    }

    void fixViolation(Node *node) {
        if (node == NULL)
            return;

        if (node == root) {
            root = NULL;
            return;
        }

        //if one of node or its child is red
        if (node->getColor() == RED || node->left->getColor() == RED || node->right->getColor() == RED) {
            Node *child = node->left != NULL ? node->left : node->right;

            //if node is left child
            if (node == node->parent->left) {
                node->parent->left = child;
                if (child != NULL) {
                    child->parent = node->parent;
                    child->setColor(BLACK);
                }
                delete (node);
            }
                //if node is right child
            else {
                node->parent->right = child;
                if (child != NULL) {
                    child->parent = node->parent;
                    child->setColor(BLACK);
                }
                delete (node);
            }
        }
            //if both node and it's child is black
        else {
            Node *child = NULL;
            Node *parent = NULL;
            Node *ptr = node;
            ptr->setColor(BOTH_BLACK);
            while (ptr != root && ptr->getColor() == BOTH_BLACK) {
                parent = ptr->parent;

                if (ptr == parent->left) {
                    child = parent->right;

                    if (!child->right) {
                        child->right = new Node(-1, BLACK);
                        child->right->parent = child;
                    }
                    if (!child->left) {
                        child->left = new Node(-1, BLACK);
                        child->left->parent = child;
                    }

                    //If child is red
                    //Make child black
                    //Make parent red
                    //Rotate parent left
                    if (child->getColor() == RED) {
                        child->setColor(BLACK);
                        parent->setColor(RED);
                        rotateLeft(parent);
                    }

                    else {
                        //If child is black
                        //Make child red
                        //If parent is black make parent double black
                        //If parent is red make parent black
                        if (child->left->getColor() == BLACK && child->right->getColor() == BLACK) {
                            child->setColor(RED);
                            if (parent->getColor() == RED)
                                parent->setColor(BLACK);
                            else
                                parent->setColor(BOTH_BLACK);
                            ptr = parent;
                        } else {
                            if (child->right->getColor() == BLACK) {
                                child->left->setColor(BLACK);
                                child->setColor(RED);
                                rotateRight(child);
                                child = parent->right;
                            }
                            child->setColor(parent->getColor());
                            parent->setColor(BLACK);
                            child->right->setColor(BLACK);
                            rotateLeft(parent);
                            break;
                        }
                    }
                } else {
                    child = parent->left;
                    if (!child->right) {
                        child->right = new Node(-1, BLACK);
                        child->right->parent = child;
                    }
                    if (!child->left) {
                        child->left = new Node(-1, BLACK);
                        child->left->parent = child;
                    }
                    if (child->getColor() == RED) {
                        child->setColor(BLACK);
                        parent->setColor(RED);
                        rotateRight(parent);
                    } else {
                        if (child->left->getColor() == BLACK && child->right->getColor() == BLACK) {
                            child->setColor(RED);
                            if (parent->getColor() == RED)
                                parent->setColor(BLACK);
                            else
                                parent->setColor(BOTH_BLACK);
                            ptr = parent;
                        } else {
                            if (child->left->getColor() == BLACK) {
                                child->right->setColor(BLACK);
                                child->setColor(RED);
                                rotateLeft(child);
                                child = parent->left;
                            }
                            child->setColor(parent->getColor());
                            parent->setColor(BLACK);
                            child->left->setColor(BLACK);
                            rotateRight(parent);
                            break;
                        }
                    }
                }
            }
            if (node == node->parent->left)
                node->parent->left = NULL;
            else
                node->parent->right = NULL;
            delete (node);
            root->setColor(BLACK);
        }

    }

    void deleteNode(int data) {
        Node *nodeToDelete = getDeletingNodePosition(this->root, data);
        if (!nodeToDelete->right) {
            nodeToDelete->right = new Node(-1, BLACK);
            nodeToDelete->right->parent = nodeToDelete;
        }
        if (!nodeToDelete->left) {
            nodeToDelete->left = new Node(-1, BLACK);
            nodeToDelete->left->parent = nodeToDelete;
        }
        fixViolation(nodeToDelete);
    }

    void preorderTraversal(Node *root) {
        if (root != NULL and root->getData() != -1) {
            cout << root->getData() << " " << (root->getColor() == 1 ? "[RED]" : "[BLACK] ") << endl;
            if (root->parent != NULL) {
                cout << "Parent [" << root->parent->getData() << "] "
                     << (root->parent->getColor() == 1 ? "[RED]" : "[BLACK] ") << endl;
            } else {
                cout << "Parent [NULL] [BLACK]" << endl;

            }
            if (root->left != NULL) {
                cout << "Left Child [" << root->left->getData() << "] "
                     << (root->left->getColor() == 1 ? "[RED]" : "[BLACK] ") << endl;
            } else {
                cout << "Left Child [NULL] [BLACK]" << endl;
            }
            if (root->right != NULL) {
                cout << "Right Child [" << root->right->getData() << "]"
                     << (root->right->getColor() == 1 ? "[RED]" : "[BLACK] ") << endl;
            } else {
                cout << "Right Child [NULL] [BLACK]" << endl;
            }
            cout << endl;
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    bool find(Node *node, int data) {
        if (node == NULL) return false;
        else if (node->getData() == data) return true;
        else if (data <= node->getData()) return find(root->left, data);
        else return find(node->right, data);
    }



//    void show() {
//       preorderTraversal(root);
//    }

};


#endif //DATASTRUCTURES_REDBLACKTREE_H
