#include <bits/stdc++.h>
using namespace std;
int n, m; // n la so dinh, m la so canh
int a[1001][1001];  

int main(){
    ifstream ifs("../data/adjListToMatrixdata.txt");
    if(ifs.is_open()){ 
        ifs >> n;
        ifs.ignore();
        for(int i=1;i<=n;i++){
            string s,num;
            getline(ifs,s);
            stringstream ss(s);
            while(ss>>num){
                a[i][stoi(num)] = 1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << a[i][j] << " ";
            } 
            cout << endl;
        }
        ifs.close();
    } else{
        cout <<"Khong mo duoc file! \n";
    }

    return 1;
}