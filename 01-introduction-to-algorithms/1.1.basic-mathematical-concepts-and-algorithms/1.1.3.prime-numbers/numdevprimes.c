#include <stdio.h>

int main() {
	unsigned p = 2345;
	unsigned i = 2;
	unsigned k = 0;
	
	printf("%d = ", p);
	
	while (p > 1) {
		while (p%i == 0) {
			p/=i;
			k++;
		}
		
		if (k != 0) {
			printf("%d^%d", i, k);
			k = 0;
			
			if (p != 1) printf(" * ");
		}
		
		i++;
	}
	
    return 0;
}
