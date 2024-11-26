//kruskal

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
# define max 100
struct edge {
	int v, u, w;
};
int n,m;
edge canh[max];
vector<edge> mst;

void inp() {
	ifstream ifs("data.txt");
	if (ifs.is_open()) {
		ifs >> n >> m;
		for (int i = 0; i < m; i++) {
			edge e;
			int x, y, z;
			ifs >> x >> y >> z;
			e.v = x; e.u = y; e.w = z;
			canh[i] = e;
		}
	}
	else {
		cout << "Khong mo duoc file! \n";
	}
}

bool TonTai(edge a, edge b) {
	for (int i = 0; i < m; i++) {
		if (a.v == b.u) {
			return true;
		}
	}
	return false;
}

void swap(edge &a, edge &b) {
	edge c = a;
	a = b;
	b = c;
}

//void SapXepCanh()
//{
//	for (int i = 0; i < m ; i++)
//	{
//		for (int j = i+1; j < m; j++) {
//			if (canh[i].w > canh[j].w) {
//				swap(canh[i], canh[j]);	
//			}
//		}
//	}
//}

void kruskal()
{
	for (int i = 0; i<m; i++)
	{
		edge e = canh[i];

		if (mst.size() == n - 1);
			break;
	}
}

void output()
{
	int tong = 0;
	for (int i = 0; i<n-1; i++)
	{
		cout << endl << "(" << mst[i].v << "," << mst[i].u << ") = " << mst[i].w;
		tong += mst[i].w;
	}cout << "\n Tong = " << tong;
}


int main() {
	inp();
	SapXepCanh();
	for (int i = 0; i < mst.size(); i++) {
		cout << canh[i].v << " " << canh[i].u << " " << canh[i].w << endl;
	}

	system("pause");
	return 1;
}