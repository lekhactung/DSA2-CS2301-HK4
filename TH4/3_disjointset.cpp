#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v;
	int w;
};

const int maxn = 1001;
int n, m;
int parent[maxn], sz[maxn];
vector<edge> canh;

void make_set() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

void input() {
	ifstream ifs("data.txt");
	if (ifs.is_open()) {
		ifs >> n >> m;
		for (int i = 0; i < m; i++) {
			edge e;
			int x, y, z;
			ifs >> x >> y >> z;
			e.v = x; e.u = y; e.w = z;
			canh.push_back(e);
		}
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void kruskal() {
	vector<edge> mst;
	int d = 0;
	sort(canh.begin(), canh.end(), cmp);
	for (int i = 0; i<m; i++) {
		if (mst.size() == n - 1) {
			break;
		}
		edge e = canh[i];
		if (Union(e.u, e.v)) {
			mst.push_back(e);
			d += e.w;
		}
	}
	if (mst.size() != n - 1) {
		cout << "Khong ton tai cay khung! \n";
	}
	else {
		cout << "MST : " << d << endl;
		for (auto it : mst) {
			cout << it.u << " " << it.v << " " << it.w << endl;
		}
	}
}

int main() {
	input();
	make_set();
	kruskal();
	system("pause");
	return 1;
}