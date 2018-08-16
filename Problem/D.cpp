//============================================================================
//Name：牛客多校第八场 1005 Magic Square 模拟
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 100;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    int n;
    cin >> n;
    char str[5][100005], op[100005];
    rep(i, 0, n) {
        cin >> str[i];
    }
    cin >> op;

    int len = strlen(op);
    stack<char> s;
    rep(i, 0, len) {
        if (op[i] == '-' && !s.empty()) s.pop();
        else if (op[i] != '-')s.push(op[i]);
    }

    return 0;
}
