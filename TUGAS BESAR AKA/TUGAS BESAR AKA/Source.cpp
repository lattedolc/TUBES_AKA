#include "Header.h"
#include <iostream>

void createLinkedList(LinkedList& L) {
    L.first = nullptr;
}

address allocateNewNode(infotype matrix, int rows, int cols) {
    address newNode = new Node;
    newNode->matrix = matrix;
    newNode->rows = rows;
    newNode->cols = cols;
    newNode->next = nullptr;
    return newNode;
}

void insertLastMatriks2x2(LinkedList& L, infotype matrix, int rows, int cols) {
    address newNode = allocateNewNode(matrix, rows, cols);
    if (L.first == nullptr) {
        L.first = newNode;
    } else {
        address temp = L.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertLastMatriks3x3(LinkedList& L, infotype matrix, int rows, int cols) {
    address newNode = allocateNewNode(matrix, rows, cols);
    if (L.first == nullptr) {
        L.first = newNode;
    } else {
        address temp = L.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(const LinkedList& L) {
    address temp = L.first;
    while (temp != nullptr) {
        for (int i = 0; i < temp->rows; ++i) {
            for (int j = 0; j < temp->cols; ++j) {
                std::cout << temp->matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        temp = temp->next;
    }
}

bool iterativeSearch(const LinkedList& L, infotype targetMatrix) {
    address temp = L.first;
    while (temp != nullptr) {
        if ((temp->rows == 2 && temp->cols == 2)||(temp->rows == 3 && temp->cols == 3)) {
            bool isMatch = true;
            for (int i = 0; i < temp->rows; ++i) {
                for (int j = 0; j < temp->cols; ++j) {
                    if (temp->matrix[i][j] != targetMatrix[i][j]) {
                        isMatch = false;
                        break;
                    }
                }
                if (!isMatch) break;
            }
            if (isMatch) return true;
        }
        temp = temp->next;
    }
    return false;
}


bool recursiveSearch(const LinkedList& L, infotype targetMatrix) {
    if (L.first == nullptr) return false;

    address node = L.first;
    if ((node->rows == 2 && node->cols == 2)||(node->rows == 3 && node->cols == 3) ) {
        bool isMatch = true;
        for (int i = 0; i < node->rows; ++i) {
            for (int j = 0; j < node->cols; ++j) {
                if (node->matrix[i][j] != targetMatrix[i][j]) {
                    isMatch = false;
                    break;
                }
            }
            if (!isMatch) break;
        }
        if (isMatch) return true;
    }

    LinkedList rest;
    rest.first = node->next;
    return recursiveSearch(rest, targetMatrix);
}
