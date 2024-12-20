#include <iostream>
#include <fstream>
// #include <vector>
#include <stack>
using namespace std;
#define MAX 100
#define INF 1000000
int n,m;
int matrix[MAX][MAX];
char name[]={'A','B','C','D','E','F','G','H','I'};

void inp(){
    ifstream ifs("bt2_data.txt");
    if(ifs.is_open()){
        ifs >> n >> m;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int x,y,w; ifs >> x >> y >> w;
                matrix[x][y] = w;
                matrix[y][x] = w;
            }
        }
    }    
}

void printDegree(){
    for(int i=0;i<n;i++){
        int degree = 0;
        for(int j=0;j<n;j++){
            if(matrix[i][j]>0 ){
                degree++;
            }
        }
        cout << "So bac cua dinh " << name[i] << " la " << degree << endl;
    }
}

void output_list(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(matrix[i][j] > 0){
                cout << name[i] << " " << name[j] << " " << matrix[i][j] << endl;
            }
        }
    }
}

void output_matrix(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// struct stack{
//     int a[MAX] , top;
// };

// void initStack(stack &s){
//     s.top = -1;
// }

// void push(stack &s,int x){
//     s.a[++s.top] = x;
// }

// int pop(stack &s){
//     return s.a[s.top--];
// }

// bool isEmpty(stack s){
//     return s.top == -1;
// }

int visited[MAX];

void initVisited(){
    for(int i =0;i<n;i++){
        visited[i] = false;
    }
}

void DFS(int x){
    initVisited();
	stack<int> s;
	s.push(x);
	while (!s.empty()) {
		int temp = s.top(); s.pop();
		if (!visited[temp]) {
			cout << name[temp] << " ";
			visited[temp] = true;
			for (int i = 0; i < n; i++) {
				if (matrix[temp][i] > 0 && !visited[i]) {
					s.push(i);
					break;
				}
			}
		}
	}
}

void DFS_recursion(int s){
    if(!visited[s]){
        visited[s] = true;
        cout << name[s] << " ";
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS_recursion(i);
            }
        }
    }
}

void menu(){
    cout << "1. Input \n" 
        <<"2. Xuat danh sach trong so \n"
        <<"3. DFS khong dung de quy \n"
        <<"4. DFS dung de quy \n"
        <<"5. So bac cua moi dinh trong do thi \n"
        <<"6.  \n"
        <<"7. Prim algorithym  \n"
        <<"8. Kruskal algorithym  \n"
        <<"0. Thoat chuong trinh! \n"
        <<"Chon chuong trinh : ";

}

void run(){
    int choice;
    do{
        menu();
        do{
            cin >> choice;
            if(choice>8||choice<0){
                cout <<"Lua chon khong hop le, vui long chon lai!\n";
            }
        } while(choice >8 || choice <0);
        switch (choice)
        {
        case 1: inp(); break;
        case 2: output_list(); break;
        case 3: initVisited();DFS_recursion(0); break;
        case 4: DFS(0);break;
        case 5: printDegree(); break;
        case 6: break;
        case 7: break;
        case 8:  break;
        case 0: cout << "Thoat chuong trinh!\n"; break;
        default:  cout <<"Lua chon khong hop le!\n";
        }
        system("pause");
        system("cls");
    } while(choice!=0);
}

void test(){
    inp();
    DFS(0);
}

int main(){
    run();
    // test();
    return 1;
}

