#include <bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1001] = {false};
vector<int> adj[1001];

void inp(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y; cin >> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}


bool dfs(int u,int par){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            if(dfs(v,u)) return true;
        }
        else if(v != par){
            return true; 
        }
    }   
    return false; 
}

int main(){
    freopen("../data/undirectedGraphData4.txt","r",stdin);
    inp();
    if(dfs(1,0)){
        cout << "YES";
    } else{
        cout << "NO";
    }

    return 0;
}