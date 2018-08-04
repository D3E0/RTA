//============================================================================
//Name：牛客多校第六场 A Singing Contest 模拟
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)

using namespace std;
typedef long long LL;

priority_queue<int, vector<int>, greater<int> > Q[1026 * 16 + 5];
set<int> s[1026 * 16 + 5];
queue<int> ans;

int main() {
    IO;
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t, cnt = 0;
    cin >> t;
    while (t--) {
        int n, N, x;
        while (!ans.empty()) {
            ans.pop();
        }
        cin >> n;
        N = static_cast<int>(pow(2, n));
        rep(i, 0, N) {
            s[i].clear();
            rep(j, 0, n) {
                cin >> x;
                s[i].insert(x);
            }
            ans.push(i);
        }

        while (ans.size() > 1) {
            int p = ans.front();
            ans.pop();
            int q = ans.front();
            ans.pop();
            if (*(--s[p].end()) < *(--s[q].end())) {
                swap(p, q);
            }
            s[p].erase(s[p].lower_bound(*(--s[q].end())));
            ans.push(p);
        }
        printf("Case #%d: %d\n", ++cnt, ans.front() + 1);
    }

    return 0;
}

