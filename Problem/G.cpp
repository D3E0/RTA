//============================================================================
//Name：杭电多校第五场 1002 Beautiful Now 交换次数 全排列枚举
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
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
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
//      变成有序最多交换 n-1 次
        if (k >= n - 1) {
            sort(a, a + n);
            int tmp = 0;
            for (int i = n - 1; i >= 0; i--) tmp = tmp * 10 + a[i];
            MAX = tmp;
            rep(i, 0, n) {
                if (a[i]) {
                    tmp = i;
                    break;
                }
            }
            for (int i = tmp - 1; i >= 0; i--) swap(a[i], a[i + 1]);
            rep(i, 0, n) printf("%d", a[i]);
            printf(" %d\n", MAX);
            continue;
        }

//      c[j] --> j 这个数对应的位置
        rep(i, 0, n) {
            b[i] = i;
            c[i] = i;
        }

        do {
            mm(vis, 0);
            if (!a[b[0]]) continue;
//          从 b 经过几步交换变成 c
            int cnt = 0;
            rep(i, 0, n) {
                if (!vis[i]) {
                    int j = b[i];
                    while (i != c[j]) {
                        vis[c[j]] = 1;
                        j = b[c[j]];
                    }
                    cnt++;
                }
            }
//         n - cnt 即交换次数
            if (n - cnt <= k) {
                int tmp = 0;
                rep(i, 0, n) tmp = tmp * 10 + a[b[i]];
                MAX = max(tmp, MAX);
                MIN = min(tmp, MIN);
            }
        } while (next_permutation(b, b + n));
//        全排列数位对应关系  不能全排列数值，数值会重复

        printf("%d %d\n", MIN, MAX);

    }
    return 0;
}