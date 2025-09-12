#include <stdio.h>
#include <stdlib.h>

unsigned getFacZerosCount(unsigned n);
unsigned getProdZerosCount(unsigned arr[], int size);

int main() {
	unsigned n = 5;
	unsigned arr[6] = { 25, 4, 20, 11, 13, 15 };
	
	printf("Trailling zeros in %d! - %d\n", n, getFacZerosCount(n));
	printf("arr prod zeros - %d",
		getProdZerosCount(arr, sizeof(arr)/sizeof(arr[0])));
	
    return 0;
}

unsigned getFacZerosCount(unsigned n) {
	return n/5;
}

unsigned getProdZerosCount(unsigned arr[], int size) {
	unsigned evenCntr = 0;
	unsigned fiveCntr = 0;
	unsigned zeroCntr = 0;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] % 10 == 0) zeroCntr++;
		else if (arr[i] % 5 == 0) fiveCntr++;
		else if (arr[i] % 2 == 0) evenCntr++;
	}
	
	
	while (evenCntr > fiveCntr && zeroCntr--) {
		
	}
	
	return zeroCntr / 2 + evenCntr == fiveCntr 
		? evenCntr
		: zeroCntr % 2 + evenCntr < fiveCntr
			? evenCntr
			: fiveCntr;
}