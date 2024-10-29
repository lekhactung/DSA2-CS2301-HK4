#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX]; 
int n; 
int C[100];
// 1 là chưa xét; 0 là đã xét
int dfs[100];
int ndfs=0; 

void init()
{
    n=0;
}
void input()
{
    ifstream ifs("data4.txt");
    // cout<<"nhap so dinh do thi n: ";
    ifs>>n;
    for(int i=0;i<n;i++)
    {
        // cout<<"nhap vao dong thu "<<i+1<<": ";
        for(int j=0;j<n;j++)
            ifs >>A[i][j];
    }
}
//Xuất Ma Trận
void output()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
// Hàm khởi tạo đỉnh chưa xét = 1
void khoitaochuaxet()
{
    for(int i =0; i<n; i++) // n là số đỉnh của đồ thị C[i]=1;
    {
        C[i] = 1;
    }
}
// Thuật giải DFS sử dụng STACK
struct stack{
    int a[1000];
    int top;
};

void init(stack &s) {
	s.top = -1;
}

void push(stack &s, const int x) {
	if (s.top < MAX) {
		s.a[++s.top] = x;
	}
}

bool isEmpty(stack s) {
	return s.top == -1;
}

int pop(stack &s) {
	if (!isEmpty(s)) {
		return s.a[s.top--];
	}
    
}

void DFS(int x)
{
    stack s;
    init(s);
    push(s,x);
    dfs[ndfs++]=x;
    C[x]=0;
    int v=-1, u = x;
    while(!isEmpty(s))
    {
        if(v==n){
            pop(s);
        }
        for(v=0;v<n;v++) {
            if(A[u][v]!=0 && C[v]==1){
                // push(s,x);
                push(s,v);
                dfs[ndfs++]=v;
                C[v] = 0;
                u = v ;
                break;
            }
        }
    }
}

void output_DFS()
{
    for(int i=0;i<ndfs;i++)
        cout<<dfs[i]<<" ";
}

int main()
{
    init();
    input();
    output();
    khoitaochuaxet();
    DFS(0);
    cout << ndfs << endl;
    output_DFS();
    return 1;
}