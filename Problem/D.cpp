//============================================================================
//Name：牛客多校第七场 C Bit Compression 暴力深搜 剪枝
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 1e6;
const int MOD = 1e9 + 7;

int arr[N];
int cnt[N * 10];
struct ss {
    int x, y;
} f[N];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        mm(arr, 0);
        int a, b, c, d, n, p, q, mod;
        cin >> a >> b >> c >> d >> mod >> n;
        arr[1] = a;
        arr[2] = b;
        printf("%d %d ", a, b);
        mod = 1;
        rep(i, 3, n + 10) {
            arr[i] = (c * arr[i - 2] + d * arr[i - 1] + mod / i);
            printf("%d ", arr[i]);
        }
        printf("\n", 1);
        p = d, q = c;
        int delta = p * p + 4 * q;
        double x = (p - sqrt(delta)) / 2;
        double y = (p + sqrt(delta)) / 2;
        printf("%d %d ", a, b);
        rep(i, 3, n + 10) {
            double tmp = (b * (pow(y, i - 1) - pow(x, i - 1)) - q * a * (pow(x, i - 2) - pow(y, i - 2))) / (y - x);
            printf("%.2lf ", (tmp));
        }
        printf("\n", 1);
        int flag = 0;
        rep(i, 1, mod) {
            f[i].x = mod / (i + 1) + 1;
            f[i].y = mod / i;
            if (f[i].x == f[i].y) {
                flag = i;
                break;
            }
        }

        rep(i, 1, flag + 1) {
            int tmp = p / i;
            f[tmp].x = f[tmp].y = i;
        }


    }
    return 0;
}
