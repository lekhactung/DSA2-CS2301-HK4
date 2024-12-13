#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
#define MAX 10
#define INF 1e9
int vertices_quantity , edges_quantity;
int matrix[MAX][MAX];
char name[8]={'A','B','C','D','E','G','H','K'};

struct node{
    int info;
    node *next;
};

node *head,*tail;

void initQueue(){
    head = tail = NULL;
}

bool isEmpty(){
    if(head == NULL){
        return true;
    }
    return false;
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
            tail ==NULL;
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
        for(int i=1;i<=vertices_quantity;i++){
            for(int j=1;j<=vertices_quantity;j++){
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
    for(int i=1;i<=vertices_quantity;i++){
        cout << name[i-1] << " ";
        for(int j=1;j<=vertices_quantity;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
        }
}

void BFS(int s){
    
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
        case 1:
            inp_matrix();
            break;
        case 2:
            output_matrix();
            break;
        case 3:
         
            break;
        case 4:
         
            break;
        case 5:
         
            break;
        case 6:
         
            break;
        case 7:
         
            break;
        case 8:
         
            break;
        case 0:
            cout << "Cam on da su dung chuong trinh!\n";
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
    } while(choice!=0);
}

int main(){
    init();
    run();
    return 1;
}