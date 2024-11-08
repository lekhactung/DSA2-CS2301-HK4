#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn = 1001;
int parent[maxn], sz[maxn];

struct edge{
    int v,u,w;
};

vector <edge> canh;

void inp(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        edge e;
        e.v = x ; e.u = y ; e.w = w;
        canh.push_back(e);
    }
}

void makeset(){
    for(int i=0;i<n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}

int cmp(edge a,edge b){
    return a.w < b.w;
}

bool Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = parent[a];
    sz[a] += sz[b];
    return true;
}

void kruskal(){
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(),canh.end(),cmp);
    for(int i=0;i<m;i++){
        if(mst.size()==n-1){
            break;
        }
        edge e = canh[i];
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d+=e.w;
        }
    }
    if(mst.size()!= n-1){
        cout << "Khong co cay lien thong! \n";
    } else{
        cout << "MST : " << d << "! \n";
        for(auto it:mst){
            cout << it.v << " " << it.u << " " << it.w << endl;
        }
    }
}

int main(){
    freopen("../data/minimumSpanningTreeData2.txt","r",stdin);
    inp();
    makeset();
    kruskal();
    return 1;
}