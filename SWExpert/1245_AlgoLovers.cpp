#include <stdio.h>

int n;
double ret[10];
int pos[10], weight[10];

double get_left(double mid) {
	double sum = 0;
	for (int i = 0; i < n && mid > pos[i]; ++i) {
		double dist = (mid - pos[i]);
		sum += (weight[i] / (dist * dist));
	}
	return sum;
}

double get_right(double mid) {
	double sum = 0;
	for (int i = n - 1; i >= 0 && mid < pos[i]; --i) {
		double dist = (pos[i] - mid);
		sum += (weight[i] / (dist * dist));
	}
	return sum;
}

double get_pos(double left, double right) {
	for (int i = 0; i < 200; ++i) {
		double mid = (left + right) / 2;
		double left_sum = get_left(mid);
		double right_sum = get_right(mid);

		if (left_sum < right_sum) {
			right = mid;
		}
		else if (left_sum > right_sum) {
			left = mid;
		}
		else {
			return mid;
		}
	}
	return left;
}

void solve() {
	for (int i = 1; i < n; ++i) {
		ret[i - 1] = get_pos(pos[i - 1], pos[i]);
	}
}

void print(int test_case) {
	printf("#%d", test_case);
	for (int i = 0; i < n - 1; ++i) {
		printf(" %.10lf", ret[i]);
	}
	printf("\n");
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int test_case = 1; test_case <= tc; ++test_case) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &pos[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &weight[i]);
		}
		solve();
		print(test_case);
	}
	return 0;
}