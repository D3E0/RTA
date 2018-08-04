//============================================================================
//Name：牛客多校第六场 D Bulbasaur
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;
const int N = 1e5 + 7;
int a[N];

int main() {
    IO;
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t, cnt = 0;
    cin >> t;
    while (t--) {
        int n, m, k;
        int x, y, z;
//        memset(a, 0, sizeof(a));
        mm(a, 0);
        cin >> n >> m >> k;
        rep(i, 0, k) {
            cin >> x >> y >> z;
            a[y] = max(a[y], z);
        }
        LL ans = 0;
        rep(i, 1, m + 1) {
            ans += a[i];
        }
        printf("Case #%d: %lld\n", ++cnt, ans);

    }
    return 0;
}

