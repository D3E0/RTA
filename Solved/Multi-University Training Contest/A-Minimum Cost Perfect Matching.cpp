//============================================================================
//Name：牛客多校第七场 A Minimum Cost Perfect Matching 构造
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))
#define pb push_back

using namespace std;
typedef long long LL;

const int N = 20;
int tmp[N];
vector<int> res;

void func(int x) {
    if (!x) return;
    int y = *lower_bound(tmp, tmp + N, x), offset = y - x;
    for (int i = x - 1; i >= offset; i--) res.pb(x - i + offset);
    func(offset);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    tmp[0] = 1;
    rep(i, 1, N) tmp[i] = 2 * tmp[i - 1];
    int t = 1;
//    cin >> t;
    while (t--) {
        int n;
        res.clear();
        cin >> n;
        func(n);
        for (int i = res.size() - 1; i >= 0; i--) printf("%d ", res[i] - 1);
        printf("\n", 1);
    }
    return 0;
}