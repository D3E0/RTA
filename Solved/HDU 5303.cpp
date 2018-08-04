//
// Created by ACM-PC on 2018/7/17.
// HDU5303 Delicious Apples 贪心 枚举
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
    int l, n, k;
    int t;
    cin >> t;
    while (t--) {
        cin >> l >> n >> k;
        vector<long long> left, right; //苹果离散化，第 i 苹果的位置
        left.push_back(0);
        right.push_back(0);

        for (int i = 0; i < n; i++) {
            int dis, num;
            scanf("%d %d", &dis, &num);
            if (dis * 2 < l) {
                for (int j = 0; j < num; j++) {
                    left.push_back(dis); //左半环
                }
            } else {
                for (int j = 0; j < num; j++) {
                    right.push_back(l - dis); //右半环
                }
            }
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        for (int i = k; i < left.size(); i++) {
            left[i] += left[i - k]; //第 i 个苹果所需的花费
        }
        for (int i = k; i < right.size(); i++) {
            right[i] += right[i - k];
        }
        long long ans = (left.back() + right.back()) * 2;

//		枚举中间剩余 k 个的情况
        for (int i = 0; i <= k; i++) {
            int left_index = left.size() - 1 - i;
            int right_index = right.size() - 1 - (k - i);
            if (left_index < 0) {
                left_index = 0;
            }
            if (right_index < 0) {
                right_index = 0;
            }
            ans = min(ans, left[left_index] * 2 + right[right_index] * 2 + l);
        }
        cout << ans << endl;
    }
}
