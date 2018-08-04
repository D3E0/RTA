//============================================================================
//Name���鲢���� merge_sort
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
	int i = left; //������ָ��
	int j = mid + 1; //������ָ��
	int t = 0; //��ʱ����ָ��
	int temp[100];
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		} else {
			temp[t++] = arr[j++];
		}
	}
	while (i <= mid) { //�����ʣ��Ԫ������temp��
		temp[t++] = arr[i++];
	}
	while (j <= right) { //��������ʣ��Ԫ������temp��
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
		merge_sort(arr, left, mid); //��߹鲢����ʹ��������������
		merge_sort(arr, mid + 1, right); //�ұ߹鲢����ʹ��������������
		merge(arr, left, mid, right); //����������������ϲ�����
	}
}
int main() {
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 10 };
	int n = 10;
	merge_sort(arr, 0, n - 1);
	display(arr, n);
	return 0;
}

