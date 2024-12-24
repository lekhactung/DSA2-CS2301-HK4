#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;
#define MAX 100
#define INF 10000000
char name[] ={'A','B','C','D','E','F','G','H','I'};
int n;
int matrix[MAX][MAX];
void inp(){
    ifstream ifs("data.txt");
    if(!ifs.is_open()){
        return;
    }
    ifs >> n;
    int m[MAX];
    for(int i=0;i<n;i++){
        ifs >> m[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m[i];j++){
            int x,y,w; ifs >> x >>y >>w;
            matrix[x][y] = matrix[y][x] = w;
        }
    }
    cout << "Nhap du lieu thanh cong!\n";
    ifs.close();
}

void output(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void outputlist(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(matrix[i][j]) 
                cout << name[i] << " - " << name[j] << " : " << matrix[i][j] << endl;
        }
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
        visited[p] = true;
        cout << name[p] << " ";
        for(int i=0;i<n;i++){
            if(!visited[i]){
                s.push(i);
                break;
            }
        }
    }
}

bool visited[MAX] = {false};
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

void BFS(int u){
    queue <int> q;
    q.push(u);
    bool visited[MAX] = {false};
    visited[u] = true;
    while(!q.empty()){
        int p = q.front();q.pop();
        visited[p] = true;
        cout << name[p] << " ";
        for(int i=0;i<n;i++){
            if(matrix[p][i]!=0 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void prim(){
    int parent[MAX], key[MAX];
    fill(key,key+MAX,INF);
    bool inMST[MAX] = {false};
    parent[0] = -1;
    key[0] = 0;
    for(int i=0;i<n;i++){
        int minkey = INF,u ;
        for(int j =0 ; j< n; j++){
            if(!inMST[j] && key[j] < minkey){
                minkey = key[j];
                u=j;
            }
        }
        inMST[u] = true;
        for(int j=0;j<n;j++){
            if(matrix[u][j] && !inMST[j] && matrix[u][j] < key[j])
            {
                parent[j] = u ;
                key[j] = matrix[u][j];
            }
        }
    }
    int totalW = 0;
    for(int i=1;i<n;i++){
        cout << name[parent[i]] << " - " << name[i] << " : " << matrix[parent[i]][i] << endl;
        totalW += matrix[parent[i]][i];
    }
    cout << "Tong trong so : " << totalW;

}

void primMax(){
    int parent[MAX], key[MAX];
    fill(key,key+MAX,-INF);
    bool inMST[MAX] = {false};
    parent[0] = -1;
    key[0] = 0;
    for(int i=0;i<n;i++){
        int maxkey = -INF,u ;
        for(int j =0 ; j< n; j++){
            if(!inMST[j] && key[j] > maxkey){
                maxkey = key[j];
                u=j;
            }
        }
        inMST[u] = true;
        for(int j=0;j<n;j++){
            if(matrix[u][j] && !inMST[j] && matrix[u][j] > key[j])
            {
                parent[j] = u ;
                key[j] = matrix[u][j];
            }
        }
    }
    int totalW = 0;
    for(int i=1;i<n;i++){
        cout << name[parent[i]] << " - " << name[i] << " : " << matrix[parent[i]][i] << endl;
        totalW += matrix[parent[i]][i];
    }
    cout << "Tong trong so : " << totalW;

}

struct edge {
    int u,v,w;
};

edge edges[MAX];

bool cmp(edge a,edge b){
    return a.w > b.w;
}

void swap(edge &a,edge &b){
    edge tmp = a;
    a = b;
    b =tmp;

}

int parent[MAX];
int findParent(int u){
    if(parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
}

void kruskal(){
    int count =0;
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(matrix[i][j]){
                edge tmp; tmp.u = i;tmp.v = j; tmp.w = matrix[i][j];
                edges[count++] = tmp;
            }
        }
    }
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(cmp(edges[i],edges[j])){
                swap(edges[i],edges[j]);
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
    cout << "Tong trong so : " << totalW << endl;
}

void kruskalMax(){
    int count =0;
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(matrix[i][j]){
                edge tmp; tmp.u = i;tmp.v = j; tmp.w = matrix[i][j];
                edges[count++] = tmp;
            }
        }
    }
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(!cmp(edges[i],edges[j])){
                swap(edges[i],edges[j]);
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
    cout << "Tong trong so : " << totalW << endl;
}


void test(){
    system("cls");
    inp();
    // outputlist();
    // DFS(0);
    // BFS(0);
    // prim();
    // primMax();
    // kruskal();
    kruskalMax();
}
void menu(){
    cout << "1. Input \n" 
        <<"2. Xuat danh sach trong so \n"
        <<"3. DFS khong dung de quy \n"
        <<"4. DFS dung de quy \n"
        <<"5. So bac cua moi dinh trong do thi \n"
        <<"6. Kiem tra do thi co huong hay vo huong \n"
        <<"7. Tim duong di tu dinh x -> y bang BFS \n"
        <<"8. Tim duong di tu dinh x -> y bang DFS \n"
        <<"9. Prim algorithym  \n"
        <<"10. Kruskal algorithym  \n"
        <<"0. Thoat chuong trinh! \n"
        <<"Chon chuong trinh : ";

}

void run(){
    int choice,u ;
    do{
        menu();
        do{
            cin >> choice;
            if(choice  < 0 || choice > 10){
                cout <<"Lua chon khong hop le, vui long chon lai! \n";
            }
        } while(choice < 0 || choice > 10);
        switch (choice)
        {
        case 1:
            inp();
            break;
        case 2:
            outputlist();
            break;
        case 3:
            cout << "Nhap dinh bat dau: " ; cin >> u;
            DFS(u);
            break;
        case 4: 
            initVisited(visited);
            cout << "Nhap dinh bat dau: " ; cin >> u;
            DFS_recursion(u);
        case 5: 
            break;
        case 6: 
            break;
        case 9:
            prim();
            break;
        case 10:
            kruskal();
            break;
        default:
            break;
        }
        system("pause");
    } while(choice!=0);
}
int main(){
    test();
    // run();

    return 1;
}