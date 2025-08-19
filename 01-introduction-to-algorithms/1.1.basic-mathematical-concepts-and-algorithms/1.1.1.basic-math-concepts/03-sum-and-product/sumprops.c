#include <stdio.h>

void firstProblem();
void secondProblem();

int main() {
    firstProblem();
    secondProblem();
    return 0;
}

void firstProblem() {
    
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int sum = 0;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sum += a[i] * b[j];
            
    int sumA = 0;
    int sumB = 0;
    int result;
    for (int i = 0; i < 3; sumA += a[i], sumB += b[i], i++);
    result = sumA * sumB;
    
    printf("%u\n%u", sum, result);
}

void secondProblem() {
    int a[] = {1,2,4,5,7}; // 19
    int b[] = {2,3,4,5,6}; // 20
    int sum = 0;
    
    for (int i = 0; i < 5; i++)
        sum += a[i];
        
    for (int j = 0; j < 5; j++)
        sum += b[j];
            
    printf("%u\n", sum);
    
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    int b1[] = {2, 4, 5};
    sum = 0;
    
    
    for (int i = 0; i < 7; i++)
        sum += a1[i];
        
    for (int j = 0; j < 3; j++)
        sum += b1[j];
    

    printf("%u", sum);
}
