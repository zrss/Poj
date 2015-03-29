/* Poj 1002 two try AC 1297MS */

#include <cstdio>
#include <cstring>
#include <cstdlib>

char dir[110000][200]; // hint: should be big enough

int cmp(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}

int main(int argc, char const *argv[]) {
	int num;
	scanf("%d", &num);

	char map[] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6',
			'7','7','7','7','8','8','8','9','9','9','9'};

	for (int i = 0; i < num; ++i) {
		scanf("%s", dir[i]);

		// convert to normal format
		int len = strlen(dir[i]);

		char temp[200];

		int count = 0;

		for (int j = 0; j < len; ++j) {
			char c = dir[i][j];
			if (c != '-') {
				if (c >= 'A' && c <= 'Z') {
					temp[count] = map[c - 'A'];
				} else {
					temp[count] = c;
				}
				if (count == 2) {
					temp[++count] = '-';
				}
				++count;
			}
		}

		strcpy(dir[i], temp);
	}

	// qsort (target, count, gap, cmp)
	std::qsort(dir, num, sizeof(dir[0]), cmp);

	bool duplicates = false;

	int count = 1;
	int temp = num - 1;

	// count
	for (int i = 0; i < temp; ++i) {
		if (!strcmp(dir[i], dir[i + 1])) {
			++count;
		} else {
			if (count != 1) {
				printf("%s %d\n", dir[i], count);
				count = 1;
				duplicates = true;
			}
		}
	}

	if (count != 1) {
		printf("%s %d\n", dir[num - 1], count);
	} else {
		if (!duplicates) {
			printf("No duplicates.\n");
		}
	}

	return 0;
}