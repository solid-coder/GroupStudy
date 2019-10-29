#include <stdio.h>

int ret[5000], a[5000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)		a[i] = i;
	
	int ret_size = 0, a_size = n, step = 0;
	while (ret_size < n) {
		int cur_pick = 0;
		int i, j;
		for (i = 0, j = 0; i < a_size; ++i) {
			if ((step % m) == (m - 1)) {
				ret[ret_size++] = a[i];
				++cur_pick;
			}
			else {
				a[j++] = a[i];
			}
			++step;
		}
		a_size -= cur_pick;
	}

	printf("<");
	for (int i = 0; i < ret_size; ++i) {
		printf("%d", ret[i] + 1);
		if (i + 1 != ret_size)	printf(", ");
	}
	printf(">\n");
	return 0;
}
