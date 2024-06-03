// main.c
#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList list = {NULL, NULL}; // Inicializar una lista vacia

    insertAtEnd(&list, 10); // Agregar al final
    insertAtFront(&list, 20); // Agregar al inicio
    insertAtIndex(&list, 30, 1); // Agregar en la posicion 1
    insertAtIndex(&list, 40, 3);// Agregar en la posicion 3
    insertAtEnd(&list, 30); // Agregar al final
    deleteNode(&list, 30); // Eliminar el primer nodo con el valor 30
    
    // Imprimir la lista
    Node* current = list.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Libera la lista
    freeList(&list);

    return 0;
}

