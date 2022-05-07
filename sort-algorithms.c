#include "algOrd.h"

/*

	Credits: Nicola Ricciardi
	version 1.0.0 - 07/05/2022

*/

void printVector(int* vector, int length) {
	printf("{ ");
	for (int i = 0; i < length-1; i++)
		printf("%d, ", vector[i]);

	printf("%d }\n", vector[length - 1]);
}

int getIndexOfMax(int* vector, int length) {
	
	// salvo in indexMax l'indice dell'elemento massimo 
	int indexMax = 0;
	for (int i = 1; i < length; i++)
		if (vector[i] > vector[indexMax])
			indexMax = i;

	return indexMax;
}

void swap(int* e1, int* e2) {
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}


void naiveSort(int* vector, int length) {

	while (length > 1)
	{
		int indexMax = getIndexOfMax(vector, length);		// cerco l'indice dell'elemento massimo (senza considerare quelli già ordinati, in quanto lenght sarà inferiore della dimensione reale)
		if (indexMax < length - 1)
			swap(&vector[indexMax], &vector[length - 1]);

		length--;		// decremento per considerare il sotto vettore di lunghezza inferiore
	}
}

void bubbleSortBase(int* vector, int length) {
	
	for (int i = 0; i < length; i++)
		for (int j = i; j < length; j++)
			if (vector[i] > vector[j])			// per renderlo decrescente modificare > con <
				swap(&vector[i], &vector[j]);
}

void bubbleSort(int* vector, int length) {

	for (int i = 0; i < length; i++) {
		char ctrl = 0;

		for (int j = i; j < length; j++) {

			if (vector[i] > vector[j]) {// per renderlo decrescente modificare > con <
				swap(&vector[i], &vector[j]);
				ctrl = 1;
			}			
		}

		if (!ctrl)
			break;
	}
}

void insertSort(int* vector, int length) {
	for (int currentIndex = 1; currentIndex < length; currentIndex++) {			// scorro tutti gli elementi del vettore

		int backValueIndex;			// indice per lo spostamento "in dietro" dell'elemento
		int currentValue = vector[currentIndex];		// salvo il valore corrente in una variabile temporanea
		
		for (backValueIndex = currentIndex - 1; backValueIndex >= 0 && currentValue < vector[backValueIndex]; backValueIndex -= 1)		// fin quando il valore corrente è minore di "quello prima" e non si è sforato l'indice 0-esimo del vettore
			vector[backValueIndex + 1] = vector[backValueIndex];		// sposto gli elementi del vettore "in avanti"

		vector[backValueIndex + 1] = currentValue;			// una volta spostati salvo l'elemento corrente nella posizione corretta per essere ordinato
	}
}

void quickSort(int* vector, int first, int last) {

	int i, j, pivot;

	if (first < last) {
		i = first;
		j = last;
		pivot = vector[(first + last) / 2];		// il pivot è scelto senza controllo, per un'efficienza maggiore andrebbe scelto il valore mediano

		do {

			// cerco gli indici dei primi elementi minore e maggiore rispetto al pivot partendo da sinistra e da destra
			while (vector[i] < pivot)	// da sinistra
				i += 1;

			while (vector[j] > pivot)	// da destra
				j -= 1;

			// se i è "più a sinistra" rispetto a j, significa che dovrò scambiare gli elementi nel vettore
			if (i <= j) {
				swap(&vector[i], &vector[j]);
				// passo agli elementi successivi sia da sinistra che da destra
				i += 1;
				j -= 1;
			}

		} while (i <= j);

		// richiamo ricorsivamente la funzione sui due mezzi vettori, il primo da first a j e il secondo da i a last, ossia gli indici (precente e successivo) rispetto al pivot
		quickSort(vector, first, j);
		quickSort(vector, i, last);
	}

}


void __merge(int* vector, int first, int nextOfPivot, int last, int length) {
	int* vectorSorted = calloc(length, sizeof(int));
	int i = first, j = nextOfPivot, k = first;

	// inserisco in ordine gli elementi fin quando una dei due sotto vettori non si svuota
	while (i <= nextOfPivot -1 && j <= last) {
		if (vector[i] < vector[j]) {
			vectorSorted[k] = vector[i];
			i++;
		}	
		else {
			vectorSorted[k] = vector[j];
			j++;
		}
		k++;
	}

	// se uno dei due sotto vettori non è stato aggiunto tutto: continuo ad aggiungere gli elementi restanti
	while (i <= nextOfPivot -1) {
		vectorSorted[k] = vector[i];
		i++;
		k++;
	}

	while (j <= last) {
		vectorSorted[k] = vector[j];
		j++;
		k++;
	}

	// copio il vettore ordinato nel vettore di input
	for (int i = first; i <= last; i++)
		vector[i] = vectorSorted[i];
}

void mergeSort(int* vector, int first, int last, int length) {
	int pivot;

	if (first < last) {
		pivot = (first + last) / 2;		// prendo sempre l'elemento di mezzo
		mergeSort(vector, first, pivot, length);
		mergeSort(vector, pivot +1, last, length);	// dal successivo al pivot in poi
		__merge(vector, first, pivot + 1, last, length);		// ordino i sotto vettori ottenuti
	}


}