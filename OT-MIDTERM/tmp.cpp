#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 50
#define INF 9999999

using namespace std;

int n; // So dinh cua do thi
int adjMatrix[MAX][MAX]; // Ma tran ke trong so

// 1. Tao file Input.txt
void createInputFile() {
    
    ofstream outFile("Input.txt");
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    outFile << n << endl;

    cout << "Nhap ma tran ke trong so (0 neu khong co canh):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
            outFile << adjMatrix[i][j] << " ";
        }
        outFile << endl;
    }
    outFile.close();
    cout << "File Input.txt da duoc tao thanh cong!\n";
}

// 2. Doc file Input.txt
void readInputFile() {
    ifstream inFile("bt1_matrixdata.txt");
    if (!inFile) {
        cout << "Khong mo duoc file Input.txt\n";
        return;
    }
    inFile >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> adjMatrix[i][j];
        }
    }
    inFile.close();
    cout << "Doc file thanh cong!\n";
}

// 3. Xuat ma tran ke
void printMatrix() {
    cout << "Ma tran ke trong so:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

char name[]={'A','B','C','D','E','G','H','K'};
// 4. Duyet BFS
void BFS(int start) {
    bool visited[MAX] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "Thu tu duyet BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << name[u] << " ";
        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// 5. Kiem tra do thi vo huong hay co huong
bool isUndirected() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) return false;
        }
    }
    return true;
}

// 6. Tinh bac cua cac dinh
void printDegrees() {
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] > 0) degree++;
        }
        cout << "Bac cua dinh " << (char)(i + 'a') << " la: " << degree << endl;
    }
}

// 8. Tim cay khung nho nhat bang Prim
void primMST() {
    int parent[MAX];
    int key[MAX];
    bool inMST[MAX];

    fill(key, key + MAX, INF);
    memset(inMST, false, sizeof(inMST));

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int minKey = INF, u;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    cout << "Cay khung nho nhat (Prim):\n";
    for (int i = 1; i < n; i++) {
        cout << name[parent[i]] << " - " << name[i] << " : " << adjMatrix[i][parent[i]] << endl;
    }
}

// 9. Tim cay khung nho nhat bang Kruskal
struct Edge {
    int u, v, weight;
};

bool compareEdge(Edge a, Edge b) { return a.weight < b.weight; }

int parent[MAX];
int findParent(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
}

void kruskalMST() {
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] > 0) {
                edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }
    for(int i=0;i<edges.size();i++){
        cout << edges[i].u << " " << edges[i].v << " " << edges[i].weight << endl;
    }
    sort(edges.begin(), edges.end(), compareEdge);
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Cay khung nho nhat (Kruskal):\n";
    int totalWeight = 0;
    for (Edge e : edges) {
        int uRoot = findParent(e.u);
        int vRoot = findParent(e.v);
        if (uRoot != vRoot) {
            cout << (char)(e.u + 'a') << " - " << (char)(e.v + 'a') << " : " << e.weight << endl;
            totalWeight += e.weight;
            parent[uRoot] = vRoot;
        }
    }
    cout << "Tong trong so: " << totalWeight << endl;
}

// Main function
int main() {
    int choice;
    do {
        cout << "\nMenu lua chon:\n";
        cout << "1. Tao file Input.txt\n";
        cout << "2. Doc file Input.txt\n";
        cout << "3. Xuat ma tran ke\n";
        cout << "4. Duyet BFS\n";
        cout << "5. Kiem tra do thi vo huong\n";
        cout << "6. Tinh bac cua cac dinh\n";
        cout << "7. Tim cay khung Prim\n";
        cout << "8. Tim cay khung Kruskal\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: createInputFile(); break;
            case 2: readInputFile(); break;
            case 3: printMatrix(); break;
            case 4: BFS(0); break;
            case 5: cout << (isUndirected() ? "Do thi vo huong\n" : "Do thi co huong\n"); break;
            case 6: printDegrees(); break;
            case 7: primMST(); break;
            case 8: kruskalMST(); break;
            case 0: cout << "Thoat chuong trinh!\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
        system("pause");
    } while (choice != 0);

    return 0;
}
