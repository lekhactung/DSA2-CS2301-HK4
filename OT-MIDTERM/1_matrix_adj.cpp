#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
int n;

void init(){
    n = 0;
}

void inp(){
    ifstream ifs("../data/matrix.txt");
    if(ifs.is_open()){
        ifs >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ifs >> adj[i][j];
            }
        }
    } else {
        cout << "Khong mo duoc file! \n";
    }
    ifs.close();
}



int main(){
    init();

    return 1;
}