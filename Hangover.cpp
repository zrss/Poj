/* Poj 1003 one try AC 0MS */

#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[]) {
	float c;
	while (scanf("%f", &c) && c > 1e-3) {
		int cards = 1;
		float sum = 0;
		for (; sum < c; ++cards) {
			sum += (1.0 / (cards + 1));
			if (fabs(sum - c) < 1e-3 || sum > c) {
				printf("%d card(s)\n", cards);
				break;
			}
		}
	}
	return 0;
}