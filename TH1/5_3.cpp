#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;  // Kích thước tối đa cho ma trận kề

// Hàm nhập đồ thị vô hướng có trọng số
void nhapDoThiVoHuong(int graph[MAX][MAX], int soDinh) {
    int u, v, w;
    cout << "Nhap canh theo dinh u v va trong so w (nhap -1 de dung):" << endl;
    while (true) {
        cin >> u;
        if (u == -1) break;
        cin >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Vì là đồ thị vô hướng
    }
}

// Hàm nhập đồ thị có hướng có trọng số
void nhapDoThiCoHuong(int graph[MAX][MAX], int soDinh) {
    int u, v, w;
    cout << "Nhap canh theo dinh u v va trong so w (nhap -1 de dung):" << endl;
    while (true) {
        cin >> u;
        if (u == -1) break;
        cin >> v >> w;
        graph[u][v] = w; // Vì là đồ thị có hướng
    }
}

// Hàm đọc đồ thị từ file text
void docDoThiTuFile(int graph[MAX][MAX], int soDinh, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        int u, v, w;
        while (file >> u >> v >> w) {
            graph[u][v] = w;
            graph[v][u] = w; // Đọc đồ thị vô hướng
        }
        file.close();
        cout << "Doc file thanh cong!" << endl;
    } else {
        cout << "Khong mo duoc file!" << endl;
    }
}

// Hàm xuất đồ thị ra màn hình
void xuatDoThi(int graph[MAX][MAX], int soDinh) {
    for (int i = 0; i < soDinh; ++i) {
        for (int j = 0; j < soDinh; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int soDinh;
    int graph[MAX][MAX] = {0};  // Ma trận kề khởi tạo bằng 0

    cout << "Nhap so dinh cua do thi: ";
    cin >> soDinh;

    // Chọn đồ thị để nhập
    int luaChon;
    cout << "1. Do thi vo huong\n2. Do thi co huong\nChon loai do thi: ";
    cin >> luaChon;

    if (luaChon == 1) {
        nhapDoThiVoHuong(graph, soDinh);
    } else if (luaChon == 2) {
        nhapDoThiCoHuong(graph, soDinh);
    } else {
        cout << "Lua chon khong hop le!" << endl;
        return 1;
    }

    // Xuất đồ thị ra màn hình
    cout << "Do thi da nhap la:" << endl;
    xuatDoThi(graph, soDinh);

    // Đọc đồ thị từ file (tùy chọn)
    string tenFile;
    cout << "Nhap ten file de doc (hoac nhap 'none' de bo qua): ";
    cin >> tenFile;
    if (tenFile != "none") {
        docDoThiTuFile(graph, soDinh, tenFile);
        cout << "Do thi sau khi doc tu file la:" << endl;
        xuatDoThi(graph, soDinh);
    }

    return 0;
}
