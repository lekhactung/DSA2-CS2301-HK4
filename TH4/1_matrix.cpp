//kruskal

#include <iostream>
#include <fstream>
using namespace std;
# define max 100
int a[max][max];
int n; 
int E1[max], E2[max],wE[max],nE = 0; 
int T1[max], T2[max], wT[max], nT = 0; 
			
bool TonTai(int d, int D[], int nD) {
	for (int i = 0; i < nD; i++) {
		if (D[i] == d) {
			return true;
		}
	}
	return false;
}

void kruskal()
{
		for (int i = 0; i<nE; i++)
		{
			if (TonTai(E1[i], T1, nT) && TonTai(E2[i], T2, nT))
				continue;
			if (TonTai(E1[i], T2, nT) && TonTai(E2[i], T1, nT))
				continue;
			T1[nT] = E1[i];
			T2[nT] = E2[i];
			wT[nT] = wE[i];
			nT++;
			if (nT == n - 1) {
				break;
			}
		}
	
}
void taoE()
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				nE++;
			}
}
void SapXepE()
{
	for (int i = 0; i<nE - 1; i++)
		for (int j = i + 1; j<nE; j++)
			if (wE[i]>wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}
void output()
{
	int tong = 0;
	for (int i = 0; i<nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}cout << "\n Tong = " << tong << endl;
}
void inp() {
	ifstream ifs("matrixdata.txt");
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
}


int main() {
	inp();
	taoE();
	SapXepE();
	kruskal();
	output();

	// system("pause");	
	return 1;
}