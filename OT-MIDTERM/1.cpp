#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#define MAX 100
#define INF 10000000
using namespace std;

int n;
int matrix[MAX][MAX];
char name[] = { 'A','B','C','D','E','F','G','H','I' };
void inp() {
	ifstream ifs("data.txt");
	if (!ifs.is_open()) {
		return;
	}
	ifs >> n;
	int m[MAX];
	for (int i = 0; i < n; i++) {
		ifs >> m[i];
	}
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < m[i]; i++) {
			int x, y, w; ifs >> x >> y >> w;
			matrix[x][y] = matrix[y][x] = w;
		}
	}
	ifs.close();
}

void output() {
	cout << " ";
	for (int i = 0; i < n; i++) {
		cout << " " << name[i];
	} 
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << name[i] << " ";
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void outputlist() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][j] != 0) {
				cout << name[i] << " - " << name[j] << " : " << matrix[i][j] << endl;
			}
		}
	}
}

void initVisited(bool visited[]) {
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
}

void DFS(int u) {
	stack <int> s;
	s.push(u);
	bool visited[MAX];
	initVisited(visited);
	while (!s.empty()) {
		int p = s.top(); s.pop();
		visited[p] = true;
		cout << name[p] << " ";
		for (int i = 0; i < n; i++) {
			if (matrix[p][i] && !visited[i]) {
				s.push(i);
				break;
			}
		}
	}
}

//int bfs[MAX], nbfs = 0;
void BFS(int u) {
	bool visited[MAX] = { false };
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int p = q.front(); q.pop();
		//bfs[nbfs++] = p;
		cout << name[p] << " ";
		for (int i = 0; i < n; i++) {
			if (matrix[p][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void prim() {
	int parent[MAX], key[MAX];
	fill(key, key + MAX, INF);
	bool inMST[MAX] = { false };
	parent[0] = -1;
	key[0] = 0;
	for (int i = 0; i < n; i++) {
		int minkey = INF, u;
		for (int j = 0; j < n; j++) {
			if (!inMST[j] && key[j] < minkey) {
				minkey = key[j];
				u = j;
			}
		}
		inMST[u] = true;
		for (int j = 0; j < n; j++) {
			if (matrix[u][j]!=0 && !inMST[j] && matrix[u][j] < key[j]) {
				parent[j] = u;
				key[j] = matrix[u][j];
			}
		}
	}
	for (int i = 1; i < n; i++) {
		cout << name[parent[i]] << " - " << name[i] << " : " << matrix[parent[i]][i] << endl;
	}
}

struct edge {
	int u, v, w;
};
edge edges[MAX];
int parent[MAX];
bool cmp(edge a, edge b) {
	return a.w > b.w;
}

void swap(edge &a, edge &b) {
	edge tmp = a;
	a = b;
	b = tmp;
}

int findParent(int u) {
	if (parent[u] == u) return u;
	return parent[u] = findParent(parent[u]);
}

void kruskal() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][j]!=0) {
				edge tmp; tmp.u = i; tmp.v = j; tmp.w = matrix[i][j];
				edges[count++] = tmp; 
			}
		}
	}
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (cmp(edges[i], edges[j])) {
				swap(edges[i], edges[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
	}
	int totalW = 0;
	for (edge e : edges) {
		int uRoot = findParent(e.u);
		int vRoot = findParent(e.v);
		if (uRoot != vRoot) {
			cout << name[e.u] << " - " << name[e.v] << " : " << e.w << endl;
			totalW += e.w;
			parent[uRoot] = vRoot;
		}
	}
	cout << "Tong trong so la: " << totalW << endl;
}

void test() {
	inp();
	//outputlist();
	//DFS(0);
	BFS(0);;
	//prim();
	//kruskal();
}



int main() {
	test();
	system("pause");
	return 1;
}