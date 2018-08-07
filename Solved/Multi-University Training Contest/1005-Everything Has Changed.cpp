//============================================================================
//Name：杭电多校第五场 1005 Everything Has Changed 弧度 数学
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;
//acos(-1.0) = pi
const double PI = acos(-1.0);

//acos 参数范围 (-1.0, 1.0)
double norm(double x) {
    return min(max(x, -1.0), 1.0);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int m, R;
        cin >> m >> R;
        int x, y, r;
//      一个完整的圆的弧度是 2*pi
        double ans = 0, rem = 2 * PI;
        rep(i, 0, m) {
            cin >> x >> y >> r;
            int dis = x * x + y * y;
            if (dis > (R + r) * (R + r) || dis < (R - r) * (R - r)) continue;
            double sdis = sqrt(dis);
            double ang_1 = acos(norm((R * R + dis - r * r) / (2 * sdis * R)));
            double ang_2 = acos(norm((r * r + dis - R * R) / (2 * sdis * r)));
            ans += ang_2 * 2 * r;
            rem -= ang_1 * 2;
        }
//      弧长 L = r * ang
        ans += rem * R;
        printf("%.10lf\n", ans);
    }
    return 0;
}