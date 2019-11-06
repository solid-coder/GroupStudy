#include <stdio.h>
#define MAX_LEN		1001

char a[MAX_LEN];

int mstrlen(const char* s) {
	int len = 0;
	while (*s++) ++len;
	return len;
}
int findString(char parent[], char pattern[]) {
	int ret = 0;
	int parentSize = mstrlen(parent);
	int patternSize = mstrlen(pattern);
	int parentHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (!i) {
			for (int j = 0; j < patternSize; j++) {
				parentHash = (parentHash << 1) + parent[j];
				patternHash = (patternHash << 1) + pattern[j];
				if (j < patternSize - 1) power <<= 1;
			}
		}
		else {
			parentHash = ((parentHash - parent[i - 1] * power) << 1) + (parent[i + patternSize - 1]);
		}
		if (parentHash == patternHash) {
			bool found = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					found = false;
					break;
				}
			}
			if (found) {
				ret++;
			}
		}
	}

	return ret;
}
int main()
{
	int T;
	int ans;
	T = 10;
	int tc;
	char target[11];

	while (T--) {
		ans = 0;
		scanf("%d", &tc);
		scanf("%s", target);
		scanf("%s", a);
		ans = findString(a, target);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
