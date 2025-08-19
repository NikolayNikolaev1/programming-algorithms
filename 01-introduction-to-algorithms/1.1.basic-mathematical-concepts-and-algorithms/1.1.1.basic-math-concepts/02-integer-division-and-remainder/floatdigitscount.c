#include <stdio.h>

unsigned getFloatNumberDigitCount(long double n);

int main() {
    long double number = 3.14;
    unsigned digitsCount = getFloatNumberDigitCount(number);
    printf("%u", digitsCount);
    
    return 0;
}

unsigned getFloatNumberDigitCount(long double number) {
    unsigned digits = 0;
    for (int lastDigit = -1; lastDigit != 0; number*=10, lastDigit = (int)number % 10, digits++);

    return --digits;
}
