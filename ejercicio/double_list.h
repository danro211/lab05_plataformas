// double_list.h
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdlib.h>

// Definicion de la estructura para un nodo de la lista
typedef struct Node {
    int data;               // Datos que almacenara el nodo
    struct Node* prev;      // Puntero al nodo anterior
    struct Node* next;      // Puntero al nodo siguiente
} Node;

// Definicion de la estructura para la lista doblemente enlazada
typedef struct DoubleList {
    Node* head;             // Puntero al primer nodo de la lista
    Node* tail;             // Puntero al ultimo nodo de la lista
} DoubleList;

// Declaraciones de funciones
void insertAtFront(DoubleList* list, int data);
void insertAtEnd(DoubleList* list, int data);
void insertAtIndex(DoubleList* list, int data, int index);
void deleteNode(DoubleList* list, int data);
int findNode(DoubleList* list, int data);
void freeList(DoubleList* list);


#endif
