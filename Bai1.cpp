//SINH CÁC DÃY NHỊ PHÂN

#include <iostream>

using namespace std;

// Hàm quay lui để sinh các dãy nhị phân
void generateBinary(int n, int sequence[], int index) {
    if (index == n) {
        // In ra một dãy nhị phân
        for (int i = 0; i < n; i++) {
            cout << sequence[i];
        }
        cout << endl;
        return;
    }

    // Gán giá trị 0 vào vị trí hiện tại
    sequence[index] = 0;
    generateBinary(n, sequence, index + 1);

    // Gán giá trị 1 vào vị trí hiện tại
    sequence[index] = 1;
    generateBinary(n, sequence, index + 1);
}

int main() {
    int n;
    cout << "Nhap do dai n cua day nhi phan: ";
    cin >> n;

    int sequence[n]; // Dãy nhị phân (mảng tĩnh)
    cout << "Tat ca cac day nhi phan do dai " << n << ":\n";
    generateBinary(n, sequence, 0);

    return 0;
}
