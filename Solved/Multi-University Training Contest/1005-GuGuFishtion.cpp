//============================================================================
//Name：杭电多校第七场 1005 GuGuFishtion 莫比乌斯反演 数论
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 20;
const int MAX = static_cast<const int>(1e6 + 5);

bool vis[MAX];
int prime[MAX], phi[MAX], mu[MAX];
LL arr[MAX], inv[MAX];

void init() {
    int cnt = 0;
    mu[1] = phi[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                mu[i * prime[j]] = 0;
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            mu[i * prime[j]] = -mu[i];
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    int t;
    cin >> t;
    init();
    while (t--) {
        int m, n, p;
        cin >> m >> n >> p;
        if (m < n) swap(m, n);

        inv[1] = 1;
        rep(i, 2, n + 1) inv[i] = (p - p / i) * inv[p % i] % p;
        rep(i, 1, n + 1) arr[i] = i * inv[phi[i]] % p;

        LL ans = 0;
        rep(i, 1, n + 1) {
            LL cnt = 0;
            rep(j, 1, n / i + 1) {
                if (!mu[j]) continue;
                LL x = n / (1LL * i * j), y = m / (1LL * i * j);
                cnt = (cnt + mu[j] * x * y % p) % p;
            }
            ans = (ans + cnt * arr[i]) % p;
        }
        cout << ans % p << endl;
    }

    return 0;
}
