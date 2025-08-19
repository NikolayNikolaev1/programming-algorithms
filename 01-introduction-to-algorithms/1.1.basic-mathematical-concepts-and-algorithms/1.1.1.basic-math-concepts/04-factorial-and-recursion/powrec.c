#include <stdio.h>

double recursivePow(int base, int pow);

int main() {
    printf("%0.f", recursivePow(-3, 1));
}

double recursivePow(int base, int pow) {
    if (pow < 0) return 1 / (base * recursivePow(base, -(pow+1)));
    if (pow == 0) return 1;
    if (pow == 1) return base;
    
    return base * recursivePow(base, --pow);
}
