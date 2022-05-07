#pragma once


/*

	Credits: Nicola Ricciardi
	version 1.0.0 - 07/05/2022

*/


#include <stdio.h>
#include <stdlib.h>

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
*	L'algoritmo prende in input il vettore di interi da ordinare e la sua dimensione (length).
*	Ad ogni ciclo porta indietro nel vettore l'elemento corrente fin quando non è minore dell'elemento i-esimo all'indietro nel vettore. 
*
*	Complessità media O(n^2)
*/
extern void insertSort(int* vector, int length);

/*
*	Quick Sort:
*	L'algoritmo prende in input il vettore di interi da ordinare, l'indice del primo elemento (inizialmente deve essere 0) e l'indice del suo ultimo elemento (inizialmente length-1).
*	Ad ogni ciclo scelgo un elemento "di mezzo" nel vettore (in base a questa scelta se ne determina l'efficienza, per un'efficienza maggiore sarebbe necessario scegliere il pivot come
*	elemento mediano rispetto agli elementi del vettore) detto pivot, successivamente porto a sinistra del pivot gli elementi minori presenti a destra di esso e a destra quelli maggiori
*	presenti a sinistra di esso. In fine chiamo ricorsivamente l'algoritmo su due sotto vettori ottenuti dividendo in due il vettore originale rispetto al pivot.
*
*	Complessità media O(n*log2(n))
*/
extern void quickSort(int* vector, int first, int last);

/*
*	Merge Sort:
*	L'algoritmo prende in input il vettore di interi da ordinare, l'indice del primo elemento (inizialmente deve essere 0) e l'indice del suo ultimo elemento (inizialmente length-1).
*	L'algoritmo è un quick sort dove il pivot è scelto sempre in modo efficiente, ossia spezzando il vettore sempre in due porzioni "uguali"
*
*	Complessità media O(n*log2(n))
*/
extern void __merge(int* vector, int first, int nextOfPivot, int last, int length);		// sotto funzione di mergeSort(...)
extern void mergeSort(int* vector, int first, int last, int length);