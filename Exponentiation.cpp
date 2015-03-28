/* Poj 1001 one try AC 0MS */

#include <cstdio>
#include <cstring>

void multiple(int* a, int lenA, int* b, int lenB, int* rel) {
	for (int i = 0; i < lenA; ++i) {
		for (int j = 0; j < lenB; ++j) {
			int pos = i + j;
			rel[pos] += (a[i] * b[j]);
			rel[pos + 1] += rel[pos] / 10;
			rel[pos] %= 10; 
		}
	}
}

int main(int argc, char const *argv[]) {
	char r[7];
	int n;
	
	while (scanf("%s%d", r, &n) == 2) {
		int len = strlen(r);

		if (1 == n) {
			// pre zero
			int start = 0; 
			for (; start < len; ++start) {
				if (r[start] != '0') {
					break;
				}
			}
			// trail zero
			int end = len - 1;
			for (; end > start; --end) {
				if (r[end] != '0') {
					if (r[end] != '.') {
						r[end + 1] = '\0';
					} else {
						r[end] = '\0';
					}
				}
			}
			printf("%s\n", r + start);
			continue;
		}

		--n;

		// 
		int dotPos = 0;
		for(; dotPos < len; ++dotPos) {
			if ('.' == r[dotPos]) {
				break;
			}
		}

		int decimal = 0;

		if (dotPos != len) {
			decimal = (len - 1 - dotPos) * (n + 1);
		}

		// reverse
		int num[7];
		int count = len - 1, nlen = 0;
		for (; count > dotPos; --count, ++nlen) {
			num[nlen] = r[count] - '0';
		}
		for (count = dotPos - 1; count >= 0; --count, ++nlen) {
			num[nlen] = r[count] - '0';
		}

		// copy to rel
		int rel[200];
		int pre[200];

		int relLen = nlen;
		for (int i = 0; i < relLen; ++i) {
			pre[i] = num[i];
		}

		int time = 0;

		while (time < n) {
			memset(rel, 0, sizeof(rel));

			multiple(num, nlen, pre, relLen, rel);

			relLen = nlen + relLen - 1;

			if (rel[relLen]) {
				++relLen;
			}

			memcpy(pre, rel, sizeof(int)*relLen);

			++time;
		}

		// convert to string
		char str[200];
		int c = 0;
		for (int i = relLen - 1; i >= 0; --i, ++c) {
			str[c] = '0' + rel[i];
			if (decimal && i == decimal) {
				str[++c] = '.';
			}
		}

		// pre zeros
		int start = 0;
		while (start < c) {
			if (str[start] == '0') {
				++start;
			} else {
				break;
			}
		}

		// trail zeros
		int end = c - 1;
		while (end >= start) {
			if (str[end] == '0') {
				--end;
			} else {
				if (str[end] != '.') {
					str[end + 1] = '\0';
				} else {
					str[end] = '\0';
				}
				break;
			}
		}

		printf("%s\n", str + start);
	}

	return 0;
}