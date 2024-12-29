#include "Header.h"
#include <iostream>

int main() {
    LinkedList list2x2, list3x3;
    createLinkedList(list2x2);
    createLinkedList(list3x3);

    // Predefined 2x2 matrices
    int matrices2x2[5][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}},
        {{9, 10}, {11, 12}},
        {{13, 14}, {15, 16}},
        {{17, 18}, {19, 20}}
    };

    for (int n = 0; n < 5; ++n) {
        int** matrix = new int*[2];
        for (int i = 0; i < 2; ++i) {
            matrix[i] = new int[2];
            for (int j = 0; j < 2; ++j) {
                matrix[i][j] = matrices2x2[n][i][j];
            }
        }
        insertLastMatriks2x2(list2x2, matrix, 2, 2);
    }

    // Predefined 3x3 matrices
    int matrices3x3[5][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
        {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}},
        {{28, 29, 30}, {31, 32, 33}, {34, 35, 36}},
        {{37, 38, 39}, {40, 41, 42}, {43, 44, 45}}
    };

    for (int n = 0; n < 5; ++n) {
        int** matrix = new int*[3];
        for (int i = 0; i < 3; ++i) {
            matrix[i] = new int[3];
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] = matrices3x3[n][i][j];
            }
        }
        insertLastMatriks3x3(list3x3, matrix, 3, 3);
    }

    cout << "\n2x2 Matrices in Linked List:" << endl;
    displayList(list2x2);

    cout << "\n3x3 Matrices in Linked List:" << endl;
    displayList(list3x3);

    // User interaction for search
    int target, sizeChoice;
    cout << "Enter the matrix size you want to search (2 for 2x2, 3 for 3x3): ";
    cin >> sizeChoice;

    if (sizeChoice == 2) {
    int** targetMatrix = new int*[2];
    for (int i = 0; i < 2; ++i) {
        targetMatrix[i] = new int[2];
        for (int j = 0; j < 2; ++j) {
            cout << "Masukkan elemen matriks 2x2 [" << i << "][" << j << "]: ";
            cin >> targetMatrix[i][j];
        }
    }

   /* cout << "\nHasil Iterative Search untuk matriks 2x2:" << endl;
    if (iterativeSearch(list2x2, targetMatrix)) {
        cout << "Matriks ditemukan!" << endl;
    } else {
        cout << "Matriks tidak ditemukan." << endl;
    }
    */
    cout << "\nHasil Recursive Search untuk matriks 2x2:" << endl;
    if (recursiveSearch(list2x2, targetMatrix)) {
        cout << "Matriks ditemukan!" << endl;
    } else {
        cout << "Matriks tidak ditemukan." << endl;
    }

    for (int i = 0; i < 2; ++i) delete[] targetMatrix[i];
    delete[] targetMatrix;

} else if (sizeChoice == 3) {
    int** targetMatrix = new int*[3];
    for (int i = 0; i < 3; ++i) {
        targetMatrix[i] = new int[3];
        for (int j = 0; j < 3; ++j) {
            cout << "Masukkan elemen matriks 3x3 [" << i << "][" << j << "]: ";
            cin >> targetMatrix[i][j];
        }
    }

    /*cout << "\nHasil Iterative Search untuk matriks 3x3:" << endl;
    if (iterativeSearch(list3x3, targetMatrix)) {
        cout << "Matriks ditemukan!" << endl;
    } else {
        cout << "Matriks tidak ditemukan." << endl;
    }
    */
    cout << "\nHasil Recursive Search untuk matriks 3x3:" << endl;
    if (recursiveSearch(list3x3, targetMatrix)) {
        cout << "Matriks ditemukan!" << endl;
    } else {
        cout << "Matriks tidak ditemukan." << endl;
    }

    for (int i = 0; i < 3; ++i) delete[] targetMatrix[i];
    delete[] targetMatrix;
}

    return 0;
}
