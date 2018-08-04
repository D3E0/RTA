//============================================================================
//Name：牛客多校第二场 J Farm 二维差分 随机化解
//https://www.nowcoder.com/acm/contest/140/J
//============================================================================
#include <bits/stdc++.h>

typedef long long LL;
using namespace std;

//返回大于 n*m(1e6) 的随机数
inline LL rrand() { return (1LL * rand() << 15) + rand(); }

int main() {
    int n, m, k;
    srand(233);

    scanf("%d %d %d", &n, &m, &k);

//    随机数容器
    vector<LL> r(n * m + 1);
//    累加值
    vector<vector<LL>> a(n + 2, vector<LL>(m + 2));
//    初始值
    vector<vector<int>> b(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n * m; i++) {
        r[i] = rrand();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

// a[i][j] 差分，通过二维差分将区间修改的复杂度降为T；
    for (int i = 1; i <= k; i++) {
        int x1, x2, y1, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
//      施加的肥料映射到 r[c]
        a[x1][y1] += r[c];
        a[x2 + 1][y1] -= r[c];
        a[x1][y2 + 1] -= r[c];
        a[x2 + 1][y2 + 1] += r[c];
    }

// a[i][j] 差分 --> 单点值，区间更新复杂度为 (nm + t)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
//          施加的肥料为初始值的倍数很大可能施加的是同一种肥料
//          因为存在多次施加和为初始值倍数情况
            if (a[i][j] % r[b[i][j]] != 0) {
//                printf("(%d, %d) \n", i, j);
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}