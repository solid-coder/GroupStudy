#include <iostream>
#define res 1E-12
using namespace std;

int T, N;

struct OBJ{
	double x, m;
}obj[10];

double ans[9];

double solve(double low, double high){
	double mid = 0, value = 0;

	while (high - low >= res){
		value = 0;
		mid = (high + low) / 2;

		for (int i = 0; i < N; i++){
			if (obj[i].x > mid)
				value += obj[i].m / ((obj[i].x - mid) * (obj[i].x - mid));
			else if (obj[i].x < mid)
				value -= obj[i].m / ((mid - obj[i].x) * (mid - obj[i].x));
			else{
				cout << "div by zero";
				return -1;
			}
		}

		if (value > 0)
			high = mid;
		else if (value < 0)
			low = mid;
		else
			return mid;
	}

	return mid;
}

int main(int argc, char** argv){
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++){
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%lf", &obj[i].x);
		for (int i = 0; i < N; i++)
			scanf("%lf", &obj[i].m);

		for (int i = 0; i < N - 1; i++)
			ans[i] = solve(obj[i].x, obj[i+1].x);

		printf("#%d ", testcase);
		for (int i = 0; i < N - 1; i++)
			printf(" %.10lf", ans[i]);
		printf("\n");
	}
	
	return 0;
}