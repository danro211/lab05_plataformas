// main.c
#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList list = {NULL, NULL}; // Inicializar una lista vacia

    // Insertar algunos nodos al inicio para variedad
    insertAtFront(&list, 10);
    insertAtFront(&list, 20);

    // Insertar nodos al final
    insertAtEnd(&list, 30);
    insertAtEnd(&list, 40);

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

