//============================================================================
//Name：归并排序 merge_sort
//============================================================================
#include <iostream>
using namespace std;
void display(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void merge(int arr[], int left, int mid, int right) {
	int i = left; //左序列指针
	int j = mid + 1; //右序列指针
	int t = 0; //临时数组指针
	int temp[100];
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		} else {
			temp[t++] = arr[j++];
		}
	}
	while (i <= mid) { //将左边剩余元素填充进temp中
		temp[t++] = arr[i++];
	}
	while (j <= right) { //将右序列剩余元素填充进temp中
		temp[t++] = arr[j++];
	}
	t = 0;

	while (left <= right) {
		arr[left++] = temp[t++];
	}
}
void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid); //左边归并排序，使得左子序列有序
		merge_sort(arr, mid + 1, right); //右边归并排序，使得右子序列有序
		merge(arr, left, mid, right); //将两个有序子数组合并操作
	}
}
int main() {
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 10 };
	int n = 10;
	merge_sort(arr, 0, n - 1);
	display(arr, n);
	return 0;
}

