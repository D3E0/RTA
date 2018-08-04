//============================================================================
//Name：普通筛求素数表
//============================================================================

#include<iostream>
#include<cstring>
using namespace std;

const int N = 500000;
bool notprime[N];
int prime[N];

void getPrime() {
	int cnt = 0;
	memset(notprime, 0, sizeof(notprime));
	for (int i = 2; i < N; i++) {
		if (!notprime[i]) {
			prime[cnt++] = i;
			for (int j = i * i; j < N; j += i) {
				notprime[j] = true;
			}
		}

	}
}

int main() {
	getPrime();
	for (int i = 0; prime[i] != 0; i++) {
		cout << prime[i] << endl;
	}
}

