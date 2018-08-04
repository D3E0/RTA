//============================================================================
//Name：二分查找求上、下界  浮点数二分
//============================================================================
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1000;

bool check(long long x) {
	return true;
}

//上界，返回其出现的最后一个位置的后面一个位置
long long upper_bound() {
	long long low = 0;
	long long high = MAX;
	long long mid;
	while (low < high) {
		mid = (high + low) >> 1;
		if (check(mid)) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return high;
}

//下界
long long lower_bound() {
	long long low = 0;
	long long high = MAX;
	long long mid;
	while (low < high) {
		mid = (high + low) >> 1;
		if (check(mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int main() {

	return 0;
}

