#include <stdio.h>

const int DOWN = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int SIZE = 100;

int search(int map[][SIZE], int sp) {
	int dir = DOWN;
	int x = sp, y = 0;
	while (y < SIZE) {
		if ((dir == DOWN || dir == LEFT) && x > 0 && map[y][x - 1] != 0) {
			--x;
			dir = LEFT;
		}
		else if ((dir == DOWN || dir == RIGHT) && x < SIZE - 1 && map[y][x + 1] != 0) {
			++x;
			dir = RIGHT;
		}
		else {
			++y;
			dir = DOWN;
		}
	}
	return x;
}

int main()
{
	int tc;
	while (scanf("%d", &tc) != 0) {
		int map[SIZE][SIZE];
		for (int y = 0; y < SIZE; ++y) {
			for (int x = 0; x < SIZE; ++x) {
				scanf("%01d", &map[y][x]);
			}
		}

		int ans = 0;
		for (int i = 0; i < SIZE; ++i) {
			if (map[0][i] != 0) {
				int last_pos = search(map, i);
				if (map[SIZE - 1][last_pos] == 2) {
					ans = i;
					break;
				}
			}
		}

		printf("#%d %d\n", tc, ans);
		if (tc == 10) {
			break;
		}
	}
	return 0;
}	