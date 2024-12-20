#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
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

void printDegree(){
    for(int i=0;i<n;i++){
        int degree = 0;
        for(int j=0;j<n;j++){
            if(matrix[i][j]>0 ){
                degree++;
            }
        }
        cout << "So bac cua dinh " << name[i] << " la " << degree << endl;
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

// struct stack{
//     int a[MAX] , top;
// };

// void initStack(stack &s){
//     s.top = -1;
// }

// void push(stack &s,int x){
//     s.a[++s.top] = x;
// }

// int pop(stack &s){
//     return s.a[s.top--];
// }

// bool isEmpty(stack s){
//     return s.top == -1;
// }

int visited[MAX] = {false};
void DFS(int x){
    stack <int> s;
    // initStack(s);
    s.push(x);
    // visited[x] = true;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(!visited[node]){
            cout << name[node] << " ";
            visited[node] = true;
            for (int i = 0; i < n; i++){
				if (matrix[node][i] == 1 && !visited[i]) {
					s.push(i);
					break;
				}
			}
        } 
    }
}

void DFS_recursion(int s){
    if(!visited[s]){
        visited[s] = true;
        cout << name[s] << " ";
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS_recursion(i);
            }
        }
    }
}

int main(){
    inp();
    // output_list();
    // printDegree();
    DFS(0);
    // DFS_recursion(0);

    return 1;
}

