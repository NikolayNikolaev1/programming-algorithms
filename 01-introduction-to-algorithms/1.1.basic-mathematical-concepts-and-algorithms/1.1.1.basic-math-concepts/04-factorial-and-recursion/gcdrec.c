#include <stdio.h>

int recursiveGCD(int firstNum, int secondNum);

int main() {
    printf("%u", recursiveGCD(18, 12));

    return 0;
}

int recursiveGCD(int firstNum, int secondNum) {
    if (firstNum == 0) return secondNum;
    int m = firstNum > secondNum ? firstNum : secondNum;
    int n = firstNum < secondNum ? firstNum : secondNum;
    
    recursiveGCD(m % n, n);
}
