#include <stdio.h>
#define MAX_SIZE	100
int a[MAX_SIZE][MAX_SIZE];

int dx[] = { -1,0,0 };	//╩С аб ©Л
int dy[] = { 0,-1,1 };	//╩С аб ©Л

void run(int& x, int& y) {
	register int d = 0;
	while (x > 0) {
		x += dx[d];
		y += dy[d];
		if (!d && y > 0 && a[x][y - 1]) {
			d = 1;
		}
		else if (!d && y < 99 && a[x][y + 1]) {
			d = 2;
		}
		else if (d && a[x - 1][y]) {
			d = 0;
		}
	}
}
int main()
{
	int T;
	int ans;
	T = 10;
	int tc;

	while (T--) {
		ans = 0;
		scanf("%d", &tc);
		int r, c;

		for (register int i = 0; i < MAX_SIZE; ++i) {
			for (register int j = 0; j < MAX_SIZE; ++j) {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 2) {
					r = i;
					c = j;
				}
			}
		}
		run(r, c);

		ans = c;
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
