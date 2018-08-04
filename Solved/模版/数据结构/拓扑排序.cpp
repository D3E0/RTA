//============================================================================
//Name��˹���ֹ�ʽ  ��N���Ľ���ֵ
//============================================================================
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int N = 505;
vector<int> Graph[N];
int TopNum[N], NodeNum[N];;
int NumVertex, NumEdge;

// �����޻�ͼһ������������
void TopSort() {
    // ά�����Ϊ0�Ľڵ㣬��Ŵ�С�������򣬱�֤���С�Ľڵ��������С
    priority_queue<int, vector<int>, greater<int> > que;
    // �����Ϊ0�Ľڵ�������
    for (int i = 1; i <= NumVertex; ++i) {
        if (Graph[i][0] == 0) que.push(i);
    }
    // ѭ���������Ϊ0�Ľڵ㣬������������
    int cnt = 0;
    while (!que.empty()) {
        int u = que.top();
        que.pop();
        // �����С������Ÿ������Ϊ0�ҵ�ǰ�����С�Ľڵ�
        TopNum[u] = ++cnt;
        // ɾ���ڵ�u�����ıߣ������������ڵ�����
        for (int i = 1; i < Graph[u].size(); ++i) {
            // �����������Ϊ0�Ľڵ�������
            if (--Graph[Graph[u][i]][0] == 0) que.push(Graph[u][i]);
        }
    }
    // ͼ�д��ڻ�����������
    if (cnt != NumVertex) return;
    // ���ͼ����һ����ȫ��ͨ�ģ���ô��ԭͼ��ĳһ��ͨ�����Ƿ���ڻ���
    for (int i = 1; i <= NumVertex; ++i) {
        if (Graph[i][0])  {
            puts("somerwhere of the graph has a cycle");
        }
    }

    // ��������������еĽڵ���
    for (int i = 1; i <= NumVertex; ++i) {
        NodeNum[TopNum[i]] = i;
    }

    for (int i = 1; i <= NumVertex; ++i) {
        printf("%d%c", NodeNum[i], i == NumVertex ? '\n' : ' ');
    }

}

int main() {
    //freopen("sample.txt", "r", stdin);
    while (~scanf("%d%d", &NumVertex, &NumEdge)) {
        // ��ʼ��
        for (int i = 1; i <= NumVertex; ++i) {
            Graph[i].clear();
            // ��ʼ�����
            Graph[i].push_back(0);
        }
        // ��ͼ
        for (int i = 1; i <= NumEdge; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            // ʹ���ڽӱ�ʱ���ر߶�����������Ӱ�죬���Կ��Բ��ô���
            //if(find(Graph[u].begin(), Graph[u].end(), v)
            //   == Graph[u].end())
            {
                Graph[u].push_back(v);
                // v�ڵ����ȼ�1
                ++Graph[v][0];
            }
        }
        // ��������
        TopSort();
    }
    return 0;
}


