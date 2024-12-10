//duyet do thi bang kruskal
#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 20;
int a[MAX][MAX];
int n;
char vertex[MAX];
//tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

struct Edge {
	int dinhBatDau;
	int dinhKetThuc;
	int trongSo;
};

void inputFromFile()
{
	ifstream inF;
	inF.open("matrantrongso1.txt");
	if(inF.is_open())
	{
		inF >> n;
		for(int i = 0; i < n; i++)
			inF >> vertex[i];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				inF >> a[i][j];
		inF.close();
		cout << "Doc file thanh cong\n";
	}
	else
		cout << "Doc file khong thanh cong\n";
}
void outputMatrix()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
//tao tap E: danh sach tat ca cac canh cua do thi kem trong so
void taoE()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}
void xuatE()
{
	for(int i = 0; i < nE; i++)
		cout << "Canh (" << vertex[E1[i]] << "," 
		<< vertex[E2[i]] << "," << wE[i] << ")\n";
}
void hoanDoi(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
void sapXepE()
{
	for(int i = 0; i < nE - 1; i++)
		for(int j = i + 1; j < nE; j++)
			if(wE[i] > wE[j])
			{
				hoanDoi(E1[i], E1[j]);
				hoanDoi(E2[i], E2[j]);
				hoanDoi(wE[i], wE[j]);
			}
}
bool kiemTraTonTai(int T[], int nT, int e)
{
	for(int i = 0; i < nT; i++)
		if(e == T[i])
			return true;
	return false;
}

int findRoot(int parent[], int dinh)
{
	while (parent[dinh] != dinh)
	{
		dinh = parent[dinh];
	}
	return dinh;
}

void kruskal()
{
	int parent[MAX];

	for (int i = 0; i < n; i++)
	{
		parent[i] = i; // moi dinh thuoc 1 cay khac nhau
	}
	for(int i = 0; i < nE; i++)
	{
		// Duyet canh
		int dinhBatDau = E1[i];
		int dinhKetThuc = E2[i];

		int root_dinhBatDau = findRoot(parent, dinhBatDau);
		int root_dinhKetThuc = findRoot(parent, dinhKetThuc);

		cout << "Duyet canh (" << vertex[E1[i]] << "," << vertex[E2[i]] <<")" << endl;

		/*if(kiemTraTonTai(T1, nT, E1[i]) ==  true && kiemTraTonTai(T2, nT, E2[i]) == true)
			continue;

		if(kiemTraTonTai(T1, nT, E2[i]) == true && kiemTraTonTai(T2, nT, E1[i]) == true)
			continue;*/

		
		// Kiem tra co tao chu trinh ?
		if (root_dinhBatDau != root_dinhKetThuc)
		{
			T1[nT] = E1[i];
			T2[nT] = E2[i];
			wT[nT] = wE[i];
			nT++;

			parent[root_dinhKetThuc] = root_dinhBatDau;
		}

		
		// Them canh vao cay T
		
		/*T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;*/
		
		if(nT == n - 1) break; //cay khung toi tieu da du so dinh
	}
}

void kruskal_new()
{
	int nhan[MAX];

	for (int i = 0; i < n; i++)
	{
		nhan[i] = i; // moi dinh thuoc 1 cay khac nhau
	}

	for (int i = 0; i < nE; i++) // duyet cac canh cua do thi
	{
		// Kiem tra canh da co chu trinh hay chua?
		if (nhan[E1[i]] != nhan[E2[i]] && nhan[E2[i]] != nhan[E1[i]])
		{
			// Them
			T1[nT] = E1[i];
			T2[nT] = E2[i];
			wT[nT] = wE[i];
			nT++;

			int gt = nhan[E2[i]];
			for(int k = 0; k<n; k++)
			{
				if(nhan[k]==gt)
					nhan[k]= nhan[E1[i]];
			}
		}
		if (nT == n - 1) break; //cay khung toi tieu da du so dinh
	}
}
void xuatCKTT()
{
	int sum_wT = 0;
	cout << "Cay khung toi tieu gom cac canh: ";
	for(int i = 0; i < nT; i++)
	{
		cout << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << "," << wT[i] << ")\n";
		sum_wT += wT[i];
	}
	cout << "Tong trong so: " << sum_wT << endl;
}
int main()
{
	Edge DanhSachCanh[40];

	inputFromFile();
	outputMatrix();
	taoE();
	xuatE();
	sapXepE();
	cout << "Sau khi sap xep: " << endl;
	xuatE();
	kruskal();
	xuatCKTT();

	system("pause");

}