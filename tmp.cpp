#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100
int a[MAX][MAX]; // Adjacency matrix
int n; // Number of vertices

	   // Arrays to store the edges
vector<int> E1, E2, wE;

// Arrays to store the edges in the MST
vector<int> T1, T2, wT;

// Function to check if an element exists in the given array
bool TonTai(int d, const vector<int>& D) {
	for (int i = 0; i < D.size(); i++) {
		if (D[i] == d) {
			return true;
		}
	}
	return false;
}

// Kruskal's algorithm to find the MST
void kruskal() {
	for (int i = 0; i < E1.size(); i++) {
		if (TonTai(E1[i], T1) && TonTai(E2[i], T2))
			continue;
		if (TonTai(E1[i], T2) && TonTai(E2[i], T1))
			continue;

		T1.push_back(E1[i]);
		T2.push_back(E2[i]);
		wT.push_back(wE[i]);

		if (T1.size() == n - 1) {
			break;
		}
	}
}

// Function to extract the edges from the adjacency matrix
void taoE() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {  // Avoid duplicate edges (since graph is undirected)
			if (a[i][j] != 0) {
				E1.push_back(i);
				E2.push_back(j);
				wE.push_back(a[i][j]);
			}
		}
	}
}

// Function to sort the edges based on their weights
void SapXepE() {
	for (int i = 0; i < E1.size() - 1; i++) {
		for (int j = i + 1; j < E1.size(); j++) {
			if (wE[i] > wE[j]) {
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
		}
	}
}

// Output the MST and its total weight
void output() {
	int totalWeight = 0;
	for (int i = 0; i < T1.size(); i++) {
		cout << "(" << T1[i] << ", " << T2[i] << ") = " << wT[i] << endl;
		totalWeight += wT[i];
	}
	cout << "Total Weight = " << totalWeight << endl;
}

// Function to read the graph data from a file
void inp() {
	ifstream ifs("matrixdata.txt");
	if (ifs.is_open()) {
		ifs >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ifs >> a[i][j];
			}
		}
	}
	else {
		cout << "Could not open the file!\n";
	}
}

int main() {
	inp();  // Read input from file
	taoE(); // Create edge list
	SapXepE(); // Sort edges by weight
	kruskal(); // Run Kruskal's algorithm to find MST
	output(); // Output the MST and total weight
	system("pause");
	return 0;
}
