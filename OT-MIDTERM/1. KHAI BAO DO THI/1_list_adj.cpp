#include <iostream>
#include <fstream>

using namespace std;
#define MAX 100
int n,m;
struct  node
{
    int info;
    node *next; 
};

node *heads[MAX];

void init(){
    for(int i=0;i<n;i++){
        heads[i] = NULL;
    }
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirst(node *&head,int x){
    node *p = createNode(x);
    p->next = head;
    head = p;
}

void inp(){
    ifstream ifs("1_list_adj_data.txt");
    if(ifs.is_open()){
        int d,x,m;
        ifs >> n;
        for(int i=0;i<n;i++){
            ifs >> d;
            insertFirst(heads[i],d);
            ifs >> m;
            for(int j=0;j<m;j++){
                ifs >> x;
                insertFirst(heads[i],x);
            }
        }
    } else{
        cout << "Khong mo duoc file! \n" ;
    }
    ifs.close();
}

void output_list(node *head) {
	if (head != NULL) {
		while (head != NULL) {
			cout << head->info << " ";
			head = head->next;
		}
	}
}

void output() {
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			cout << "Danh sach thu " << i + 1 << ": ";
			output_list(heads[i]);
			cout << endl;
		}
	}
	else {
		cout << "Danh sach rong! \n";
	}
}

int main(){
    inp();
    output();

    return 1;
}