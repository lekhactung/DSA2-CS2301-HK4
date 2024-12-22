int parent[MAX],key[MAX];
    fill(key,key+MAX,INF);
    bool inMST[MAX] = {false};
    key[0] = 0;
    parent[0] = -1;
    for(int i=0;i<n;i++){
        int minKey = INF,u;
        for(int j=0;j<n;j++){
            if(!inMST[j] && key[j] < minKey){
                minKey = key[j];
                u = j;
            }
        }
        inMST[u] =true;
        for(int j=0;j<n;j++){
            if(matrix[u][j]!=0 && !inMST[j] && matrix[u][j] < key[j]){
                parent[j] = u;
                key[j] = matrix[u][j];
            }
        } 
    }
        cout << "Cay khung nho nhat (Prim):\n";
    int total = 0;
    for (int i = 1; i < n; i++) {
        cout << name[parent[i]] << " - " << name[i] << " : " << matrix[i][parent[i]] << endl;
        total += key[i];
    }
    cout << total ;