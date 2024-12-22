#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 100
#define INF 10000000

int n , m;
int matrix[MAX][MAX];
char name[]={'A','B','C','D','E','F','G','H','I'};
struct edge {
    int u,v,w;
};

void inpList(){
    ifstream ifs("bt2data.txt");
    if(!ifs.is_open()){
        return;
    }
    ifs >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int x,y,w; ifs >> x >> y >> w;
            matrix[x][y] = w;
            matrix[y][x] = w;  
        }
    }
}

void output_matrix(){
    cout << "  ";
    for(int i=0;i<n;i++){
        cout  <<name[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << name[i] << " ";
        for(int j =0 ; j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void output_list(){
    for(int i=0;i<n;i++){
        for(int j= i;j<n;j++){
            if(matrix[i][j]!=0 ){
                cout << i << " " << j << " " << matrix[i][j] << endl;
            }
        }
    }
}

void initVisited(bool visited[]){
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
}

void DFS(int u){
    bool visited[MAX];
    initVisited(visited);
    stack <int> s;
    s.push(u);
    while(!s.empty()){
        int tmp = s.top(); s.pop();
        cout << name[tmp] << " ";
        for(int i=0;i<n;i++){
            if(matrix[tmp][i]!= 0 && !visited[i]){
                s.push(i);
                break;
            }
        }
    }
}

bool visited[MAX] = {false};
void DFS_recursion(int u){
    if(!visited[u]){
        visited[u] = true;
        cout << name[u] << " ";
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS_recursion(i);
            }
        }
    }
}

void printDegree(){
    for(int i=0;i<n;i++){
        int degree = 0;
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                degree++;
            }
        }
        cout << name[i] << " : " << degree << endl;
    }
}

void DFS_xy(int x, int y){
    bool visited[MAX];
    initVisited(visited);
    stack <int> s;
    s.push(x);
    while(!s.empty()){
        int tmp = s.top(); s.pop();
        visited[tmp] = true;
        cout << name[tmp] << " ";
        for(int i = 0 ;i < n;i++){
            if(matrix[tmp][i] != 0 && !visited[i]){
                s.push(i);
                break;
            }
        }
        if(tmp==y){
            break;
        }
    }
}

void primMST(){
    int parent[MAX], key[MAX];
    fill(key,key+MAX,INF);
    bool inMST[MAX] ={ false};
    parent[0] = -1;
    key[0] = 0;
    for(int i=0;i<n;i++){
        int minkey = INF,u;
        for(int j=0;j<n;j++){
            if(!inMST[j] && key[j] < minkey){
                minkey = key[j];
                u = j;
            }
        }
        inMST[u] = true;
        for(int j=0;j<n;j++){
            if(matrix[u][j]!=0 && !inMST[j] && matrix[u][j] < key[j]){
                parent[j] = u;
                key[j] = matrix[u][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << name[parent[i]] << " --> " << name[i] << " : " << matrix[parent[i]][i] << endl;
    }
}

bool cmp(edge a,edge b){
    return a.w > b.w;
}

void swap(edge &a , edge &b){
    edge tmp = a;
    a = b;
    b = tmp;
}

edge edges[MAX];
int parent[MAX];
int findParent(int u){
    if(parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
}

void kruskal(){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(matrix[i][j]!=0){
                edge tmp; tmp.u = i; tmp.v = j; tmp.w = matrix[i][j];
                edges[count++] = tmp;
            }
        }
    }
    for(int i=0;i<count-1;i++){
        for(int j = i +1;j< count;j++){
            if(cmp(edges[i],edges[j])){
                swap(edges[i],edges[j]);
            }
        }
    }
    // for(int i=0;i<count;i++){
    //     cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << endl;
    // }
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int totalW = 0;
    for(edge e : edges){
        int uRoot = findParent(e.u);
        int vRoot = findParent(e.v);
        if(uRoot != vRoot ){
            cout << name[e.u] << " - " << name[e.v] << " : " << e.w <<endl;
            totalW += e.w;
            parent[uRoot] = vRoot;
        }
    }
    cout << "Tong trong so la : " << totalW;
}

struct node{
    int info;
    node *next;
};

node *head,*tail;
void initQ(){
    head = tail = NULL;
}

bool isEmpty(){
    return head == NULL;
}

void pushQ(int x){
    node *p = new node;
    if(p==NULL){
        return;
    }
    p->info = x;
    p->next = NULL;
    if(tail==NULL){
        head == p;
    }
    else{
        tail->next = p;
    }
    tail = p;
}

void popQ(int &x){
    if(head!=NULL){
        node *p = head;
        x = p->info;
        head = head->next;
        if(head==NULL){
            tail = NULL;
        }
        delete p;
    }
}

int bfs[MAX],nbfs=0;
void BFS(int s){
    bool visited[MAX] = {false};
    initQ();
    pushQ(s);
    visited[s] = true;
    cout << "Thu tu duye BFS : " ;
    while(!isEmpty()){
        int p;
        popQ(p);
        bfs[nbfs]
    }
}

void menu(){
    cout << "1. Input \n" 
        <<"2. Xuat danh sach trong so \n"
        <<"3. DFS khong dung de quy \n"
        <<"4. DFS dung de quy \n"
        <<"5. So bac cua moi dinh trong do thi \n"
        <<"6.  \n"
        <<"7. Prim algorithym  \n"
        <<"8. Kruskal algorithym  \n"
        <<"0. Thoat chuong trinh! \n"
        <<"Chon chuong trinh : ";

}


void test(){
    inpList();
    // output_list();
    // DFS(0);
    // DFS_recursion(0);
    // printDegree();
    // DFS_xy(0,5);
    // primMST();
    // kruskal();
}

int main(){
    test();

    return 1;
}