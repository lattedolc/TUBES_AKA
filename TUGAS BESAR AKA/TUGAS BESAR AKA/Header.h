#ifndef MATRIX_SEARCH_H
#define MATRIX_SEARCH_H
using namespace std;
typedef int** infotype;
typedef struct Node* address;

struct Node {
    infotype matrix;
    int rows;
    int cols;
    address next;
};

struct LinkedList {
    address first;
};

void createLinkedList(LinkedList& L);
address allocateNewNode(infotype matrix, int rows, int cols);
void insertLastMatriks2x2(LinkedList& L, infotype matrix, int rows, int cols);
void insertLastMatriks3x3(LinkedList& L, infotype matrix, int rows, int cols);
void displayList(const LinkedList& L);

bool iterativeSearch(const LinkedList& L, infotype targetMatrix);
bool recursiveSearch(const LinkedList& L, infotype targetMatrix);


#endif // HEADER_H_INCLUDED
