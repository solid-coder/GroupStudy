#include <stdio.h>

int a[101];

void init() {
	for (int i = 0; i < 101; ++i) {
		a[i] = 0;
	}
}
int main()
{

	int T;
	scanf("%d", &T);

	int tn;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		scanf("%d", &tn);
		int cnt = 0, ans = 0;
		int s;
		for (int i = 0; i < 1000; ++i) {
			scanf("%d", &s);
			a[s]++;
			if (a[s] > cnt) {
				cnt = a[s];
				ans = s;
			}
			else if (a[s] == cnt) {
				ans = ans < s ? s : ans;
			}
		}
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
