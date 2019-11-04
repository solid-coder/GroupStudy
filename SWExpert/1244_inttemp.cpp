#include <stdio.h>

char a[7];
int n;
int s;
int ans;
void swap(char& x, char& y) {
	char temp = x;
	x = y;
	y = temp;
}

void dfs(int depth) {
	if (depth > 3) {
		for (int i = depth; i < s; ++i) {
			swap(a[n - 2], a[n - 1]);
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum = sum * 10 + a[i] - '0';
		}
		ans = ans > sum ? ans : sum;
		return;
	}
	if (depth == s) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum = sum * 10 + a[i] - '0';
		}
		ans = ans > sum ? ans : sum;
		return;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] == a[j])continue;
			swap(a[i], a[j]);
			dfs(depth + 1);
			swap(a[i], a[j]);
		}
	}

}
int main()
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		scanf("%s %d", a, &s);
		for (n = 0; a[n]; ++n);

		dfs(0);
		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}