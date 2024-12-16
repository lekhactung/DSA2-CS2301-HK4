#include <iostream>
#include <fstream>
using namespace std;
#define MAX 10
#define INF 100000
int vertices_quantity , edges_quantity;
int matrix[MAX][MAX];
char name[]={'A','B','C','D','E','G','H','K'};

struct node{
    int info;
    node *next;
};

node *head,*tail;

void initQueue(){
    head = tail = NULL;
}

bool isEmptyQ(){
    return head == NULL;
}

void pushQ(int x){
    node *p = new node;
    if(p==NULL){
        return;
    }
    p->info = x;
    p->next = NULL;
    if(tail == NULL){
        head = p;
    }
    else {
        tail->next = p;
    }
    tail = p;
}

void popQ(int &x){
    if(head!=NULL){
        node *p = head;
        x = p->info;
        head = head->next;
        if(head ==NULL){
            tail = NULL;
        }
        delete p;
    }
}

void init(){
    vertices_quantity =0;
    edges_quantity =0;
    matrix[MAX][MAX] = {0};
    
}

void inp(){
    ifstream ifs("bt1_data.txt");
    if(ifs.is_open()){
        ifs >> edges_quantity;
        for(int i=1;i<=edges_quantity;i++){
            for(int j=1;j<=edges_quantity;j++){
                int x,y,z; ifs >> x >> y >> z;
                if(x > y && x > vertices_quantity){
                    vertices_quantity = x;
                } else if(y > x && y > vertices_quantity){
                    vertices_quantity = y;
                }
                matrix[x][y] = z;
                matrix[y][x] = z;
            }
        }

    } else{
        cout << "Khong the mo file! \n";
    }
    ifs.close();
}

void inp_matrix(){
    ifstream ifs("bt1_matrixdata.txt");
    if(ifs.is_open()){
        ifs >> vertices_quantity;
        for(int i=0;i<vertices_quantity;i++){
            for(int j=0;j<vertices_quantity;j++){
                ifs >> matrix[i][j];
            }
        }
        cout <<"Doc file thanh cong!\n";
    } else {
        cout << "Khong the mo file! \n";
    }
    ifs.close();
}

void exp_matrix(){
    ofstream ofs("bt1_matrixdata.txt");
    if(ofs.is_open()){
        ofs << vertices_quantity << endl;
        for(int i=1;i<=vertices_quantity;i++){
            for(int j=1;j<=vertices_quantity;j++){
                ofs << matrix[i][j] << " ";
            }
            ofs << endl;
        }
    } else{
        cout << "Khong mo duoc file! \n";
    }
    ofs.close();
}

void output_matrix(){
    int character =  65;
    cout << "  ";
    for(int i=0;i<vertices_quantity;i++){
        cout << name[i] << " ";
    }
    cout << endl;
    for(int i=0;i<vertices_quantity;i++){
        cout << name[i] << " ";
        for(int j=0;j<vertices_quantity;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
        }
}

int bfs[MAX], nbfs=0;
void BFS(int s){
    bool visited[MAX] = {false};
    initQueue();
    pushQ(s);
    visited[s] = true;
    cout << "Thu tu duyet BFS: ";
    while(!isEmptyQ()){
        int p;
        popQ(p);
        bfs[nbfs++] = p;
        cout << name[p] << " ";
        for(int i=0;i<vertices_quantity;i++){
            if(matrix[p][i]>0 && !visited[i]){
                visited[i] = true;
                pushQ(i);
            }
        }       
    }    
}

bool isUndirected (){
    for(int i=0;i<vertices_quantity;i++){
        for(int j=0;j<vertices_quantity;j++){
            if(matrix[i][j] != matrix[j][i])  return false;
        }
    }
    return true;
}

void printDegrees(){
    for(int i=0;i<vertices_quantity;i++){
        int degree =0;
        for(int j=0;j<vertices_quantity;j++){
            if(matrix[i][j]!=0) degree++;
        }
        cout << "Bac cua dinh " << name[i] << " la : " << degree << endl; 
    }
}

void primMST() {
    int parent[MAX];
    int key[MAX];
    fill(key, key + MAX, INF);
    bool inMST[MAX] = {false};
    key[0] = 0;
    parent[0] = -1;
    for(int count =0;count <vertices_quantity-1;count++){
         int minKey = INF, u;
        for(int v=0;v<vertices_quantity;v++){
            if(!inMST[v] && key[v] < minKey){
                minKey=key[v];
                u=v;
            }
        }
    inMST[u] = true;
    for (int v = 0; v < vertices_quantity; v++) {
            if (matrix[u][v] && !inMST[v] && matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = matrix[u][v];
            }
        }
    }
    cout << "Cay khung nho nhat (Prim):\n";
    for (int i = 1; i < vertices_quantity; i++) {
        cout << name[parent[i]] << " - " << name[i] << " : " << matrix[i][parent[i]] << endl;
    }
}


void menu(){
    cout  << "1. Doc du lieu tu file\n"
        <<"2. Xuat ma tran \n"
        <<"3. Duyet dinh bang DFS \n"
        <<"4. Kiem tra do thi vo huong hay co huong \n"
        <<"5. So bac cua moi dinh trong do thi \n"
        <<"6. Tim so dinh va liet ke cac dinh tu x-> y dua tren DFS \n"
        <<"7. Tim cay khung nho nhat bang thuat giai Prim \n"
        <<"8. Tim cay khung nho nhat bang thuat giai Kruskal co dien \n"
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
        case 1: init(); inp_matrix(); break;
        case 2: output_matrix(); break;
        case 3: BFS(0); break;
        case 4: cout << ((isUndirected())? "Do thi da cho la do thi vo huong\n" : "Do thi da cho la do thi co huong\n"); break;
        case 5: printDegrees(); break;
        case 6: break;
        case 7: primMST();break;
        case 8: break;
        case 0: cout << "Thoat chuong trinh!\n"; break;
        default:  cout <<"Lua chon khong hop le!\n";
        }
        system("pause");
        system("cls");
    } while(choice!=0);
}

int main(){
    run();
    
    return 1;
}