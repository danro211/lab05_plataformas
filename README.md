# Laboratorio #5: Programación Bajo Plataformas Abiertas

## Descripción General
Este repositorio contiene los códigos fuente desarrollados para el Laboratorio #5 del curso IE-0117. Este laboratorio se enfoca en la implementación y manipulación de listas doblemente enlazadas en C, incluyendo operaciones de inserción, eliminación, búsqueda y recorrido de la lista en ambas direcciones. Además, se asegura de que el código no tenga fugas de memoria mediante el uso de Valgrind.

## Estructura del Repositorio
El repositorio está organizado en un directorio principal con los archivos necesarios para el laboratorio, como se muestra a continuación:

### Directorio `ejercicio`
Contiene el código fuente, los archivos de cabecera, los ejecutables y otros archivos relacionados con las listas doblemente enlazadas.
- `double_list.c`: Implementación de las funciones para manejar la lista doblemente enlazada.
- `double_list.h`: Declaraciones de las estructuras y funciones para la lista doblemente enlazada.
- `main.c`: Implementación del programa principal que prueba las funcionalidades de la lista doblemente enlazada.
- `Makefile`: Archivo para automatizar la compilación del proyecto y la limpieza de archivos generados.
- `salida-valgrind.txt`: Resultado de la ejecución de Valgrind, demostrando que no hay fugas de memoria.
- `main`: Ejecutable compilado del código fuente.

## Compilación
Para compilar el proyecto, se utiliza un Makefile que automatiza el proceso. En un entorno Unix/Linux, se puede compilar y limpiar el proyecto con los siguientes comandos:

### Compilar el proyecto
```bash
make
