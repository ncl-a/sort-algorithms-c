#include "algOrd.h"

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


// TODO:
void insertSort(int* vector, int length) {
	for (int currentIndex = 0; currentIndex < length; currentIndex++) {

		int backValueIndex = currentIndex;
		while (vector[currentIndex] <= vector[backValueIndex] && backValueIndex >= 0) {

			//vector[backValueIndex];

			backValueIndex -= 1;
		}

	}
}