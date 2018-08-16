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

    int t;
    cin >> t;
    while (t--) {
        char arr[4][4];
        int n;
        cin >> n;
        rep(i, 0, 3) {
            rep(j, 0, 3) cin >> arr[i][j];
        }
        char str[100];
        rep(i, 0, n) {
            int x, y;
            cin >> str;
            int m = str[0] - '0';
            if (m == 1) x = 0, y = 0;
            else if (m == 2) x = 0, y = 1;
            else if (m == 3) x = 1, y = 0;
            else x = 1, y = 1;
            swap(arr[x][y], arr[x][y + 1]);
            swap(arr[x + 1][y], arr[x + 1][y + 1]);
            if (str[1] == 'C') swap(arr[x + 1][y + 1], arr[x][y]);
            else swap(arr[x][y + 1], arr[x + 1][y]);
        }
        rep(i, 0, 3) {
            rep(j, 0, 3) cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
