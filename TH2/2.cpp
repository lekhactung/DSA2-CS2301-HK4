#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
#define MAX 100

int adj[MAX][MAX] = { 0 };
bool visited[MAX] = { false };

int n, m;
void inp() {
	ifstream ifs("data1.txt");
	ifs >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; ifs >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
}

int ndfs[MAX], nbfs[MAX];
int cnt = 0, cnt1 = 0;

void dfs(int v, int n, int adj[MAX][MAX], bool visited[MAX]) {
	visited[v] = true;
	ndfs[cnt++] = v;
	//cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && adj[v][i] == 1) {
			dfs(i, n, adj, visited);
		}
	}
}

void bfs(int v, int n, int adj[MAX][MAX], bool visited[MAX]) {
	queue <int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int u = q.front();
		nbfs[cnt1++] = u;
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && adj[u][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	inp();
	//bfs(1,n,adj,visited);
	dfs(1, n, adj, visited);
	cout << "-----DFS------- \n";
	for (int i = 0; i < cnt; i++) {
		cout << ndfs[i] << " ";
	}
	/*cout << "\n-----BFS------- \n";
	for (int i = 0; i < cnt1; i++) {
		cout << nbfs[i] << " ";
	}*/
	system("pause");
	return 1;
}
