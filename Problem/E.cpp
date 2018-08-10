#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, n) for (int i=a;i<n;i++)
#define per(i, a, n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;

ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

const int N = 2010;
int n, m, nxt[N], gor[N][N], god[N][N], mg[N];
ll ans;
char s[N][N];

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n + 1) {
        scanf("%s", s[i] + 1);
    }
//    go right
    rep(i, 1, n + 1) {
        rep(j, 0, 127) nxt[j] = m + 1;
        gor[i][m + 1] = m + 1;
        per(j, 1, m + 1) {
            gor[i][j] = gor[i][j + 1];
            gor[i][j] = min(gor[i][j], nxt[s[i][j]]);
            nxt[s[i][j]] = j;
        }
    }
//go down
    rep(j, 1, m + 1) {
        rep(i, 0, 127) nxt[i] = n + 1;
        god[n + 1][j] = n + 1;
        per(i, 1, n + 1) {
            god[i][j] = god[i + 1][j];
            god[i][j] = min(god[i][j], nxt[s[i][j]]);
            nxt[s[i][j]] = i;
        }
    }

    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            printf("(%c  %d  %d)  ", s[i][j], gor[i][j], god[i][j]);
        }
        printf("\n", 1);
    }

    rep(i, 1, n + 1) rep(j, 1, m + 1) {
            int g = god[i][j];
            rep(c, j, gor[i][j]) {
                g = min(g, god[i][c]);
                mg[c] = g;
            }
            g = gor[i][j] - 1;
            rep(c, i, god[i][j]) {
                g = min(g, gor[c][j] - 1);
                while (mg[g] <= c) --g;
                ans += g - j + 1;
            }
        }
    printf("%lld\n", ans);
}