//============================================================================
//Name£∫√‘π¨Œ Ã‚
//============================================================================
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

set<int> s;
int dir[3][4] = { { 3, -3, 1, -1 }, { 3, -3, 1 }, { 3, -3, -1 } };

struct Node {
	string str;
	int cnt;
};

bool check(string str) {
	int value = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			value = value * 10;
		} else {
			value = value * 10 + str[i] - '0';
		}
	}
	if (!s.count(value)) {
		s.insert(value);
		//cout << "for string = " << str << endl;
		return true;
	} else {
		return false;
	}

}

int BFS(string str, string end) {

	queue<Node> q;

	Node node = { str, 0 };
	check(str);
	q.push(node);

	while (!q.empty()) {

		Node cur = q.front();
		q.pop();
		//cout << "------for string : " << cur.str << endl;
		int loc = cur.str.find('.');
		int n, f;
		if (loc % 3 == 0) {
			f = 1;
			n = 3;
		} else if (loc % 3 == 2) {
			f = 2;
			n = 3;
		} else {
			f = 0;
			n = 4;
		}
		for (int i = 0; i < n; i++) {
			int z = loc + dir[f][i];
			if (z >= 0 && z <= 8) {
				node.str = cur.str;
				node.str[z] = '.';
				node.str[loc] = cur.str[z];
				if (node.str == end) {
					return cur.cnt + 1;
				}
				if (check(node.str)) {
					node.cnt = cur.cnt + 1;
					q.push(node);
				}
			}
		}

	}
	return -1;
}

int main() {
	string str;
	string end;
	cin >> str;
	cin >> end;
	if (str == end) {
		cout << 0 << endl;
	} else {
		cout << BFS(str, end) << endl;
	}

	return 0;
}

