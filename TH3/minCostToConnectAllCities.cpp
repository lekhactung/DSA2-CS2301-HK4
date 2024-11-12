#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

#define MAX 100
#define INF INT_MAX

void prim(int graph[MAX][MAX], int n, int start) {
	int key[MAX];      
	int parent[MAX];  
	bool visited[MAX]; 
					
	for (int i = 0; i < n; i++) {
		key[i] = INF;   
		visited[i] = false; 
	}

	key[start] = 0;    
	parent[start] = -1; 

	for (int count = 0; count < n - 1; count++) {
		int u = -1;
		int min = INF;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && key[i] < min) {
				min = key[i];
				u = i;
			}
		}
		visited[u] = true;

		for (int v = 0; v < n; v++) {
			if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
				key[v] = graph[u][v]; 
				parent[v] = u;  
			}
		}
	}


	int totalWeight = 0;
	//cout << "Các cạnh trong cây khung nhỏ nhất (MST):\n";
	for (int i = 1; i < n; i++) {
		cout << "(" << parent[i] << ", " << i << ") = " << graph[i][parent[i]] << endl;
		totalWeight += graph[i][parent[i]];
	}
	cout << "Tong trong so: " << totalWeight << endl;
}

int main() {
	int n;
	int graph[MAX][MAX];
	ifstream ifs("data2.txt");
	if (ifs.is_open()) {
		ifs >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ifs >> graph[i][j];
			}
		}
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
	ifs.close();


	prim(graph, n, 0);
	system("pause");
	return 0;
}
