#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int w[MAXN];
int v[MAXN];
int par[MAXN];
int Rank[MAXN];
bool a[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        Rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x || a[x]) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    if (Rank[x] < Rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (Rank[x] == Rank[y])Rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        char s[15];
        int n;
        cin >> n;
        init(n);
        for (int i = 1; i < n + 1; i++) {
            int pos;
            cin >> pos >> s;
            if (s[0] == 'w') {
                w[i] = pos;
            } else {
                v[i] = pos;
            }
        }
        cout << "wolf  ";
        for (int i = 1; i < n + 1; i++) {
            if (w[i] != 0) {
                int temp = w[i];
                set<int> si;
                int size = 0;
                si.insert(w[i]);
                while (v[temp] != 0 && size != si.size()) {
                    size = int(si.size());
                    temp = v[temp];
                    si.insert(temp);
                }
                if (temp == i) {
                    a[w[i]] = true;
                    cout << w[i] << " ";
                }
            }
        }
        cout << endl;
        for (int i = 1; i < n + 1; i++) {
            if (v[i]) {
                par[i] = find(v[i]);
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[find(i)];
        }
        cout << "0 " << sum << endl;
    }
    return 0;
}