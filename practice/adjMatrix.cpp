#include <iostream>
#include <fstream>

using namespace std;
int n, m; // n la so dinh, m la so canh
int a[1001][1001];

int main(){
    // cin >> n >> m;
    // for(int i=0;i<m;i++){
    //     int x,y; cin >> x >> y;
    //     a[x][y] = a[y][x] = 1;
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << a[i][j] << " ";
    //     } 
    //     cout << endl;
    // }

    ifstream ifs("../data/adjMatrix_data.txt");
    if(ifs.is_open()){
        ifs >> n >> m;
        for(int i = 0;i<m;i++){
            int x,y; ifs >> x >> y;
            a[x][y] = a[y][x] = 1;
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