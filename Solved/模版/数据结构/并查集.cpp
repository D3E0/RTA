//============================================================================
//Name：并查集
//============================================================================

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 105;
int par[N];//父亲
int rank[N];//树的高度

//初始化N个元素,包括对所有单个的数据建立一个单独的集合
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

//查询树的根
int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

//合并x和y所属的集合
void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) par[x] = y;
    else {
        par[x] = y;
        if (rank[x] == rank[y]) rank[x]++;
    }
}
//判断是否属于同一个集合
bool same(int x, int y) {
    return find(x) == find(y);
}


int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif


    return 0;
}