//============================================================================
//Name：杭电多校第六场 1001 oval-and-rectangle 积分
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;

typedef long long LL;
const int N = 205;
const double PI = acos(-1.0);

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        LL a, b;
        cin >> a >> b;
        double ans = (PI * a + 2 * b);
        LL tmp = static_cast<LL>(ans * 1e6);
        ans = 1.0 * tmp / 1e6;
        printf("%.6lf\n", ans);
    }
    return 0;
}