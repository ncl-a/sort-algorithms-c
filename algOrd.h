#pragma once

#include <stdio.h>

// stampa il vettore
extern void printVector(int* vector, int length);

// restituisce l'indice della prima occorrenza del valore massimo in un'array; complessità O(n)
extern int getIndexOfMax(int* vector, int length);

// scambia gli elementi agli indirizzi passati
extern void swap(int** e1, int** e2);


/*
	Naive Sort:
	L'algoritmo prende in input il vettore di interi da ordinare e la sua dimensione (length).
	Length diventa un contatore da decrementare ad ogni ciclo, in quanto l'algoritmo ad ogni iterazione considera un sotto vettore vector[0:length].
	Per ogni ciclo, l'algoritmo cerca l'indice dell'elemento di grandezza massima, verifica che sia maggiore dell'elemento di indice length-1 (l'ultimo 
	elemento del sotto vettore nel ciclo considerato) e in caso positivo li scambia, ossia pone l'elemento massimo trovato nell'ultima posizione del sotto
	vettore.
	Il ciclo ricomincia con un dimensione inferiore di uno (length--) in modo da considerare un sotto vettore inferiore.

	Complessità media O(n^2)
*/
extern void naiveSort(int* vector, int length);

/*
*	Bubble Sort senza controllo:
*	L'algoritmo prende in input il vettore di interi da ordinare e la sua dimensione (length).
*	Ad ogni ciclo confronto a due a due gli elementi spostando verso l'ultima posizione l'elemento maggiore.
*	Alla fine dei due cicli il vettore sarà ordinato
* 
*	Complessità media O(n^2)
*/
extern void bubbleSortBase(int* vector, int length);

/*
*	Bubble Sort con controllo:
*	L'algoritmo prende in input il vettore di interi da ordinare e la sua dimensione (length).
*	Ad ogni ciclo confronto a due a due gli elementi spostando verso l'ultima posizione l'elemento maggiore.
*	Alla fine dei due cicli il vettore sarà ordinato.
*	Se il vettore risulta essere già ordinato in uno dei passaggi: termino l'algoritmo
*
*	Complessità media O(n^2); se il vettore è già ordinato O(n) -> supera il limite di naive sort di non sapere quando è ordinato
*/
extern void bubbleSort(int* vector, int length);


/*
*	Insert Sort:
*	
*
*	Complessità media O(n^2)
*/
extern void insertSort(int* vector, int length);
