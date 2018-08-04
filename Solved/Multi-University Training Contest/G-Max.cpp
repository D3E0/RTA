//============================================================================
//Name：牛客多校第五场 G Max
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

    int c, n;
    scanf("%d%d", &c, &n);
    if (n < c) {
        printf("-1\n");
        return 0;
    }
    int d = n / c;
    if (d == 1) {
        printf("%lld\n", c * 1ll * c);
    } else {
        printf("%lld\n", c * 1ll * c * (d * 1ll * (d - 1)));
    }
    return 0;
}

