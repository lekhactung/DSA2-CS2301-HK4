#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20

char vertex[MAX];
int n,nbfs=0;
int C[MAX],bfs[MAX],a[MAX][MAX];

void output(int a[][MAX],int n);
void inputMatrix(int a[][MAX],int &n);
void initEdges();
void initQ();
int isEmpty();
void push(int x);
void pop(int &x);
void outputBFS();
void BFS(int s);

int main(){
    inputMatrix(a,n);
    output(a,n);
    BFS(0);
    // outputBFS();
    int character = 65;
	cout << "RESULT : ";
	for (int i = 0; i < nbfs; i++) {
		cout << char(bfs[i]+character) << " ";
	}
    return 1;
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
    cout << "  ";
    for(int i=0;i<n;i++){
        cout << vertex[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << vertex[i] << " ";
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

void push(int x){
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

void pop(int &x){
   if (front != NULL) {
		node *p = front;
		x = p->info;
		front = front->next;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
	}
}

void BFS(int s){
    initEdges();
	initQ();
	push(s);
	C[s] = 0;
	while (!isEmpty() ){
		int p;
		pop(p);
		bfs[nbfs++] = p;
		for (int i = 0; i < n; i++) {
			if (C[i] == 1 && a[p][i] == 1) {
				push(i);
				C[i] = 0;
			}
		}
	}
}

void outputBFS(){
    int character = 65;
	cout << "RESULT : ";
	for (int i = 0; i < nbfs; i++) {
		cout << char(bfs[i]+character) << " ";
	}
}