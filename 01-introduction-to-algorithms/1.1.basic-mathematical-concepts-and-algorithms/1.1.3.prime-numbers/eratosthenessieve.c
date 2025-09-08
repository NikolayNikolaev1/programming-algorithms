#include <math.h>
#include <stdio.h>

unsigned sieve[100];
unsigned n = 17;

void removeByIndex(unsigned indx);

int main() {
	for (unsigned i = 2; i <= n; sieve[i-2] = i, i++);
	
	for (unsigned i = 0; i <= n-2; i++)
		if (sieve[i] != 0) {
			removeByIndex(i);
			printf("%d\n", sieve[i]);
		}

    return 0;
}

void removeByIndex(unsigned indx) {
	for (unsigned i = indx;
		i <= n-2 && i+sieve[indx] <= n-2;
		i += sieve[indx], sieve[i] = 0);
}
