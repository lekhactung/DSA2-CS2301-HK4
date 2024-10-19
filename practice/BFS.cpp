// BFS = BREADTH FIRST SEARCH
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
vector <int> ans;
void bfs(int v, int n, bool visited[MAX], int adj[MAX][MAX]) {
    queue <int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for(int i = 1 ; i <= n ; i++){
            if(adj[u][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


int main(){
    ifstream ifs("../data/data.txt");
    if(ifs.is_open()){
        int adj[MAX][MAX] = {0};
        bool visited[MAX] = {false};  
        int n,e;
        ifs >> n >> e;
        for(int i=0;i<e;i++){
            int u,v;
            ifs >> u >> v;
            adj[u][v] = adj[v][u] = 1;
        }
        bfs(1,n,visited,adj);
        ofstream ofs("../data/output.txt");
        if(ofs.is_open()){
            // for(int i=1;i<=n;i++){
            //     for(int j = 1 ;j <= n ;j++){
            //         ofs << adj[i][j] << " ";
            //     }
            //     ofs << endl;
            // }    
            ofs <<  "------BFS-------\n";
            for(int i=0;i<ans.size();i++){
                ofs << ans[i] << " ";
            }
            ofs << endl << endl;
            ofs.close();
        } else {
            cout << "Khong ghi duoc file! \n";
        }
        ifs.close();
    } else{
        cout << "Khong mo duoc file! \n";
    }

    return 1;
}