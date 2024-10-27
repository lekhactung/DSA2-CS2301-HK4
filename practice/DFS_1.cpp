#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001] = {false};

void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for(auto x:adj[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}


int main(){
    freopen("../data/data3.txt","r",stdin);
    input();
    dfs(1);
    return 1;
}