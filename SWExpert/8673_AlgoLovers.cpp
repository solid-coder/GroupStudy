#include <stdio.h>

int get_point(int data[], int len) {
	int k = 0, ret = 0;
	for (int i = 0; i < len; i += 2) {
		if (data[i] < data[i + 1]) {
			ret += (data[i + 1] - data[i]);
			data[k++] = data[i + 1];
			
		} else {
			ret += (data[i] - data[i + 1]);
			data[k++] = data[i];
		}
	}
	return ret;
}

int main()
{
	int tc;
	scanf("%d\n", &tc);
	for (int test_case = 1; test_case <= tc; ++test_case) {
		int n;
		int value[1024];
		scanf("%d", &n);
		int len = 1;
		for (int i = 0; i < n; ++i) {
			len *= 2;
		}
		for (int i = 0; i < len; ++i) {
			scanf("%d", &value[i]);
		}
		
		int score = 0;
		while (len > 1) {
			score += get_point(value, len);
			len /= 2;
		}

		printf("#%d %d\n", test_case, score);
	}
	return 0;
}
