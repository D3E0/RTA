//============================================================================
//Name：杭电多校第三场 J Heritage of Skywalkert 暴力
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\91417\CLionProjects\RTA\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\91417\CLionProjects\RTA\Problem\out)", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int k, a[15], b[15], c[15], vis[15];
        int MAX = INT_MIN, MIN = INT_MAX;
        string str;
        cin >> str >> k;
        int n = str.length();
        rep(i, 0, n) {
            a[i] = str[i] - '0';
        }

        rep(i, 0, n) {
            b[i] = i;
        }
        do {
            mm(vis, 0);
            if (!a[b[0]]) continue;
            rep(i, 0, n) {
                c[i] = i;
            }
            int cnt = 0;
            rep(i, 0, n) {
                if (!vis[i]) {
                    vis[i] = 1;
                    int j = c[i];
                    while (i != c[j]) {
                        j = c[j];
                        vis[j] = 1;
                    }
                    cnt++;
                }
            }
            cnt = n - cnt;
            if (cnt <= k) {
                int tmp = 0;
                rep(i, 0, n) {
                    tmp = tmp * 10 + a[b[i]];
                }
                MAX = max(tmp, MAX);
                MIN = min(tmp, MIN);
            }
        } while (next_permutation(b, b + n));
//        全排列数位对应关系  不能全排列数值，数值会重复

        printf("%d %d\n", MIN, MAX);

    }
    return 0;
}