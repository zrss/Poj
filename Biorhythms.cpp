/* Poj 1006 three try AC 79MS */
/* hint: 24 29 34 0 */
#include <cstdio>

int main(int argc, char const *argv[]) {
	int c = 1;
	int p, e, i, d;

	while (scanf("%d %d %d %d", &p, &e, &i, &d) && (p != -1)) {
		p %= 23;
		e %= 28;
		i %= 33;

		int gapPE = p - e;
		int gapPI = p - i;

		bool stop = false;

		for (int n1 = 0; !stop; ++n1) {
			if (!(gapPE % 28) && !(gapPI % 33)) {
				int days = p + 23 * n1 - d;
				days = days > 0 ? days : days + 21252;
				printf("Case %d: the next triple peak occurs in %d days.\n", c, days);
				stop = true;
			}
			gapPE += 23;
			gapPI += 23;
		}

		++c;
	}

	return 0;
}