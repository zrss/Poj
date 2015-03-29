/* Poj 1004 one try AC 0MS */
#include <cstdio>

int main(int argc, char const *argv[]) {
	float temp;
	float sum = 0;
	for (int i = 0; i < 12; ++i) {
		scanf("%f", &temp);
		sum += temp;
	}

	printf("$%.2f\n", sum / 12);

	return 0;
}