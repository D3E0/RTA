//
// Created by ACM-PC on 2018/7/17.
// HDU1285 确定比赛名次 拓扑排序
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 505;
vector<int> graph[maxN];
queue<int> res;
priority_queue<int, vector<int>, greater<int> > que;
int vertexNum, edgeNum;

void display() {
    for (int i = 1; i <= vertexNum; ++i) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    while (cin >> vertexNum >> edgeNum) {

        for (int i = 1; i <= vertexNum; i++) {
            graph[i].clear();
            graph[i].push_back(0);
        }

        for (int i = 0; i < edgeNum; i++) {
            int x, y;
            cin >> x >> y;
            graph[y][0]++;
            graph[x].push_back(y);
        }

        //    display();

        for (int i = 1; i <= vertexNum; i++) {
            if (graph[i][0] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int vertex = que.top();
            res.push(vertex);
            que.pop();
            for (int i = 1; i < graph[vertex].size(); i++) {
                int temp = graph[vertex][i];
                graph[temp][0]--;
                if (graph[temp][0] == 0) {
                    que.push(temp);
                }
            }
        }

        cout << res.front();
        res.pop();
        while (!res.empty()) {
            cout << " " << res.front();
            res.pop();
        }
        cout << endl;

    }

    return 0;
}



