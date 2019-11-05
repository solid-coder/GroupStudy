#include <stdio.h>
#define MAXN	10
#define INF		0x3f3f3f3f
#define MIN(x,y)	(x)<(y)?(x):(y)
#define MAX(x,y)	(x)>(y)?(x):(y)
#define F(m,d)	((m)/((d)*(d)))
int n;
double x[MAXN];
double m[MAXN];


int main()
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) {
			scanf("%lf", x + i);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf", m + i);
		}
		printf("#%d ", test_case);
		for (int i = 0; i < n - 1; ++i) {
			double l = x[i], r = x[i + 1];
			double mid;
			for (int c = 0; c < 50; ++c) {
				mid = (l + r) / 2;

				double lf = 0, rf = 0;
				int j;
				for (j = 0; x[j] < mid; ++j) {
					lf += F(m[j], (mid - x[j]));
				}
				for (; j < n; ++j) {
					rf += F(m[j], (mid - x[j]));
				}

				if (lf < rf) r = mid;
				else l = mid;
			}

			printf("%.10lf ", mid);

		}
		printf("\n");

	}
	return 0;
}