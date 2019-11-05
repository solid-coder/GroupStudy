#include <stdio.h>
#define MAX_SIZE    100
int a[MAX_SIZE][MAX_SIZE];
int s[MAX_SIZE];
int size;
int dx[] = { 1,0,0 };  //го аб ©Л
int dy[] = { 0,-1,1 };  //го аб ©Л

int run(int y) {
	int x = 0;
	int d = 0;
	int cnt = 0;
	while (x < 99) {
		cnt++;
		x += dx[d];
		y += dy[d];
		if (!d && y > 0 && a[x][y - 1]) {
			d = 1;
		}
		else if (!d && y < 99 && a[x][y + 1]) {
			d = 2;
		}
		else if (d && a[x + 1][y]) {
			d = 0;
		}
	}
	return cnt;
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
		size = 0;
		for (int i = 0; i < MAX_SIZE; ++i) {
			for (int j = 0; j < MAX_SIZE; ++j) {
				scanf("%d", &a[i][j]);
				if (i == 0 && a[i][j]) {
					s[size++] = j;
				}
			}
		}
		int dist;
		int min = 100000;
		for (int i = 0; i < size; ++i) {
			dist = run(s[i]);

			if (dist <= min) {
				if (dist == min) {
					ans = ans > s[i] ? ans : s[i];
				}
				else {
					min = dist;
					ans = s[i];
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
