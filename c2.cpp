#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
int n;
struct node {
	int info;
	node *next;
};

node *heads[MAX];

void init() {
	for (int i = 0; i < n; i++) {
		heads[i] = NULL;
	}
} 

node *createNode(int x) {
	node *p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

void insertFirst(node *&head,int x) {
		node *p = createNode(x);
		p->next = head;
		head = p;
}

void input() {
	int d, x, m;
	cout << "Nhap so dinh cua do thi n : "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap dinh thu " << i + 1 << ": ";
		cin >> d;
		insertFirst(heads[i], d);
		cout << "Nhap vao so dinh ke cua " << d << ": ";
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			insertFirst(heads[i], x);
		}
	}
}

void output_list(node *head) {
	if (head != NULL) {
		while (head != NULL) {
			cout << head->info << " ";
			head = head->next;
		}
	}
}

void output() {
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			cout << "Danh sach thu " << i + 1 << ": ";
			output_list(heads[i]);
		}
	}
	else {
		cout << "Danh sach rong! \n";
	}
}
int main() {
	init();
	input();
	output();
	cout << endl;
	system("pause");
	return 1;
}