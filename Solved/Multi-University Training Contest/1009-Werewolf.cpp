//============================================================================
//Name：杭电多校第六场 1009 Werewolf 并查集 推理
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;
const int N = static_cast<const int>(1e5 + 10);

int n, mynext[N], flag[N], vis[N], par[N], wolf[N];

int find(int x) {
    if (wolf[x] || par[x] == x) return x;
    return par[x] = find(par[x]);
}

int main() {
    IO;
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        string str;
        mm(flag, 0), mm(wolf, 0), mm(par, 0);
        vis[0] = 1;
        rep(i, 1, n + 1) {
            cin >> mynext[i] >> str;
            par[i] = i;
            if (str == "werewolf") flag[i] = 1;
        }
        rep(i, 1, n + 1) {
//            狼边开始
            if (flag[i]) {
                int j = mynext[i];
                set<int> si;
                int size = 0;
                si.insert(j);
//                找民边
                while (!flag[j] && size != si.size()) {
                    size = int(si.size());
                    j = mynext[j];
                    si.insert(j);
                }
                if (j == i) wolf[mynext[i]] = 1;
            }
        }

        rep(i, 1, n + 1) {
            if (!flag[i]) par[i] = find(mynext[i]);
        }

        int ans = 0;
        rep(i, 1, n + 1) {
            if (wolf[find(i)]) ans++;
        }

        cout << 0 << " " << ans << endl;

    }
    return 0;
}