//#pragma once
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    int height;
//    Node* left;
//    Node* right;
//
//    Node(int d = 0, int h = 0) {
//
//        data = d;
//        height = h;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//class AVLTree {
//
//public:
//    Node* root;
//
//    AVLTree() {
//
//        root = NULL;
//    }
//
//    int height(Node* node) {
//
//        if (node != NULL) {
//
//            return node->height;
//        }
//        else {
//
//            return 0;
//        }
//    }
//
//    int balance_factor(Node* node) {
//        
//        if (node != NULL) {
//
//            return height(node->left) - height(node->right);
//        }
//        else {
//
//            return 0;
//        }
//    }
//
//    Node* left_rotate(Node* x) {
//
//        Node* y = x->right;
//        Node* T2 = y->left;
//
//        y->left = x;
//        x->right = T2;
//
//        x->height = max(height(x->left), height(x->right)) + 1;
//        y->height = max(height(y->left), height(y->right)) + 1;
//
//        return y;
//    }
//
//    Node* right_rotate(Node* y) {
//        Node* x = y->left;
//        Node* T2 = x->right;
//
//        x->right = y;
//        y->left = T2;
//
//        y->height = max(height(y->left), height(y->right)) + 1;
//        x->height = max(height(x->left), height(x->right)) + 1;
//
//        return x;
//    }
//
//    Node* insert(Node* node, int data) {
//        if (!node) return new Node(data);
//
//        if (data < node->data) node->left = insert(node->left, data);
//        else if (data > node->data) node->right = insert(node->right, data);
//        else return node;
//
//        node->height = max(height(node->left), height(node->right)) + 1;
//
//        int balance = balance_factor(node);
//
//        if (balance > 1) {
//            if (data < node->left->data) return right_rotate(node);
//            else {
//                node->left = left_rotate(node->left);
//                return right_rotate(node);
//            }
//        }
//
//        if (balance < -1) {
//            if (data > node->right->data) return left_rotate(node);
//            else {
//                node->right = right_rotate(node->right);
//                return left_rotate(node);
//            }
//        }
//
//        return node;
//    }
//
//    Node* minValueNode(Node* node) {
//        Node* current = node;
//        while (current->left) current = current->left;
//        return current;
//    }
//
//    Node* delete_node(Node* node, int data) {
//        if (!node) return nullptr;
//
//        if (data < node->data) node->left = delete_node(node->left, data);
//        else if (data > node->data) node->right = delete_node(node->right, data);
//        else {
//            if (!node->left || !node->right) {
//                Node* temp = node->left ? node->left : node->right;
//                if (!temp) node = nullptr;
//                else *node = *temp;
//                delete temp;
//            }
//            else {
//                Node* temp = minValueNode(node->right);
//                node->data = temp->data;
//                node->right = delete_node(node->right, temp->data);
//            }
//        }
//
//        if (!node) return nullptr;
//
//        node->height = max(height(node->left), height(node->right)) + 1;
//        int balance = balance_factor(node);
//
//        if (balance > 1) {
//            if (balance_factor(node->left) >= 0) return right_rotate(node);
//            else {
//                node->left = left_rotate(node->left);
//                return right_rotate(node);
//            }
//        }
//
//        if (balance < -1) {
//            if (balance_factor(node->right) <= 0) return left_rotate(node);
//            else {
//                node->right = right_rotate(node->right);
//                return left_rotate(node);
//            }
//        }
//
//        return node;
//    }
//
//    bool search(Node* node, int data) {
//        if (!node) {
//
//            return false;
//        }
//
//        if (data < node->data) {
//
//            return search(node->left, data);
//        }
//
//        else if (data > node->data) {
//
//            return search(node->right, data);
//        }
//
//        return true;
//    }
//
//    int size(Node* node) {
//        if (!node) return 0;
//        return 1 + size(node->left) + size(node->right);
//    }
//};
