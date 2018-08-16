//============================================================================
//Name：牛客多校第七场 1005 GuGuFishtion 莫比乌斯反演 数论
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int M = 100005;
const int N = 45;

LL n, m, q;
int t[M];

void add(int p, int x) { //给位置p增加x
    while (p <= n) t[p] += x, p += p & -p;
}

int ask(int p) { //求位置p的前缀和
    int res = 0;
    while (p) res += t[p], p -= p & -p;
    return res;
}

int range_ask(int l, int r) { //区间求和
    return ask(r) - ask(l - 1);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    cin >> m >> q >> n;
    n++;
    int x, y, z;
    while (q--) {
        cin >> x >> y;
        if (x == 0) {
            cin >> z;

        } else {

        }

    }


    return 0;
}
