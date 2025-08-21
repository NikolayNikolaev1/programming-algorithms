#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void printPrimesOfEvenSum(int n);
bool isPrime(unsigned long n);

int main() {
    int n = 523656;
    printPrimesOfEvenSum(n);
	
    return 0;
}

void printPrimesOfEvenSum(int n) {
    if (n == 2 || n % 2 != 0) {
        printf("Number should be even and bigger than 2.");
        return;
    }
    
	for (int prime = n - 2; prime >= (int)floor(n/2); prime--)
		if (isPrime(prime) && isPrime(n - prime)) {
			printf("%d + %d = %d", prime, n - prime, n);
			return;
		}
}

bool isPrime(unsigned long n) {
	if (n == 2 || n == 3) return true;
	
	int halfN = (int)ceil((double)n/2);
	bool primeCheck = false;
	
	for (int divider = 2;
	    n % divider != 0 && divider < halfN;
	    divider++, primeCheck = divider == halfN);
		
	return primeCheck;
}