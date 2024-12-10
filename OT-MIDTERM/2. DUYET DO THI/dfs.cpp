#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int a[MAX][MAX], c[MAX], dfs[MAX] ;
int n, ndfs = 0;

void init(){
    n = 0;
}

void inp(){
    ifstream ifs("dfs_matrix_data.txt");
    ifs >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ifs >> a[i][j];
        }
    }
    ifs.close();
}

void output(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void khoitaochuaxet(){
    for(int i=0; i<n; i++){
        c[i] = 0;
    }
}

struct stack{
    int a[1000];
    int top;
};

void initStack(stack &s){
    s.top = -1;
}

void push(stack &s,const int x){
    if(s.top<MAX ){
        s.a[++s.top] = x;
    }
}

bool isEmpty(stack s){
    return s.top == -1;
}

int pop(stack &s){
    if(!isEmpty(s)){
        return s.a[s.top--];
    }
}

void DFS(int x){
    stack s;
    initStack(s);
    push(s,x);
    dfs[ndfs++] = x;
    c[x] = 0;
    int v=-1 , u =x;
    while(!isEmpty(s)){
        
    }
}

int main(){


    return 1;
}