// main.c
#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList list = {NULL, NULL}; // Inicializar una lista vacia

    // Insertar valores iniciales
    insertAtEnd(&list, 1);
    insertAtEnd(&list, 2);
    insertAtEnd(&list, 3);
    insertAtEnd(&list, 4);
    insertAtEnd(&list, 5);

    printf("Lista inicial:\n");
    printListForward(&list);

     // Secuencia de operaciones en la lista
    insertAtEnd(&list, 10); // Agregar al final
    insertAtFront(&list, 20); // Agregar al inicio
    insertAtIndex(&list, 30, 1); // Agregar en la posicion 1
    insertAtIndex(&list, 40, 3); // Agregar en la posicion 3
    insertAtEnd(&list, 30); // Agregar al final

    printf("\nLista despues de las inserciones:\n");
    printListForward(&list);

    // Eliminar el primer nodo con el valor 30
    deleteNode(&list, 30); 

    printf("\nLista despues de eliminar el primer nodo con el valor 30:\n");
    printListForward(&list);

    // Prueba de la funcion findNode
    printf("\nResultados de busqueda:\n");
    findNode(&list, 20); // Buscar el nodo con valor 20
    findNode(&list, 30); // Buscar el nodo con valor 30

    // Funciones de impresion
    printListForward(&list); // Imprimir la lista hacia adelante
    printListBackward(&list); // Imprimir la lista hacia atras

    // Libera la lista
    freeList(&list);

    return 0;
}