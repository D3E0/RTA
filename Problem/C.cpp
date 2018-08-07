//============================================================================
//Name：杭电多校第三场 J Heritage of Skywalkert 暴力
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

bool cmp(LL a, LL b) {
    return a > b;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    LL T;
    cin >> T;
    while (T--) {
        LL x, k, a[100], b[100], c[100];
        mm(a, 0), mm(b, 0), mm(c, 0);
        cin >> x >> k;
        stack<LL> s;
        set<LL> res;
        res.insert(x);
        while (x) {
            s.push(x % 10);
            x /= 10;
        }
        LL n = 0;
        while (!s.empty()) {
            LL x = s.top();
            s.pop();
            a[n] = b[n] = c[n] = x;
            n++;
        }

        sort(a, a + n, cmp);
        LL ans = 0, flag = 0;

        rep(i, 0, n) {
            if (b[i] != a[i]) {
                for (LL j = n - 1; j >= 0; j--) {
                    if (b[j] == a[i]) {
                        swap(b[j], b[i]);
                        LL tmp = 0;
                        rep(p, 0, n) {
                            tmp = tmp * 10 + b[p];
                        }
                        res.insert(tmp);
                        if (++ans == k) {
                            flag = 1;
                        }
                        break;
                    }
                }
            }
            if (flag) break;
        }

        sort(a, a + n);
        rep(i, 0, n) {
            if (a[i]) {
                flag = i;
                break;
            }
        }
        for (LL i = flag - 1; i >= 0; i--) {
            swap(a[i], a[i + 1]);
        }
        LL ans2 = 0;
        flag = 0;

        rep(i, 0, n) {
            if (c[i] != a[i]) {
                for (LL j = n - 1; j >= 0; j--) {
                    if (c[j] == a[i]) {
                        swap(c[j], c[i]);
                        LL tmp = 0;
                        rep(p, 0, n) {
                            tmp = tmp * 10 + c[p];
                        }
                        res.insert(tmp);
                        if (++ans2 == k) {
                            flag = 1;
                        }
                        break;
                    }
                }
            }
            if (flag) break;
        }

//        rep(i, 0, n) {
//            cout << c[i];
//        }
//        cout << " ";
//        rep(i, 0, n) {
//            cout << b[i];
//        }
//        cout << endl;

        cout << *res.begin() << " " << *(--res.end()) << endl;
    }
    return 0;
}