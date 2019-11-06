#include <stdio.h>

#define ABS(x)		(((x) < (0)) ? (-(x)) : (x))

struct POS {
	int y, x;
};

const int SIZE = 10;

int n, ret;
POS pos[SIZE + 2];
bool visited[SIZE];

int get_dist(int sp, int ep) {
	return (ABS(pos[sp].y - pos[ep].y) + ABS(pos[sp].x - pos[ep].x));
}

void solve(int cur, int count, int dist) {
	if (count == n) {
		dist += get_dist(cur, n + 1);
		if (ret > dist) {
			ret = dist;
		}
		return;
	}

	for (int next = 0; next < n; ++next) {
		if (visited[next] == false) {
			visited[next] = true;
			dist += get_dist(cur, next);
			solve(next, count + 1, dist);
			dist -= get_dist(cur, next);
			visited[next] = false;
		}
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int test_case = 1; test_case <= tc; ++test_case) {
		scanf("%d", &n);
		scanf("%d %d %d %d", &pos[n].x, &pos[n].y, &pos[n + 1].x, &pos[n + 1].y);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &pos[i].x, &pos[i].y);
		}

		for (int i = 0; i < n; ++i) {
			visited[i] = false;
		}
		ret = 0x7fffffff;
		solve(n, 0, 0);
		printf("#%d %d\n", test_case, ret);
	}
	return 0;
}