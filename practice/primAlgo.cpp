#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int a[MAX][MAX];
int n;
int E1[MAX],E2[MAX],wE[MAX],nE=0;
int T1[MAX],T2[MAX],wT[MAX],nT=0;

bool exist(int d,int D[],int nD){
    for(int i=0;i<nD;i++){
        if(d==D[i]){
            return true;
        }
    }
    return false;
}

void xoaViTriE(int i){
    for(int j=i;j<nE;j++){
        E1[j] = E1[j+1];
        E2[j] = E2[j+1];
        wE[j] = wE[j+1];

    }
    nE--;
}

void xoaCanhE(int u,int v){
    for(int i=0;i<nE;i++){
        if(E1[i] == u && E2[i]==v){
            xoaViTriE(i);
            break;
        }
    }
}

void inp(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
}

void prim(int s){
    int u = s, min, i, d1, d2;
    while(nT < n-1){
        for(int v=0;v<n;v++){
            if(a[u][v] != 0){
                if(!exist(v,T2,nT)){
                    E1[nE] = u; 
                    E2[nE] = v;
                    wE[nE] = a[u][v];
                    nE++;
                }
            }
        }
        for(i = 0 ;i<nE ; i++){
            if(!exist(E2[i],T2,nT)){
                min = wE[i];
                d1 = E1[i];
                d2 = E2[i];
                break;
            }
        }
        for(;i<nE; i++){
            if(!exist(E2[i],T2,nT)){
                if(wE[i] < min ){
                    min = wE[i];
                    d1 = E1[i];
                    d2 = E2[i];
                }
            }
        }
        T1[nT] = d1;
        T2[nT] = d2;
        wT[nT] = a[d1][d2];
        a[d1][d2] = 0;
        a[d2][d1] = 0;
        nT++;
        xoaCanhE(d1,d2);
        u = d2;
    }
}

void outp(){
    int tong = 0;
	for (int i = 0; i<nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong = " << tong << endl;
}
int main(){
    freopen("../TH3/data2.txt","r",stdin);
    inp();
    prim(0);
    outp();
    return 1;
}