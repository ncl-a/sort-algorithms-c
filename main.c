#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "algOrd.h"

int main(void) {	// CANCELLAMI !!!!!!!!!!!!!!!!!!!!!!

	int a[] = { 10, 2, 7, 5, 9, 1, 2, 8 };
	printVector(a, 8);

	bubbleSort(a, 8);

	printVector(a, 8);


	return 0;
}
