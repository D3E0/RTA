//============================================================================
//Name£ºËØÊý»· DFS
//============================================================================
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
bool isprime[40];
bool vis[100];
int path[100];

void DFS(int cnt) {

	if (cnt == n && isprime[path[0] + path[n-1]]) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 2; i <= n; i++) {
		if (isprime[i + path[cnt - 1]] && !vis[i]) {
			path[cnt] = i;
			vis[i] = true;
			DFS(cnt+1);
			vis[i] = false;
		}
	}
}

void f() {
	for (int i = 2; i < 40; i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11) {
			isprime[i] = true;
			continue;
		}
		if (i == 23 || i == 13 || i == 29 || i == 17 || i == 19) {
			isprime[i] = true;
			continue;
		}
		if (i == 39 || i == 31 || i == 37) {
			isprime[i] = true;
			continue;
		}
	}
}

int main() {

	f();

	while (cin >> n && n != 0) {
		vis[1] = true;
		path[0] = 1;
		DFS(1);
	}
	return 0;

}

