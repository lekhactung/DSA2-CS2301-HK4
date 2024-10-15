#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int n;

void init() {
	n = 0;
}

void input() {
	do {
		cout << "Nhap so dinh do thi n : ";
		cin >> n;
	} while (n<0 || n> MAX); 
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao dong thu " << i + 1 << " : ";
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

void inputFile() {
	ifstream ifs("graphMatrix.txt");
	if (ifs.is_open()) {
		ifs >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ifs >> a[i][j];
			}
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	init();
	inputFile();
	output();
	system("pause");
	return 1;
}