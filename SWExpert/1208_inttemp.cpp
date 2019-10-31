#include <stdio.h>
#define MAX_SIZE	100
int a[MAX_SIZE];

int main()
{
	int T;
	T = 10;
	for (int tc = 1; tc <= T; ++tc) {
		int k;
		scanf("%d", &k);
		for (int i = 0; i < MAX_SIZE; ++i) {
			scanf("%d", a + i);
		}
		int temp;
		int i;
		int j;
		while (k--) {
			//insertsort
			
			for (i = 1; i < MAX_SIZE; i++)
			{
				temp = a[i];
				j = i - 1;

				while ((j >= 0) && (temp < a[j]))
				{
					a[j + 1] = a[j];
					j = j - 1;
				}
				a[j + 1] = temp;
			}
			//
			a[99]--;
			a[0]++;
		}
		int max = a[99] > a[98] ? a[99] : a[98];
		int min = a[0] < a[1] ? a[0] : a[1];
		printf("#%d %d\n", tc, max-min);
	}
	return 0;
}
