//============================================================================
//Name：牛客多校第七场 E Counting 4-Cliques 构造
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int N = 80;
//comb = C(n, 4)  tmp = C(x, 3)
int comb[N], n, k, tmp[N];
vector<int> v;
vector<pii> edges;

void func() {
    rep(i, 2, n + 1) {
        rep(j, 2, n + 1) {
            rep(q, 2, n + 1) {
                rep(p, 2, n + 1) {
                    rep(w, 2, n + 1) {
//                      C(a, 3)+C(b, 3)+C(c, 3)+C(d, 3)+C(e, 3) == k
                        int cnt = tmp[i] + tmp[j] + tmp[q] + tmp[p] + tmp[w];
                        if (cnt == k) {
//                          printf("%d %d %d %d %d\n", i, j, q, p, w);
                            v.pb(i), v.pb(j), v.pb(q), v.pb(p), v.pb(w);
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    mm(comb, 0), mm(tmp, 0);
    rep(i, 3, N) {
        comb[i] = i * (i - 1) * (i - 2) * (i - 3) / 24;
        tmp[i] = i * (i - 1) * (i - 2) / 6;
    }
    int t = 1;
    while (t--) {
        scanf("%d", &k);
        rep(i, 4, N) {
            if (k >= comb[i]) n = i;
            else break;
        }
//      n 个顶点的完全图  构造 C(n, 4) 个团，5 个顶点构造剩余的团
        n = min(n, 70);
        k -= comb[n];

//      枚举 5 个顶点分别与 n 中几个点相连
        func();

        rep(i, 1, n + 1) {
            rep(j, i + 1, n + 1) edges.pb(mp(i, j));
        }
        rep(i, 0, 5) {
            rep(j, 0, v[i]) {
                edges.pb(mp(n + 1 + i, j + 1));
            }
        }
        printf("%d %d\n", n + 5, edges.size());
        rep(i, 0, edges.size()) {
            printf("%d %d\n", edges[i].fi, edges[i].se);
        }
    }
    return 0;
}