#include <stdio.h>
int MAX = 5;

void fillMatrix(unsigned a[][MAX], unsigned n);
void printMatrix(unsigned a[][MAX], unsigned n);

int main() {
    unsigned a[MAX][MAX];
    
    fillMatrix(a, MAX);
    printMatrix(a, MAX);

    return 0;
}

void fillMatrix(unsigned a[][MAX], unsigned n) {
    signed counter = 0;
    int topIdx = 0,
        bottomIdx = n-1,
        leftIdx = 0,
        rightIdx = n-1;

    while (topIdx <= bottomIdx
        && leftIdx <= rightIdx) {
        for (int i = topIdx; i <= bottomIdx; i++)
            a[i][leftIdx] = ++counter;
        leftIdx++;
        
        for (int i = leftIdx; i <= rightIdx; i++)
            a[bottomIdx][i] = ++counter;
        bottomIdx--;
        
        if (leftIdx <= rightIdx) {
            for (int i = bottomIdx; i >= topIdx; i--)
                a[i][rightIdx] = ++counter;
            rightIdx--;
        }
        
        if (topIdx <= bottomIdx) {
            for (int i = rightIdx; i >= leftIdx; i--)
                a[topIdx][i] = ++counter;
            topIdx++;
        }
    }
}

void printMatrix(unsigned a[][MAX], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("|%u\t", a[i][j]);
        printf("|\n");
    }
}