#include <iostream>
using namespace std;
#define MAX 1000

void input(int a[], int &n) {
	do {
		cout << "Nhap so luong phan tu : " << endl;
		cin >> n;
	} while (n < 0 || n > 100);
	for (int i = 0; i < n; i++) {
		//a[i] = rand() % 100 + 1;
		cout << "a[" << i << "] = ";
		cin >> a[i];
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

void interchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

int main() {
	int a[MAX];
	int n;
	input(a, n);
	output(a, n);
	interchangeSort(a, n);
	output(a, n);
	system("pause");
	return 1;
}