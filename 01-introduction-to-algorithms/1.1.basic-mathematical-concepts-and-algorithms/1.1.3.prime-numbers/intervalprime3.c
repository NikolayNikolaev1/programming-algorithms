#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int R[] = {1, 7, 11, 13};

bool isPrime(unsigned n);

int main() {
	unsigned min = 1;
	unsigned max = 110;
	unsigned minQ = min/30;
	unsigned maxQ = max/30+1;
	
	for (unsigned i = minQ; i <= maxQ; i++) {
		for (unsigned j = 3; j >= 0; j--) {
			unsigned currNum = 30 * i - R[j];
			if (currNum >= min
			&& currNum <= max
			&& isPrime(currNum)) {
				printf("%d\n", currNum);
			}
		}
		
		for (unsigned j = 0; j < 4; j++) {
			unsigned currNum = 30 * i + R[j];
			if (currNum >= min
			&& currNum <= max
			&& isPrime(currNum)) {
				printf("%d\n", currNum);
			}
		}
	}

    return 0;
}

bool isPrime(unsigned n) {
	bool primeCheck = true;
	for (unsigned i = 2;
	i <= sqrt(n) && primeCheck;
	primeCheck = n % i != 0, i++);
	
	return primeCheck;
}