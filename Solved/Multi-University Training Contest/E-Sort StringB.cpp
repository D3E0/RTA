//============================================================================
//Name：牛客多校第三场 E Sort String 字符串Hash 
//https://www.nowcoder.com/acm/contest/141/E
//============================================================================
#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const int MAX = 2e6 + 50;

struct hash_table {
    ULL seed;
    ULL Hash[MAX], tmp[MAX];

    void set(ULL _seed) {
        seed = _seed;
    }

    void work(char *s, int n) {
        LL i, j;
        tmp[0] = 1;
        Hash[0] = 0;
        for (i = 1; i <= n; i++) {
            tmp[i] = tmp[i - 1] * seed;
        }
        for (i = 1; i <= n; i++) {
            Hash[i] = (Hash[i - 1] * seed + (s[i] - 'a'));
        }
    }

//    str[l..r]
    ULL get(int l, int r) {
        return (Hash[r] - Hash[l - 1] * tmp[r - l + 1]);
    }
} h;

char str[MAX];
unordered_map<LL, int> mymap;
vector<int> ans[MAX];

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
        str[i + len] = str[i];
    }

    h.set(2333);
    h.work(str, 2 * len);
    int cnt = 0;
    for (int i = 1; i <= len; i++) {
        LL tt = h.get(i, i + len - 1);
        if (!mymap.count(tt)) {
            mymap[tt] = cnt++;
        }
        ans[mymap[tt]].push_back(i - 1);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d", ans[i].size());
        for (int j : ans[i]) {
            printf(" %d", j);
        }
        puts("");
    }

    return 0;
}