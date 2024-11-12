#include <fstream>
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX][MAX];
int n;
int E1[MAX], E2[MAX], wE[MAX];
int nE = 0;

int T1[MAX], T2[MAX], wT[MAX];
int nT = 0;

int TonTai(int d, int D[], int nD) {
	for (int i = 0; i < n; i++) {
		if (D[i] == d) {
			return 1;
		}
	}
	return 0;
}

void XoaViTriE(int i)
{
	for (int j = i; j<nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i = 0; i<nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}
// Hàm Prim
void prim(int s) // s là đỉnh bắt đầu
{
	int u = s, min, i, d1, d2;
	while (nT<n - 1)
	{
		for (int v = 0; v<n; v++)
			if (a[u][v] != 0)
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u; E2[nE] = v;
					wE[nE] = a[u][v]; nE++;
				}
		for (i = 0; i<nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i]; d1 = E1[i];
				d2 = E2[i]; break;
			}
		for (; i<nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if (min>wE[i])
				{
					min = wE[i]; d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1; T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0; a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}

void inp() {
	ifstream ifs("data2.txt");
	if (ifs.is_open()) {
		ifs >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ifs >> a[i][j];
			}
		}
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
	ifs.close();
}

void input() {
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ma tran ke cua do thi : ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

void output()
{
	int tong = 0;
	for (int i = 0; i<nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong = " << tong << endl;
}

void menu() {
	cout << "1. Nhap do thi tu ban phim \n"
		<< "2. Nhap do thi tu file \n"
		<< "3. Prim \n"
		<< "0. Thoat ! \n"
		<< "Lua chon : ";
}
int main() {
	int choice;
	do {
		do {
			system("cls");
			menu();
			cin >> choice;
			if (choice == 0) {
				break;
			}
			if (choice != 1 && choice != 2 && choice != 3) {
				cout << "Lua chon khong hop le! \n";
			}
		} while (choice != 1 && choice != 2 && choice != 3);
		switch (choice)
		{
		case 1:
			input();
			break;
		case 2:
			inp();
			break;
		case 3:
			int x;
			cout << "Nhap dinh bat dau: "; cin >> x;
			prim(x);
			output();
			break;
		default:
			break;
		}
	} while (choice != 0);
	system("pause");
	return 1;
}