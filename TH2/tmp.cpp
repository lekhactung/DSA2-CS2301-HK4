#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20

char vertex[MAX];
int n;
int C[MAX],bfs[MAX],nbfs=0,a[MAX][MAX];

void output(int a[][MAX],int n);
void inputMatrix(int a[][MAX],int &n);
void initEdges();
void initQ();
int isEmpty();
void push(int x);
void pop(int &x);
void outputBFS();
void BFS(int s);

void main(){
    inputMatrix(a,n);
    output(a,n);
    BFS(0);
    outputBFS();
}

void inputMatrix(int a[][MAX],int &n){
    ifstream ifs("data2.txt");
    ifs >> n;
    for(int i = 0;i<n;i++){
        ifs >> vertex[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ifs >> a[i][j];
        }
    }
}

void output(int a[][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

struct node {
    int info;
    node *next;
};

node *front,*rear;

void initEdges(){
    for(int i=0;i<n;i++){
        C[i] = 1;
    }
}

void initQ() {
    front = rear = NULL;
}

int isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void push(int x){
    if(front == NULL){
        front = rear = createNode(x);
    } else{
        node *p = createNode(x);
        p->next = front;
        front = p;
    }
}

void pop(int &x){
    if(front != NULL ){
        
    }
    return;
}
void outputBFS();
void BFS(int s);