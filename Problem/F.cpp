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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

const ll N = 1000000;
int pr[N / 5], p[N + 100], tot, phi[N + 100];
ll f[N + 10], inv[N + 10];
int n, m, mod, _;

void init() {
    phi[1] = 1;
    p[1] = 1;
    rep(i, 2, N + 1) {
        if (!p[i]) p[i] = i, pr[++tot] = i, phi[i] = p[i] - 1;
        for (int j = 1; j <= tot && pr[j] * i <= N; j++) {
            p[i * pr[j]] = pr[j];
            if (p[i] == pr[j]) {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            } else phi[i * pr[j]] = phi[i] * (pr[j] - 1);
        }
    }
}

int main() {
    init();
    for (scanf("%d", &_); _; _--) {
        scanf("%d%d%d", &n, &m, &mod);
        if (n > m) swap(n, m);
        inv[1] = 1;
        for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ll ans = 0;
        for (int i = n; i >= 1; i--) {
            f[i] = (ll) (n / i) * (m / i);
            for (int j = i + i; j <= n; j += i) f[i] = f[i] - f[j];
            ans = (ans + f[i] % mod * i % mod * inv[phi[i]]) % mod;
        }
        printf("%lld\n", ans);
    }
}
