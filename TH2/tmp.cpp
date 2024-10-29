//DFS =  DEPTH FIRST SEARCH
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector <int> ans;
void dfs(int v,bool visited[],int adj[MAX][MAX],int n){
    visited[v] = true;
    ans.push_back(v);
    for(int i=1;i<=n;i++){
        if(!visited[i] && adj[v][i]==1){
            dfs(i,visited,adj,n);
        }
    }
}

int main(){
    ifstream ifs("data3.txt");
    if(ifs.is_open()){
        int n,e;
        ifs >> n >> e;
        bool visited[n] = {false};
        int adj[MAX][MAX] = {0};
        for(int i=0;i<e;i++){
            int u,v;
            ifs >> u >> v;
            adj[u][v] = adj[v][u] =1;
        }
        dfs(1,visited,adj,n);
        ofstream ofs("output.txt",ios::app);
        if(ofs.is_open()){
            // for(int i=1;i<=n;i++){
            //     for(int j = 1 ;j <= n ;j++){
            //         ofs << adj[i][j] << " ";
            //     }
            //     ofs << endl;
            // }    
            ofs <<  "------DFS-------\n";
            for(int i=0;i<ans.size();i++){
                ofs << ans[i] << " ";
            }
            ofs << endl;
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