#include <iostream>
#include <time.h>
using namespace std;
#define MAX 100000

void input(int a[], int &n) {
	do {
		cout << "Nhap so luong phan tu : " << endl;
		cin >> n;
	} while (n < 0 || n > 100000);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	/*	cout << "a[" << i << "] = ";
		cin >> a[i];*/
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void quickSort(int a[], int left, int right) {
	int pivot = a[(left + right) / 2];
	int l = left, r = right;
	do {
		while (a[l]<pivot) {
			l++;
		}
		while (a[r]>pivot) {
			r--;
		}
		if (l <= r) {
			swap(a[r], a[l]);
			l++; r--;
		}
	} while (l <= r);
	if (l<right) {
		quickSort(a, l, right);
	}
	if (left < r) {
		quickSort(a, left, r);
	}
}

int main() {
	int a[MAX];
	int n;
	clock_t s1, e1;
	input(a, n);
	s1 = clock();
	output(a, n);
	//quickSort(a, 0,n-1);
	bubbleSort(a, n);
	e1 = clock();
	output(a, n);
	double d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
	cout << "Thoi gian chay giai thuat la: " << d1 << endl;
	system("pause");
	return 1;
}