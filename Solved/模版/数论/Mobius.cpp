//============================================================================
//Name��Ī����˹����ɸ:������������ɸ
//��iΪ��������ͬ����֮��mob[i] = -1
//��iΪż������ͬ����֮��mob[i] = 1
//��i��ƽ��������mob[i] = 0��
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
int prime[MAX];
bool notprime[MAX];
int mob[MAX];

void get_mobius() {
	int cnt = 0;
	mob[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!notprime[i]) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
			notprime[i * prime[j]] = true;
			mob[i] = -1;
			if (i % prime[j] == 0) {
				mob[i * prime[j]] = 0;
				break;
			}
			mob[i * prime[j]] = -mob[i];
		}
	}
}

int main() {
	get_mobius();
	for (int i = 1; i < MAX; i++) {
		cout << mob[i] << " ";
	}
	cout << endl;
	return 0;
}

