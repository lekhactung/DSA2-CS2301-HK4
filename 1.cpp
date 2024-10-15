#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int n;
int c[100];
int dfs[100];
int ndfs=0;

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
	ifs.close();
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;	
	}
}

void outputFile() {
	ofstream ofs("output.txt");
	if (ofs.is_open()) {
		ofs << 1;
	}
	else {
		cout << "Khong mo dc file! \n";
	}
}

void khoitaochuaxet() {
	for(int i = 0; i < n; i++) {
		c[i] = 1;
	}
}

void DFS(int s) //s là đỉnh bắt đầu
{
	stack <int> stack;
	stack.push(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while (!stack.empty())
	{
		if (v == n)
			stack.pop(u);
		for (v = 0; v<n; v++)
			if (a[u][v] != 0 && c[v] == 1)
			{
				stack.push(u);
				stack.push(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
	}
}

int main() {
	init();
	input();
	outputFile();
	system("pause");
	return 1;
}