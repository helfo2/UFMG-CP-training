#include <iostream>

using namespace std;

int main(void) {
	long int n;
	int cont;
	scanf("%ld", &n);

	printf("%ld\n", n);
	
	cont = 0;
	while(n >= 100) {
		n -= 100;
		cont++;
	}
	printf("%d nota(s) de R$ 100,00\n", cont);
	
	cont = 0;
	while(n >= 50) {
		n -= 50;
		cont++;
	}
	printf("%d nota(s) de R$ 50,00\n", cont);

	cont = 0;
	while(n >= 20) {
		n -= 20;
		cont++;
	}
	printf("%d nota(s) de R$ 20,00\n", cont);

	cont = 0;
	while(n >= 10) {
		n -= 10;
		cont++;
	}
	printf("%d nota(s) de R$ 10,00\n", cont);

	cont = 0;
	while(n >= 5) {
		n -= 5;
		cont++;
	}
	printf("%d nota(s) de R$ 5,00\n", cont);

	cont = 0;
	while(n >= 2) {
		n -= 2;
		cont++;
	}
	printf("%d nota(s) de R$ 2,00\n", cont);

	cont = 0;
	while(n >= 1) {
		n -= 1;
		cont++;
	}
	printf("%d nota(s) de R$ 1,00\n", cont);

	return 0;
}