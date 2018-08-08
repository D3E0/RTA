//============================================================================
//Name：最大流 Edmonds_Karp
//https://blog.csdn.net/vonmax007/article/details/64921089
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;

#define N 220
#define INF 0x7f7f7f7f
//cap 容量  flow 当前流量
int cap[N][N], flow[N][N];
// res[i] 残量
int pre[N], res[N];

int Edmonds_Karp(int start, int end) {
    int maxflow = 0;
    memset(flow, 0, sizeof(flow));
    memset(pre, 0, sizeof(pre));
    queue<int> q;
    while (true) {
        memset(res, 0, sizeof(res));
        res[start] = INF;
        q.push(start);
        //BFS寻找增广路
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= end; v++)
                if (!res[v] && cap[u][v] > flow[u][v]) {
                    //start-v路径上的最小残量 d
                    res[v] = min(res[u], cap[u][v] - flow[u][v]);
                    //记录 v 的父亲，并加入队列中
                    pre[v] = u;
                    q.push(v);
                }
        }
        //无法继续更新最大流量，则当前流已经是最大流
        if (res[end] == 0) return maxflow;
        //从汇点往回走，对应边流量 加上 res[end]
        for (int u = end; u != start; u = pre[u]) {
            //更新正向流
            flow[pre[u]][u] += res[end];
            //更新反向流
            flow[u][pre[u]] -= res[end];
        }
        //更新从s流出的总流量
        maxflow += res[end];
    }
}

int main() {
//    memset(cap, 0, sizeof(cap));
//    for (/**/) {
//        int u, v, s;
//        scanf("%d %d %d", &u, &v, &s);
//        cap[u][v] += s;//要考虑到重边问题
//    }
//
    return 0;
}
