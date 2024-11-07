#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
    int w;
};

const int maxn = 1001;
int n,m;
int parent[maxn],sz[maxn];
vector<edge> canh;

void make_set(){
    for(int i=0;i<n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union (int a,int b){
    a = find(a);
    b = find(b);
    if( a==b ) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void kruskal(){
    vector <edge> mst;
}

int main(){
    freopen("../data/minimumSpanningTreeData.txt","r",stdin);

    return 1;
}