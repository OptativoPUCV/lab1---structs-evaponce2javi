#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int *vector, int tam) {
  int mayor = vector[0];
  for (int i = 1; i < tam; i++) {
    if (vector[i] > mayor) {
      mayor = vector[i];
    }
  }
  return mayor;
}
/*  return 0;

}*/

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  // void invertir(int *aarreglo, int tamanio) {
  int aux[size];
  for (int i = 0; i < size; i++) {
    aux[i] = arr[i];
  }
  int k = 0;
  int j = size - 1;
  for (int i = 0; i < size; i++) {
    arr[k] = aux[j];
    k++;
    j--;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { // return NULL; }
  // int *filtrarPares(int *arreglo, int talla, int *nuevaTalla) {
  int *vectorPares = malloc(size * sizeof(int));
  if (vectorPares == NULL)
    exit(EXIT_FAILURE);

  (*newSize) = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      vectorPares[*newSize] = arr[i];
      (*newSize)++;
    }
  }
  return vectorPares;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int tamanio1, int arr2[], int tamanio2,
                       int result[]) {
  int res = tamanio1 + tamanio2;
  int cont1 = 0;
  int cont2 = 0;
  for (int i = 0; i < res; i++) {
    if (cont1 < tamanio1 && (cont2 >= tamanio2 || arr1[cont1] < arr2[cont2])) {
      result[i] = arr1[cont1];
      cont1++;
    } else {
      result[i] = arr2[cont2];
      cont2++;
    }
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { // return -2; }
  // int verificarOrden(int arreglo[], int tamano) {
  int ascendente = 1;
  int descendente = 1;

  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      ascendente = 0; // O sea es falso
    }
    if (arr[i] < arr[i + 1]) {
      descendente = 0; // o sea es falso
    }
  }
  if (ascendente)
    return 1;
  else if (descendente)
    return -1;
  else
    return 0;
}
/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. IMPORTANTE: Escribe la función
para inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}
/*
datos= NULL;
datos = (tipoDato* )realloc(datos,(talla+1)*sizeof(tipoDato));
if (datos == NULL) exit(EXIT_FAILURE);)
strcpy(libro->titulo, titulo);
*/

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una LISTA ENLAZADA usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. ->El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.<-
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;
// recorrer la lista e ir uno por uno los nodos
Nodo *crearListaEnlazada(int arr[], int size) {
  Nodo *lst = NULL;
  // Nodo *fin = NULL;

  for (int i = 0; i < size - 1; i++) {
    Nodo *nuevo = (Nodo *)malloc(size * sizeof(int));
    Nodo *lst = (Nodo *)malloc(size * sizeof(int));
    if (nuevo == NULL)
      exit(EXIT_FAILURE);

    nuevo->numero = arr[i];
    nuevo->siguiente = NULL;

    if (i > 0) {
      lst->siguiente = nuevo;
      lst = nuevo;
    }
  }
  return NULL;
}
