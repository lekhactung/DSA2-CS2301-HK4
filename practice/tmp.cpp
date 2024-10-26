#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector <int> ans;

void bfs(int v,int n,bool visited[],int adj[MAX][MAX]){
    queue <int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int i=1;i<=n;i++){
            if(!visited[i] && adj[u][i] == 1 ){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    freopen("../data/data.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;cin >> n >> m;
    bool visited[MAX] = {false};
    int adj[MAX][MAX] = {0};
    // cout << n << m;
    for(int i =1;i<=m;i++){
        int v,e;
        cin >> v >> e;
        adj[v][e] = adj[e][v] = 1;
    }
    bfs(1,n,visited,adj);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 1;
}