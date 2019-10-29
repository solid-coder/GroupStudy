#include<stdio.h>
#define ABS(x)      (((x)>0)?(x):-(x))
#define MAX(x,y)    (x)>(y)?(x):(y)
 
int a[1 << 10];
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int k;
        scanf("%d", &k);
        int n = 1 << k;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        int ans = 0;
 
        while (n > 1) {
            for (int i = 0; i < n; i += 2) {
                ans += ABS(a[i] - a[i + 1]);
                a[i >> 1] = MAX(a[i], a[i + 1]);
            }
            n >>= 1;
 
        }
 
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}