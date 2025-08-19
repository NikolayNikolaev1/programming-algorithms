#include <stdio.h>
int MAX = 10;

void fillMatrix(unsigned a[][MAX], unsigned n);
void printMatrix(unsigned a[][MAX], unsigned n);

int main() {
    unsigned a[MAX][MAX];
    
    fillMatrix(a, MAX);
    printMatrix(a, MAX);

    return 0;
}

void fillMatrix(unsigned a[][MAX], unsigned n) {
    unsigned counter = 0;
    unsigned maxCounter = n*n - n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) a[i][j] = 0;
            else a[j][i] = j < i
                ? maxCounter--
                : ++counter;
        }
}

void printMatrix(unsigned a[][MAX], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("|%u\t", a[i][j]);
        printf("|\n");
    }
}
