#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int n;
int c[100];
int dfs[100];
int ndfs[100];

void init() {
	n = 0;	
}

void input() {
	ifstream ifs("graphMatrix.txt");
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
	input();
	output();
	system("pause");
	return 1;
}