#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <locale.h>

#define MAX 1000000

struct Primes {
    int len;
    int *components;
};

int isNotPrime(intNumber) {
	int i;
	int limite = (int) sqrt(intNumber); //limitador otimizado baseado no método matemático indiano.

	for(i=2;i<=limite;i++) {
		if(intNumber % i == 0) {
			return i;
		}
	}
	return 0;
}

struct Primes componentsPrime(int intNumber) {
	int len = 0;
	int *components;
	int test;
	static struct Primes primos;

	components = malloc(sizeof(int));
	*components = 0;

	while(1==1) {
		test = isNotPrime(intNumber);
		if(test != 0) {
			components = realloc(components,((len+1) * sizeof(int)));
			*(components+len) = test;
			while(intNumber % test == 0)
				intNumber = intNumber / test;
			len++;
		}else{
			if(len == 0) {
				break;
			}else{
				if(intNumber != 1) {
					components = realloc(components,((len+1) * sizeof(int)));
					*(components+len) = intNumber;
					len++;
				}
				break;
			}
		}
	}

	primos.len = len;
	primos.components = components;

	return primos;
}


int main(int argc, char **argv) {
	int i;
	int intNumber;
	struct Primes primos;

	for(i=0;;i++) {
		scanf("%d",&intNumber);

		if(intNumber > MAX)
			return EXIT_FAILURE;

		if(intNumber == 0) {
			break;
		}else{
			primos =  componentsPrime(intNumber);
			printf("%d : %d\n",intNumber,primos.len);
		}
	}
	return EXIT_SUCCESS;
}
