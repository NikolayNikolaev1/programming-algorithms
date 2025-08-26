#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void printPrimesOfEvenSum(unsigned long n);
void printUniquePrimesOfSum(unsigned long n);
void printPrimesOfOddSum(unsigned long n);
void printPrimesOfEvenDiff(unsigned long n);
void getPrimesOfSum(unsigned long sum, unsigned long* n, unsigned long* m);
void getUniquePrimesOfSum(unsigned long sum, unsigned long* firstPrime, unsigned long* secondPrime, unsigned long* thirdPrime, bool unique);
void getPrimesOfDiff(unsigned long diff, unsigned long* n, unsigned long* m);
bool isPrime(unsigned long n);

int main() {
    unsigned long n = 2;
    printPrimesOfEvenSum(n);
	printUniquePrimesOfSum(n);
	printPrimesOfOddSum(n);
	printPrimesOfEvenDiff(n);
	
    return 0;
}

void printPrimesOfEvenSum(unsigned long n) {
    if (n == 2 || n % 2 != 0) {
        printf("Number should be even and bigger than 2.\n");
        return;
    }
    
	unsigned long firstNum, secondNum;
	getPrimesOfSum(n, &firstNum, &secondNum);
	printf("%d + %d = %d\n", firstNum, secondNum, n);
}

void printUniquePrimesOfSum(unsigned long n) {
	const int MIN_N = 18;
	
    if (n < MIN_N) {
        printf("Number should be bigger than %d.\n", MIN_N-1);
        return;
    }
	
	unsigned long firstNum, secondNum, thirdNum, sum;
	
	getUniquePrimesOfSum(n, &firstNum, &secondNum, &thirdNum, true);
	
	printf("%d + %d + %d = %d\n", firstNum, secondNum, thirdNum, n);
}

void printPrimesOfOddSum(unsigned long n) {
	const int MIN_N = 6;
	
	if (n < MIN_N  || n%2 == 0) {
		printf("Number should be odd and bigger than %d.\n", MIN_N-1);
		return;
	}
	
	unsigned long firstNum, secondNum, thirdNum;
	getUniquePrimesOfSum(n, &firstNum, &secondNum, &thirdNum, false);
	
	printf("%d + %d + %d = %d\n", firstNum, secondNum, thirdNum, n);
}

void printPrimesOfEvenDiff(unsigned long n) {
	if (n%2 != 0) {
		printf("Number should be even.\n");
		return;
	}
	
	unsigned long firstNum, secondNum;
	getPrimesOfDiff(n, &firstNum, &secondNum);
	
	printf("%d = %d - %d\n", n, firstNum, secondNum);
}

void getPrimesOfSum(unsigned long sum, unsigned long* n, unsigned long* m) {
	for (unsigned long prime = sum - 2; prime >= 2; prime--)
		if (isPrime(prime) && isPrime(sum - prime)) {
			*n = prime;
			*m = sum - prime;
			break;
		}
}

void getUniquePrimesOfSum(
	unsigned long sum,
	unsigned long* firstPrime,
	unsigned long* secondPrime,
	unsigned long* thirdPrime,
	bool unique) {
	for (int i = 2; i < sum; i++) {
		if (!isPrime(i)) continue;
		
		for (int j = 2; i+j < sum; j++) {
			if (unique && j == i || !isPrime(j)) continue;
			
			for (int k = 2; i+j+k <= sum; k++) {
				if (unique && (k == i || k == j) || !isPrime(k)) continue;
				
				if (i + j + k == sum) {
					*firstPrime = (unsigned long)i;
					*secondPrime = (unsigned long)j;
					*thirdPrime = (unsigned long)k;
					return;
				}
			}
		}
	}
}

void getPrimesOfDiff(unsigned long diff, unsigned long* n, unsigned long* m) {
	for (unsigned long prime = 2;
	!isPrime(prime) || !isPrime(diff + prime);
	prime++, *n = diff+prime, *m = prime);
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