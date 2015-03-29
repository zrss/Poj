/* Poj 1005 one try AC 0MS */

#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[]) {
	int N;
	scanf("%d", &N);

	float X, Y;

	for (int i = 0; i < N; ++i) {
		scanf("%f %f", &X, &Y);
		printf("Property %d: This property will begin eroding in year %d.\n",
				i + 1, (int)ceil((X * X + Y * Y) * 3.1415926 / 100));
	}

	printf("END OF OUTPUT.\n");

	return 0;
}