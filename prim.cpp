#include <iostream>
#include <fstream>
#define MAX 10000
using namespace std;

struct edge {
	int v, u, w;
};

int n, m;
int a[MAX];
edge mst[MAX];
bool visited[MAX];


void inpF() {
	ifstream ifs("data.txt");
	if (ifs.is_open()) {
		ifs >> n >> m;
		for (int i = 0; i < m; i++) {
			edge e;
			int x, y, z; ifs >> x >> y >> z;
			e.v = x; e.u = y; e.w = z;
			mst[i] = e;
		}
	}
}

void prim(int s) {
	int parent[MAX];
	int key[MAX];
	int mstW = 0;


	for (int i = 0; i < n; i++) {
		key[i] = INT_MAX;
		visited[i] = false;
		parent[i] = -1;
	}

	key[s] = 0;

	for (int count = 0; count < n - 1; count++) {
		int u = -1;
		int minKey = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && key[i] < minKey) {
				minKey = key[i];
				u = i;
			}
		}

		visited[u] = true;

		for (int i = 0; i < m; i++) {
			int v, weight;
			if (mst[i].v == u) {
				v = mst[i].u;
				weight = mst[i].w;
			}
			else if (mst[i].u == u) {
				v = mst[i].v;
				weight = mst[i].w;
			}
			else {
				continue;
			}

			if (!visited[v] && weight < key[v]) {
				key[v] = weight;
				parent[v] = u;
			}
		}
	}

	cout << "Cac canh : \n";
	for (int i = 1; i < n; i++) {
		cout << "(" << char(parent[i] + 65) << ", " << char(i + 65) << ") = " << key[i] << endl;
		mstW += key[i];
	}
	cout << "Tong  " << mstW << endl;

}

int main() {
	inpF();
	prim(0);
	system("pause");
	return 1;
}