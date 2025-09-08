#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int R[] = {-13, -11, -7, -1, 1, 7, 11, 13};
int R2[29];

void test(unsigned min, unsigned max);
bool isPrime(unsigned n);

int main() {
	unsigned min = 71;
	unsigned max = 93;
	unsigned minQ = min/210;
	unsigned maxQ = max/210+1;
	
	test(1, 110);
	
	for (unsigned i = minQ; i <= maxQ; i++) {
		for (int j = 28; j >= 0; j--) {
			int currNum = 210 * i - R[j];
			if (currNum >= min
			&& currNum <= max
			&& isPrime(currNum)) {
				printf("%d\n", currNum);
			}
		}
		for (unsigned j = 0; j < 29; j++) {
			unsigned currNum = 210 * i + R[j];
			if (currNum >= min
			&& currNum <= max
			&& isPrime(currNum)) {
				printf("%d\n", currNum);
			}
		}
	}

    return 0;
}

void test(unsigned min, unsigned max) {
	unsigned minQ = min/30;
	unsigned maxQ = max/30+1;
	unsigned counter = 0;
	
	for (unsigned i = minQ; i <= maxQ; i++) {
		for (unsigned j = 3; j >= 0; j--) {
			unsigned currNum = 30 * i - R[j];
			if (currNum >= min
			&& currNum <= max
			&& isPrime(currNum)) {
				//printf("%d\n", currNum);
				R2[counter] = currNum;
				counter++;
			}
		}
		
		for (unsigned j = 0; j < 4; j++) {
			unsigned currNum = 30 * i + R[j];
			if (currNum >= min
			&& currNum <= max
			&& isPrime(currNum)) {
				//printf("%d\n", currNum);
				R2[counter] = currNum;
				counter++;
			}
		}
	}
}

bool isPrime(unsigned n) {
	bool primeCheck = true;
	for (unsigned i = 2;
	i <= sqrt(n) && primeCheck;
	primeCheck = n % i != 0, i++);
	
	return primeCheck;
}