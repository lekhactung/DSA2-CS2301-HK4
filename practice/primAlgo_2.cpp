#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int n,m;

vector<pair<int,int>> adj[maxn];
bool used[maxn] = {false};

struct canh{
    int x,y,w;
};

void inp(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,w; cin >> x >> y >>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}


void prim(int u ){
    vector<canh> mst;
    int d = 0;
    used[u] = true; 
    while(mst.size() < n-1){
        int minw = INT_MAX;
        int X,Y; // luu 2 dinh cua canh e;
        for(int i=0;i<n;i++){
            if(used[i]==true){
                for(pair<int,int> it : adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!used[j] && trongso < minw){
                        minw = trongso;
                        X=j; Y=i; 
                    }
                }
            }
        }
        mst.push_back({X,Y,minw});
        d+= minw;
        used[X] = true; 

    }
    cout << d << endl;
    for(auto it:mst){
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}

int main(){
    freopen("../TH3/data3.txt","r",stdin);
    inp();
    prim(0);

    return 1;
}