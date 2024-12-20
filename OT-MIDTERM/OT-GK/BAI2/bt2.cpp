#include <iostream>
#include <fstream>
using namespace std;


#define MAX 100
#define INF 1000000
int n,m;
int matrix[MAX][MAX];
char name[]={'A','B','C','D','E','F','G','H','I'};


void inp(){
    ifstream ifs("bt2_data.txt");
    if(ifs.is_open()){
        ifs >> n >> m;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int x,y,w; ifs >> x >> y >> w;
                matrix[x][y] = w;
                matrix[y][x] = w;
            }
        }
    }    
}


void output_list(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(matrix[i][j] > 0){
                cout << name[i] << " " << name[j] << " " << matrix[i][j] << endl;
            }
        }
    }
}

void output_matrix(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    inp();
    output_list();

    return 1;
}

