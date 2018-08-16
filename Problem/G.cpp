#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define M 100100
using namespace std;
int n;
double a[M], l[M], l2[M], f[M], l3[M];

int main() {
    int i;
    cin >> n;
    double ans = 0;
    for (i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        l[i] = (l[i - 1] + 1) * a[i];
        l2[i] = (l2[i - 1] + 2 * l[i - 1] + 1) * a[i];
        l3[i] = (l3[i - 1] + 3 * l2[i - 1] + 3 * l[i - 1] + 1) * a[i];
        f[i] = f[i - 1] + (3 * l2[i - 1] + 3 * l[i - 1] + 1) * a[i];
        ans += l3[i] - l3[i - 1] * a[i];
        printf("for i = %d f1 = %lf f2 = %lf f3 = %lf\n", i, l[i], l2[i], l3[i]);
    }
    printf("%.1lf %.1lf\n", f[n], ans);
    return 0;
}