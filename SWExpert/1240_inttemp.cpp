#include <stdio.h>
#define MAXN	50
#define MAXM	100

int code[MAXN][MAXM];
int num[(1 << 6)];


int main()
{
	int test_case;
	int T;

	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	num[8 | 4 | 1] = 0;
	num[16 | 8 | 1] = 1;
	num[16 | 2 | 1] = 2;
	num[32 | 16 | 8 | 4 | 1] = 3;
	num[32 | 2 | 1] = 4;
	num[32 | 16 | 1] = 5;
	num[32 | 8 | 4 | 2 | 1] = 6;
	num[32 | 16 | 8 | 2 | 1] = 7;
	num[32 | 16 | 4 | 2 | 1] = 8;
	num[8 | 2 | 1] = 9;
	int ans = 0;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		int n, m;
		scanf("%d %d", &n, &m);
		int row, col;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%1d", &code[i][j]);
				if (code[i][j]) {
					row = i;
					col = j;
				}
			}
		}
		col -= 7 * 8 - 1;
		int verify[8];
		for (int i = 0; i < 8; ++i) {
			int val = 0;
			for (int j = 0; j < 7; ++j) {
				val = (val << 1) + code[row][col + i * 7 + j];
			}
			verify[i] = num[val];
		}
		if (((verify[0] + verify[2] + verify[4] + verify[6]) * 3 + (verify[1] + verify[3] + verify[5]) + verify[7]) % 10 > 0) {
			ans = 0;
		}
		else {
			for (int i = 0; i < 8; ++i) {
				ans += verify[i];
			}
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}