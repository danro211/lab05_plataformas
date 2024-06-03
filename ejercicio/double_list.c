// double_list.c
#include "double_list.h"

// Funcion para insertar un nodo al inicio de la lista
void insertAtFront(DoubleList* list, int data) {
    Node* newNode = malloc(sizeof(Node)); // Crear un nuevo nodo
    if (newNode == NULL) {
        return; // Si malloc falla, salir de la funcion
    }
    newNode->data = data; // Asignar datos al nuevo nodo
    newNode->prev = NULL; // El nuevo nodo sera el primero, asi que no tiene anterior
    newNode->next = list->head; // El siguiente del nuevo nodo es el actual cabeza de la lista

    if (list->head != NULL) {
        list->head->prev = newNode; // Ajustar el anterior de la antigua cabeza
    } else {
        list->tail = newNode; // Si la lista estaba vacia, el nuevo nodo tambien es la cola
    }
    list->head = newNode; // Ahora la cabeza de la lista es el nuevo nodo
}

// Funcion para insertar un nodo al final de la lista
void insertAtEnd(DoubleList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        return; // Manejo de error, si malloc falla
    }
    newNode->data = data;  // Asignar el dato al nuevo nodo
    newNode->next = NULL;  // El siguiente nodo sera NULL porque es el final de la lista

    if (list->tail == NULL) {  // La lista esta vacia
        newNode->prev = NULL; // No hay nodos anteriores
        list->head = list->tail = newNode; // El nuevo nodo es ahora la cabeza y la cola
    } else {  // La lista tiene al menos un nodo
        newNode->prev = list->tail; // El anterior del nuevo nodo es el actual final
        list->tail->next = newNode; // El siguiente del actual final es el nuevo nodo
        list->tail = newNode; // Actualizar la cola de la lista al nuevo nodo
    }
}

// Funcion para insertar nodo en indice especifico
void insertAtIndex(DoubleList* list, int data, int index) {
    if (index < 0) {
        return; // Index invalido
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        return; // Fallo de malloc
    }
    newNode->data = data;

    if (index == 0) { // Insertar al inicio
        insertAtFront(list, data);
        return;
    }

    Node* current = list->head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL) { // Index fuera de los limites, insertar al final
        insertAtEnd(list, data);
    } else { // Insertar entre current y current->next
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (newNode->next == NULL) { // Actualizar la cola si es necesario
            list->tail = newNode;
        }
    }
}

// Funcion para eliminar nodo segun data
void deleteNode(DoubleList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) { // No es el primer nodo
                current->prev->next = current->next;
            } else { // Es el primer nodo
                list->head = current->next;
            }
            if (current->next != NULL) { // No es el ultimo nodo
                current->next->prev = current->prev;
            } else { // Es el ultimo nodo
                list->tail = current->prev;
            }
            free(current);
            return; // Salir despues de eliminar el primer nodo encontrado
        }
        current = current->next;
    }
}

// Funcion para liberar la lista
void freeList(DoubleList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next; // Guarda el siguiente nodo
        free(current); // Libera el nodo actual
        current = next; // Mueve a la siguiente posicion
    }
    list->head = NULL; // Asegura que la cabeza de la lista es NULL
    list->tail = NULL; // Asegura que la cola de la lista es NULL
}

