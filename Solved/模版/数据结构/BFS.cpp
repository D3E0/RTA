//============================================================================
//Name????????????? BFS
//??????·???????迪?????Node????????飬????????????????????????????????????
//Node path[25][25];
//path[New.x][New.y].x = cur.x;
//path[New.x][New.y].y = cur.y;
//============================================================================
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define N 5
int map[N][N];
bool vis[10][10];
//?????
struct Node {
	int x;
	int y;
	int cnt;			//??????????????
};
//????????
int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
void BFS(Node root, Node target);
bool Check(Node x);
int main() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//????????????
	Node root = { 0, 0, 0 };
	Node target = { 4, 4 };
	BFS(root, target);

	return 0;
}
void BFS(Node root, Node target) {
	queue<Node> Q;
	memset(vis, 0, sizeof(vis));

	//root???????
	Q.push(root);
	vis[root.x][root.y] = true;

	while (!Q.empty()) {

		//??ò????????????
		Node cur = Q.front();
		Q.pop();

		//??????к?cur????????н???????????
		for (int i = 0; i < 4; i++) {

			Node New =
					Node { cur.x + dir[i][0], cur.y + dir[i][1], cur.cnt + 1 };

			if (!vis[New.x][New.y] && Check(New)) {

				//?ж??????????????
				if (New.x == target.x && New.y == target.y) {
					cout << New.cnt << endl;
					return;
				}
				Q.push(New);
				vis[New.x][New.y] = true;
			}
		}
	}
}
bool Check(Node x) {
	if (map[x.x][x.y] == 0) {
		return true;
	}
	return false;
}
