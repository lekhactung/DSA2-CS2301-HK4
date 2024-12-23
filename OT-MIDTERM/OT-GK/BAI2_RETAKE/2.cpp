#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 100
#define INF 10000000
char name[]={'A','B','C','D','E','F','G','H','I'};
int n,m;
int matrix[MAX][MAX];

void inp(){
    ifstream ifs("bt2data.txt");
    if(!ifs.is_open()){
        cout << "Khong mo duoc file!";return;
    } 
    ifs >> n >> m ;
    for(int i=0;i<m;i++){
        int x,y,z; ifs >> x >> y >> z;
        matrix[x][y] = matrix[y][x] = z;
    }
}

void outputMatrix(){
    cout << "  ";
    for(int i=0;i<n;i++){
        cout << name[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << name[i] << " ";
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void outputList(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(matrix[i][j]!=0 ){
                cout << i << " - " << j << " : " << matrix[i][j] << endl; 
            }
        }
    }
}

void printDegree(){
    for(int i=0;i<n;i++){
        int degree = 0;
        for(int j=i+1;j<n;j++){
            if(matrix[i][j]!=0 ){
                degree++;
            }
        }
        cout << "so canh cua canh " <<name[i] << " : " << degree << endl;
    }
}
void initVisited(bool visited[]){
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
}

void DFS(int u){
    stack <int> s;
    s.push(u);
    bool visited[MAX];
    initVisited(visited);
    while(!s.empty()){
        int p = s.top();s.pop();
        cout << name[p] << " ";
        visited[p] = true;
        for(int i=0;i<n;i++){
            if(matrix[p][i]!=0 && !visited[i]){
                s.push(i);
                break;
            }
        }
    }
}

bool visited[MAX];
void DFS_recursion(int u){
    if(!visited[u]){
        cout << name[u] << " ";
        visited[u] = true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS_recursion(i);
            }   
        }
    }
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

void push(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    if(head==NULL){
        head = p;
    } else{
        tail->next = p;
    }
    tail = p;
}

void pop(int &x){
    if(head!=NULL){
        node *p = head;
        x = p->info;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        }
        delete p;
    }
}

int bfs[MAX], nbfs=0;
void BFS(int s){
    initQ();
    push(s);
    bool visited[MAX] ={false};
    visited[s] = true;
    while(!isEmpty()){
        int p; pop(p);
        cout << name[p] << " ";
        visited[p] = true;
        for(int i=0;i<n;i++){
            if(matrix[p][i] && !visited[i]){
                visited[i] = true;
                push(i);
            }
        }
    }
}

void primMST(){
    int parent[MAX],key[MAX];
    bool inMST[MAX] = {false};
    fill(key,key+MAX,INF);
    parent[0] = -1;
    key[0] = 0;
        int count=0;
    for(int i=0;i<n;i++){
        int minkey = INF, u;
        for(int j=0;j<n;j++){
            if(!inMST[j] && key[j]<minkey){
                minkey = key[j];
                u =j;
            }
        }
        inMST[u] = true;
        for(int j =0;j<n;j++){
            if(matrix[u][j] && !inMST[j] && matrix[u][j] < key[j]){
                parent[j] = u ;
                key[j] = matrix[u][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << name[parent[i]] << " - " << name[i] << " : " << matrix[parent[i]][i]<<endl;
        count+=matrix[parent[i]][i];
    }
    cout << count;
}

struct edge{
    int v,u,w;
};
bool cmp(edge a,edge b){
    return a.w > b.w;
}
void swap(edge &a, edge &b){
    edge tmp = a;
    a = b;
    b = tmp;
}

edge edges[MAX];
int parent[MAX];
int findParent(int u){
    if(parent[u] == u ) return u;
    return parent[u] = findParent(parent[u]);
}

void kruskal(){
    int count;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++){
            if(matrix[i][j]!=0){
                edge tmp; tmp.u = i; tmp.v = j; tmp.w = matrix[i][j];
                edges[count++] = tmp;
            }
        }
    }  
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(cmp(edges[i],edges[j])){
                swap(edges[i], edges[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int totalW = 0;
    for(edge e : edges){
        int uRoot = findParent(e.u);
        int vRoot = findParent(e.v);
        if(uRoot!=vRoot){
            cout << name[e.u] << " - " << name[e.v] << " : " << e.w << endl;
            totalW += e.w;
            parent[uRoot] = vRoot;
        }
    }
    cout << totalW;
}


void test(){
    system("cls");
    inp();
    // outputMatrix();
    // outputList();
    // printDegree();
    // DFS(0);
    // DFS_recursion(0);
    // BFS(0);
    // primMST();
    kruskal();
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
void run(){
    int choice;
    do{
        do{
            system("cls");
            menu();
            cin >> choice;
            if(choice<0  || choice >8){
                cout << "Chuong trinh khong hop le, vui long nhap lai!\n";
            system("pause");
            }

        } while(choice<0  || choice >8);
        switch (choice)
        {
            case 1:
                inp();
                break;
            case 2:
                outputList();
                break;
            case 3:
                int c; cout <<"Nhap dinh bat dau duyet : " ; cin >> c;
                DFS(c);
                break;
            case 5:
                printDegree();
                break;
            case 4:
                int u; cout <<"Nhap dinh bat dau duyet : " ; cin >> u;
                DFS_recursion(u);
                break;
            case 6:

                break;
            case 7:
                primMST();
                break;
            case 8:
                kruskal();
                break;
            case 0: 
                cout <<"Thoat chuong trinh! \n";

        default:
            break;
        }
        system("pause");
        
    } while(choice != 0);
    
}
int main(){
    test();
    // run();
    return 1;
}