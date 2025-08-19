#include <math.h>
#include <stdio.h>

void printProdDigitsCount();
void printFactDigitsCount();
long getProductOfNumbers(int numbers[], size_t numbersCount);
unsigned getDigitsCount(long number);
long getFact(int n);
double getFactDigitsCount(unsigned long n);

int main() {
    printProdDigitsCount();
    printFactDigitsCount();
    
    return 0;
}

void printProdDigitsCount() {
    int numbers[] = {-5, 2, 3, 6, 4, 6};
    long prod = getProductOfNumbers(
        numbers, sizeof(numbers)/sizeof(numbers[0]));
    unsigned digitsCount = getDigitsCount(prod);
    
    printf("Product %d has %u digits.\n", prod, digitsCount);
}

void printFactDigitsCount() {
    unsigned long n = 261590;
    /*
    long fact = getFact(n);
    unsigned digitsCount = getDigitsCount(fact);
    */
    unsigned long digitsCount = 
        (unsigned long)floor(getFactDigitsCount(n));
    printf("!%u has %u digits.\n", n, digitsCount);
}

long getProductOfNumbers(int numbers[], size_t numbersCount) {
    long prod = 1;
    
    for (int i = 0; i < numbersCount; i++) {
        if (numbers[i] == 0) return 0;
        prod *= numbers[i];
    }
        
    return prod;
}

long getFact(int n) {
    return n > 1 ? n * getFact(n-1) : 1;
}

double getFactDigitsCount(unsigned long n) {
    return n > 0 ? log10(n) + getFactDigitsCount(n-1) : 1;
}


unsigned getDigitsCount(long number) {
    int counter = 0;
    for (int i = number; i != 0; i /= 10, counter++);
    return counter;
}
