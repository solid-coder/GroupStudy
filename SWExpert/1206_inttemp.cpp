#include <stdio.h>
#define MAXN    1000
int a[MAXN];
int lmax[MAXN];
int rmax[MAXN];
int main()
{
	for (int tc = 1; tc <= 10; ++tc) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			lmax[i] = rmax[i] = 0;
			scanf("%d", a+i);

			if (i >= 2) {
				lmax[i] = a[i - 2] > a[i - 1] ? a[i - 2] : a[i - 1];
				rmax[i - 2] = a[i] > a[i - 1] ? a[i] : a[i - 1];
				if (a[i - 2] > lmax[i - 2] && a[i - 2] > rmax[i - 2]) {
					ans += a[i - 2] - (lmax[i - 2] > rmax[i - 2] ? lmax[i - 2] : rmax[i - 2]);
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
