#include <bits/stdc++.h>
using namespace std;
#define MAX 100

vector <int> ans;

void dfs(int v,bool visited[],int adj[MAX][MAX],int n){
    visited[v] = true;
    ans.push_back(v);
    for(int i=1;i<=n;i++){
        if(adj[v][i]==1 && !visited[i]){
            dfs(i,visited,adj,n);
        }
    }
}

int main(){
    ifstream ifs("../data/dfsdata.txt");
    if(ifs.is_open()){
        int n,e;
        ifs >> n >> e;
        int adj[MAX][MAX]={0};
        for(int i=0;i<e;i++){
            int u,v;
            ifs >> u >> v;
            adj[u][v] = adj[v][u] = 1;
        }
        bool visited[MAX]={false};
        dfs(1,visited,adj,n);
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        ifs.close();
    } else{
        cout << "Khong mo duoc file! \n";
    }

    return 1;
}