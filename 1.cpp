#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
#define MAX 1000

int n = 0,m = 0;

void random() {
	ofstream ofs("bt1.txt",ios::in);
	if (ofs.is_open()) {
		cout << "So luong phan tu muon tao  : "; int n; cin >> n;
		ofs << n << endl;
		for (int i = 0; i < n; i++) {
			ofs << rand() % 100 + 1 << endl;
		}
		cout << "ghi file thanh cong! \n";
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
	ofs.close();
}

void inp(int a[MAX],int &n) {
	ifstream ifs("bt1.txt");
	if (ifs.is_open()) {
		ifs >> n;
		for (int i = 0; i < n; i++) {
			ifs >> a[i];
		}
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
	ifs.close();
}

void output(int a[MAX], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int max(int a[],int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[max]) {
			max = i;
		}
	}
	return a[max];
}
//
//void countingSort(int a[],int n,int &m) {
//	m = max(a, n);
//	int *count = new int[m];
//	count = { 0 };
//	for (int i = 0; i < n; i++) {
//		count[a[i]] += 1;
//	}
//	for (int i = 0; i <= m; i++) {
//		count[i] += count[i - 1];
//
//	}
//
//
//	delete []count;
//}

void Countingsort(int a[], int b[], int k, int n, int & kt)
{
	int i, j;
	int c[MAX];
	for (i = 0; i <= k; i++)
	{
		c[i] = 0;
	}
	for (j = 0; j < n; j++)
	{
		c[a[j]]++;
	}
	kt = 0;
	for (j = 0; j <= k; j++)
	{
		while (c[j]>0)
		{
			b[kt++] = j;
			c[j]--;
		}
	}
}

void CountingsortDesc(int a[], int b[], int k, int n, int & kt)
{
	int i, j;
	int c[MAX];
	for (i = 0; i <= k; i++)
	{
		c[i] = 0;
	}
	for (j = 0; j < n; j++)
	{
		c[a[j]]++;
	}
	kt = 0;
	for (j = k; j >= 0; j--)
	{
		while (c[j]>0)
		{
			b[kt++] = j;
			c[j]--;
		}
	}
}

void ShellSort(int a[], int n) {
	int j;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = a[i];
			for (j = i; j >= gap && a[j-gap] > temp; j -= gap) {
				a[j] = a[j-gap];
			}
			a[j] = temp;
		}
	}
}

void ShellSortDesc(int a[], int n) {
	int j;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = a[i];
			for (j = i; j >= gap && a[j - gap] < temp; j -= gap) {
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

void menu() {
	cout << "0. Khoi tao mang moi random!\n"
		<< "1. Counting Sort (Tang dan) \n"
		<< "2. Counting Sort (Giam dan) \n"
		<< "3. Shell Sort (Tang dan) \n"
		<< "4. Shell Sort (Giam dan) \n"
		<< "5. Bucket Sort (Tang dan) \n"
		<< "6. Bucket Sort (Giam dan) \n" 
		<< "-1. Thoat chuong trinh \n"
		<< "Lua chon : " ;
}

int main() {
	srand(time(NULL));
	int a[MAX], b[MAX];
	int kt,k;
	int choice;
	do {
		do {
			menu();
			cin >> choice;
			if (choice <-1 || choice > 6) {
				cout << "Lua chon khong hop le, vui long nhap lai! \n";
			}
		} while (choice < -1 || choice > 6);
		switch (choice)
		{
		case 0:
			random();
			inp(a, n);
			cout << "Mang moi la : "; output(a, n);
			break;
		case 1:
			k = max(a, n);
			Countingsort(a, b, k, n, kt);
			cout << "mang sau khi sap xep la :";
			output(b, kt);
			break;
		case 2:
			k = max(a, n);
			CountingsortDesc(a, b, k, n, kt);
			cout << "mang sau khi sap xep la :";
			output(b, kt);
			break;
		case 3:
			ShellSort(a, n);
			cout << "mang sau khi sap xep la :";
			output(a,n);
			break;
		case 4:
			ShellSortDesc(a, n);
			cout << "mang sau khi sap xep la :";
			output(a, n);
			break;
		}
	
		system("pause");
		system("cls");
	} while (choice != -1);
	
	return 1;
}