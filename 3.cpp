#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#define MAX 20
char vertex[MAX];
int a[MAX][MAX]; // mảng hai chiều
int n; // số đỉnh của đồ thị
int C[100]; // lưu trữ đỉnh chưa xét;
			// 1 là chưa xét; 0 là đã xét
int bfs[100];// lưu danh sách phần tử đã duyệt
int nbfs = 0; // chỉ số lưu đỉnh đã xét

struct node {
	int info;
	node *link;
};

void inputMatrix(int a[][MAX], int &n) {
	/*do {
		cout << "Nhap so luong dinh cua do thi : ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	cout << "Nhap ten cua " << n << " dinh: ";
	for (int i = 0; i < n; i++) {
		cin >> vertex[i];
	}
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tinh dinh " << i << " : ";
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}*/

	ifstream ifs("data2.txt");
		ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >>  vertex[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ifs >> a[i][j];
		}
	}

}

void output(int a[][MAX], int n) {
	cout << " ";
	for (int i = 0; i < n; i++) {
		cout << " " << vertex[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vertex[i];
		for (int j = 0; j < n; j++) {
			cout << " " << a[i][j];
		}
		cout << endl;
	}
}

void initEdges() {
	for (int i = 0; i < n; i++) {
		C[i] = 1;
	}
}


node *front, *rear;
void initQueue() {
	front = rear = NULL;
}

int isEmptyQueue() {
	if (front == NULL) {
		return 1;
	}
	return 0;
}

void pushQueue(int &x) {
	node *p = new node;
	if (p == NULL) {
		return;
	}
	p->info = x;
	p->link = NULL;
	if (rear == NULL) {
		front = p;
	}
	else {
		rear->link = p;
	}
	rear = p;
}

void popQueue(int &x){
	if (front != NULL) {
		node *p = front;
		x = p->info;
		front = front->link;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
	}
}


void BFS(int s) {
	initEdges();
	initQueue();
	pushQueue(s);
	C[s] = 0;
	while (!isEmptyQueue() ){
		int p;
		popQueue(p);
		bfs[nbfs++] = p;
		for (int i = 0; i < n; i++) {
			if (C[i] == 1 && a[p][i] == 1) {
				pushQueue(i);
				C[i] = 0;
			}
		}
	}
}

void outputBFS() {
	for (int i = 0; i < nbfs; i++) {
		cout << bfs[i] << " ";
	}
}

int main() {
	inputMatrix(a,n);
	output(a,n);
	BFS(1);
	outputBFS();
	system("pause");
	return 1;
}