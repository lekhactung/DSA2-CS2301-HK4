#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort connections by cost
bool compareConnections(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

vector<int> parent, rankk;

int findParent(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionNodes(int node1, int node2)
{
    int parent1 = findParent(node1);
    int parent2 = findParent(node2);

    if (parent1 != parent2) {
        if (rankk[parent1] > rankk[parent2]) {
            parent[parent2] = parent1;
        }
        else if (rankk[parent1] == rankk[parent2]) {
            parent[parent2] = parent1;
            rankk[parent1]+= 1;
        }
        else {
            parent[parent1] = parent2;
            rankk[parent2]
                += rankk[parent1]; 
        }

        return true; 
    }

    return false;
}

int calculateMinimumCost(int n,vector<vector<int> >& connections)
{

    sort(connections.begin(), connections.end(),
         compareConnections);
    parent.resize(n + 2);
    rankk.resize(n + 2, 1);
    for (int i = 0; i < n + 2; i++)
        parent[i] = i;

    int totalCost = 0, components = n;

    for (auto connection : connections) {

        if (unionNodes(connection[0], connection[1])) {
            totalCost+= connection[2]; 
            components--;
        }
    }

    if (components > 1)
        return -1;

    return totalCost; 
}

int main()
{
    int n = 3;
    vector<vector<int> > connections
        = { { 1, 2, 5 }, { 1, 3, 6 }, { 2, 3, 1 } };

    int minCost = calculateMinimumCost(n, connections);

    cout << "The minimum cost is: " << minCost << endl;

    return 0;
}
