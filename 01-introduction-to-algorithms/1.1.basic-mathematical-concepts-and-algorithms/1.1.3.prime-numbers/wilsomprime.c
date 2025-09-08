#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(unsigned n);
unsigned long fac(unsigned n);

int main() {
	for (int i = 2; i <= 100; i++)
		if (isPrime(i)) printf("%d\n", i);

    return 0;
}

bool isPrime(unsigned n) {
	return (fac(n-1) + 1) % n == 0;
}

unsigned long fac(unsigned n) {
	return n > 2 ? n * fac(n-1) : n;
}