//============================================================================
//Name：字符串 Hash
//============================================================================
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const int MAX = 2e6 + 10;

struct hash_table {
    ULL seed;
    ULL Hash[MAX], tmp[MAX];

//  seed 2333
    void set(ULL _seed) {
        seed = _seed;
    }

//  hash str[1...n]
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

    ULL get(int l, int r) {
        return (Hash[r] - Hash[l - 1] * tmp[r - l + 1]);
    }
} h;

int main() {

    return 0;
}