#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 100
char vertex[MAX];
int C[MAX], bfs[MAX],a[MAX][MAX];
int n, nbfs = 0;

struct node{
    int info;
    node *next;
};

node *front, *rear;

void initQ(){
    front = rear = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

bool isEmpty(){
    if(front ==NULL){
        return true;
    } 
    return false;
}

void pushQ(int x){
    node *p = new node;
	if (p == NULL) {
		return;
	}
	p->info = x;
	p->next = NULL;
	if (rear == NULL) {
		front = p;
	}
	else {
		rear->next = p;
	}
	rear = p;
}

void popQ(int &x){
    if(front !=NULL){
        node *p = front;
        x = p->info;
        front = front->next;
        if(front==NULL){
            rear = NULL;
        }
        delete p;
    }
}

void inp(){
    ifstream ifs("bfs_matrix_data.txt");
    if(ifs.is_open()){
        ifs >> n;
        for(int i=0;i<n;i++){
            ifs >> vertex[i];
        }
        for(int i =0 ;i< n;i++){
            for(int j=0;j<n;j++){
                ifs >> a[i][j];
            }
        }
    } else{
        cout << "Khong mo duoc file! \n";
    }
    ifs.close();
}

void output(int a[][MAX],int n){
    cout << " ";
    for(int i=0 ;i<n;i++){
        cout << " " << vertex[i];
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout<< vertex[i];
        for(int j=0;j<n;j++){
            cout << " " << a[i][j] << " ";
        }
        cout << endl;
    }
}

void initE(){
    for(int i=0;i<n;i++){
        C[i] = 1;
    }
}

void BFS(int s){
    initE();
    initQ();
    pushQ(s);
    while(!isEmpty()){
        int p;
        popQ(p);
        bfs[nbfs++] = p;
        for(int i=0;i<n;i++){
            if(C[i]==1 && a[p][i] == 1){
                pushQ(i);
                C[i] = 0;
            }
        }
    }
}

void outputBFS(){
    int character = 65;
    cout << "RESULT : " ;
    for(int i=0;i<nbfs;i++){
        cout << char(bfs[i]+character) << " ";
    }
}

int main(){
    initE();
    initQ();
    inp();
    BFS(0);
    outputBFS();
    return 1;
}