#include <stdio.h>
#define MAX_SIZE	100
int a[MAX_SIZE][MAX_SIZE];

int row[MAX_SIZE];
int col[MAX_SIZE];
int topdown, botup;

int main()
{
	int T;
	int ans;
	T = 10;
	int tc;
	int x;

	while (T--) {
		ans = 0;
		scanf("%d", &tc);
		for (int i = 0; i < MAX_SIZE; ++i) {
			row[i] = col[i] = topdown = botup = 0;
		}
		for (int i = 0; i < MAX_SIZE; ++i) {
			for (int j = 0; j < MAX_SIZE; ++j) {
				scanf("%d", &x);
				row[i] += x;
				col[j] += x;
				if (i == j) {
					topdown += x;
				}
				else if (i + j == 99) {
					botup += x;
				}
			}
			ans = ans < row[i] ? row[i] : ans;
		}
		for (int i = 0; i < MAX_SIZE; ++i) {
			ans = ans < col[i] ? col[i] : ans;
		}
		ans = ans < topdown ? topdown : ans;
		ans = ans < botup ? botup : ans;

		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
