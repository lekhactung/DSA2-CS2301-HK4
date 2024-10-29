#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001] = { false };

void inp() {
	ifstream ifs("data1.txt");
	ifs >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; ifs >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int u) {
	cout << u << " ";
	visited[u] = true;
	for (auto x : adj[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

void bfs(int u) {
	queue <int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (auto x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main() {
	//freopen("data1.txt", "r", stdin);
	inp();
	bfs(1);

	system("pause");

	return 1;
}