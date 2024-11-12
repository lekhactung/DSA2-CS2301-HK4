#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
int a[MAX][MAX]; 
const int n ; 


int minKey(int key[], bool mstSet[]) {
	int min = MAX, min_index;

	for (int v = 0; v < n; v++) {
		if (!mstSet[v] && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}

void printMST(int parent[]) {
	int totalWeight = 0;
	for (int i = 1; i < n; i++) {
		cout << "(" << parent[i] << ", " << i << ") = " << a[i][parent[i]] << endl;
		totalWeight += a[i][parent[i]];
	}
	cout << "Tổng trọng số của cây khung nhỏ nhất: " << totalWeight << endl;
}

void primMST() {
	int parent[9];  
	int key[9];     
	bool mstSet[9]; 

	for (int i = 0; i < n; i++) {
		key[i] = MAX;
		mstSet[i] = false; 
	}

	
	key[0] = 0; 
	parent[0] = -1; 

	for (int count = 0; count < n - 1; count++) {
		
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		
		for (int v = 0; v < n; v++) {
			if (a[u][v] != 0 && !mstSet[v] && a[u][v] < key[v]) {
				key[v] = a[u][v];
				parent[v] = u;
			}
		}
	}

	printMST(parent);
}

int main() {
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

	primMST();
	system("pause");
	return 0;
}
