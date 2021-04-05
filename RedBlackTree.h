//
// Created by Kamil Bonkowski on 02/04/2021.
//

#ifndef DATASTRUCTURES_REDBLACKTREE_H
#define DATASTRUCTURES_REDBLACKTREE_H

class BstNode {
public:
    int data;
    bool isRed;
    BstNode *left;
    BstNode *right;

};

class RedBlackTree {
public:

    BstNode *root = nullptr;

    BstNode *insert(int data) {
     root = insert(root, data);
    }

    BstNode *insert(BstNode *root, int data) {
        if (root == nullptr) {
            root = getNewNode(data);

        } else if (data <= root->data) {
            root->left = insert(root->left, data);

        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    BstNode *getNewNode(int data) {
        BstNode *newNode = new BstNode();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        newNode->isRed = true;
        return newNode;
    }

    void show(BstNode *root) {

//       // cout << "Current Root: " << root->data << endl;
//        if(root->left != nullptr)
//        cout << "Lewy: " << root->left->data << endl;
//        if(root->right != nullptr)
//        cout << "Prawy: " << root->right->data << endl;

    }

};


#endif //DATASTRUCTURES_REDBLACKTREE_H
