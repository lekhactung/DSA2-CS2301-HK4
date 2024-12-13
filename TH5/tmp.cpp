#include <iostream>
using namespace std;

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        // Dịch chuyển các phần tử lớn hơn key về phía sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm thực hiện thuật toán Bucket Sort
void bucketSort(float arr[], int n) {
    // Số lượng bucket (giả định chia thành 10 bucket)
    const int BUCKET_COUNT = 10;
    float buckets[BUCKET_COUNT][n]; // Mảng 2 chiều cho các bucket
    int bucketSizes[BUCKET_COUNT] = {0}; // Mảng theo dõi kích thước mỗi bucket

    // Bước 1: Phân loại phần tử vào các bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * BUCKET_COUNT; // Chỉ số bucket
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Bước 2: Sắp xếp các phần tử trong từng bucket
    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Bước 3: Gộp các bucket lại
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Hàm hiển thị mảng
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Ví dụ mảng đầu vào
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    // Gọi hàm bucketSort
    bucketSort(arr, n);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
