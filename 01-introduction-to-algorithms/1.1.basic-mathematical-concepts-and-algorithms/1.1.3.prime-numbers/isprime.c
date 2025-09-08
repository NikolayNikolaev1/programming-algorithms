#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(unsigned long n);

int main() {
	for (int i = 2; i <= 100; i++)
		if (isPrime(i)) printf("%d\n", i);

    return 0;
}

bool isPrime(unsigned long n) {
	bool primeCheck = true;
	for (unsigned long i = 2;
		i <= sqrt(n) && primeCheck;
		primeCheck = n%i != 0, i++);
		
	return primeCheck;
}