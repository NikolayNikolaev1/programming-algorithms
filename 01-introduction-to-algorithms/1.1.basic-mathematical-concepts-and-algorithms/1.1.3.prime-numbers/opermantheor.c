#include <math.h>
#include <stdbool.h>
#include <stdio.h>

unsigned long powRec(unsigned long n, int m);
bool isPrime(unsigned long n);

int main() {
	
	for (int j = 100; j <= 1000; j++) {
	
		unsigned long n = j;
		unsigned long prime = 0;
		unsigned long start = powRec(n, 2);
		unsigned long end = powRec(n+1, 2);
		
		for (unsigned long i = start; i <= end+1 && !isPrime(prime); prime = i, i++);
		
		if (prime == end+1) {
			printf("No prime number between %d and %d\n", start, end);
			return 0;
		}
		
		printf("INDX: %d, Start: %d, End: %d, Prime: %d\n", n, start, end, prime);
	}
		
	
	return 0;
}

bool isPrime(unsigned long n) {
	if (n == 2 || n == 3) return true;
	if (n < 2 || n%2 == 0) return false;
	
	bool primeCheck = true;
	for (int i = 1; i <= ceil(n/4) && primeCheck; i++, primeCheck = n%i != 0);
	
	return primeCheck;
}

unsigned long powRec(unsigned long n, int m) {
	if (m == 0) return 1;
	if (m == 1) return n;
	
	return n * pow(n, m-1);
}
