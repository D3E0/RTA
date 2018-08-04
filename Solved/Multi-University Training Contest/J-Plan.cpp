//============================================================================
//Name：牛客多校第五场 J Plan
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)

using namespace std;
typedef long long LL;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    LL n, x, y, ans = (1LL << 62);
    scanf("%lld %lld %lld", &n, &x, &y);

    rep(i, 0, 10) {
        ans = min(ans, i * 1LL * x + max(0LL, (n - i * 2 + 2) / 3) * 1LL * y);
    }
    rep(i, 0, 10) {
        ans = min(ans, i * 1LL * y + max(0LL, (n - i * 3 + 1) / 2) * 1LL * x);
    }
    printf("%lld\n", ans);
    return 0;
}

