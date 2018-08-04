//============================================================================
//Name：线性筛求素数表
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;
int prime[N];
bool notprime[N];

void getPrime() {
	int cnt = 0;
	memset(notprime, 0, sizeof(notprime));
	for (int i = 2; i < N; i++) {
		if (!notprime[i]) {
			prime[cnt++] = i;
		}
		//cout << "for i = " << i << "筛掉:" << ' ';
		for (int j = 0; j < cnt && i * prime[j] < N; j++) {
			notprime[i * prime[j]] = true;
			cout << i * prime[j] << "  ";
			if (i % prime[j] == 0) {
				break;
			}
		}
		//cout << endl;
	}
}

int main() {
	getPrime();
	for (int i = 0; prime[i] != 0; i++) {
		cout << prime[i] << " ";
	}
	cout << endl;
	return 0;
}

