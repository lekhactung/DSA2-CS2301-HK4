#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

//Khai Báo Cấu Trúc Ma Trận Kề
#define MAX 20
#define M 15
int A[MAX][MAX]; // mảng hai chiều
int n; // số đỉnh của đồ thị
int C[100]; // lưu trữ đỉnh chưa xét;
			// 1 là chưa xét; 0 là đã xét
int dfs[100];// lưu danh sách phần tử đã duyệt
int ndfs = 0; // chỉ số lưu đỉnh đã xét
			  //Khởi Tạo Mảng Rỗng
struct Node {
	int value;
	Node* next;
};
void init(Node* heads[]) {
	for (int i = 0; i < MAX; i++) {
		heads[i] = NULL;
	}
}
Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}
void addLast(Node*& head, int value) {
	if (head == NULL) {
		head = createNode(value);
	}
	else {
		Node* p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = createNode(value);
	}
}
void readFile(Node* heads[], string fileName) {
	ifstream myFile(fileName);
	if (myFile.is_open()) {
		myFile >> n;
		int edges;
		myFile >> edges;
		for (int i = 0; i < edges; i++) {
			int x, y;
			myFile >> x >> y;
			addLast(heads[x], y);
			addLast(heads[y], x);
		}
		myFile.close();
	}
}
struct Stack {
	int a[M];
	int top;
};
void init(Stack& s) {
	s.top = -1;
}
void push(Stack& s, int x) {
	s.a[++s.top] = x;
}

int pop(Stack& s) {
	return s.a[s.top--];
}
bool isEmpty(Stack s) {
	return s.top == -1;
}
void init()
{
	n = 0;
}
void init(int a[][MAX], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
}
void convertToMatrix(int a[][MAX], Node* heads[]) {
	init(a, n);
	for (int i = 0; i < n; i++) {
		if (heads[i] != NULL) {
			Node* p = heads[i];
			while (p != NULL) {
				a[i][p->value] = 1;
				p = p->next;
			}
		}
	}
}
//Nhập Ma Trận
void input()
{
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j<n; j++)
			cin >> A[i][j];
	}
}
//Xuất Ma Trận
void output()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
// Hàm khởi tạo đỉnh chưa xét = 1
void khoitaochuaxet()
{
	for (int i = 0; i<n; i++) // n là số đỉnh của đồ thị
		C[i] = 1;
}
// Thuật giải DFS sử dụng STACK
//========================================BUG================================
void DFS(int s) //s là đỉnh bắt đầu
{
	Stack st;
	init(st);
	push(st, s);
	dfs[ndfs++] = s;
	//ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmpty(st))
	{
		if (v == n)
			u = pop(st);
		for (v = 0; v<n; v++)
			if (A[u][v] == 1 && C[v] == 1)
			{
				push(st, u);
				push(st, v);
				dfs[ndfs++] = v;
				//ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
//========================================BUG================================
//========================================BUG================================
void dFs(int u) {
	khoitaochuaxet();
	stack<int> s;
	s.push(u);
	while (!s.empty()) {
		int temp = s.top(); s.pop();
		if (C[temp] == 1) {
			cout << temp << " ";
			C[temp] = 0;
			for (int i = 0; i < n; i++) {
				if (A[temp][i] == 1 && C[i] == 1) {
					s.push(i);
					break;
				}
			}
		}
	}
}
//========================================BUG================================
//========================================FIX BUG BANG DE QUY========================
void dfsRecursion(int u) {
	if (C[u] == 1) {
		C[u] = 0;
		cout << u << " ";
		for (int i = 0; i < n; i++) {
			if (C[i] == 1)
				dfsRecursion(i);
		}
	}
}
//========================================FIX BUG BANG DE QUY========================
// Hàm xuất DFS
void output_DFS()
{
	for (int i = 0; i<ndfs; i++)
		cout << dfs[i] << " ";
}
int main()
{
	Node* heads[MAX];
	init(heads);
	init();
	readFile(heads, "input.txt");
	convertToMatrix(A, heads);
	output();
	// khoitaochuaxet();
	// DFS(0);
	// output_DFS();
	// cout << endl;
	dFs(0);
	cout << endl;
	khoitaochuaxet();
	dfsRecursion(0);
	system("pause");
	return 0;
}