//SINH TỔ HỢP

#include <iostream>

using namespace std;

// Hàm quay lui để sinh các tổ hợp (tập con)
void generateSubsets(int subset[], int subsetSize, int nums[], int n, int index) {
    if (index == n) {
        // In ra một tập hợp con
        cout << "{ ";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    // Không chọn phần tử tại vị trí index
    generateSubsets(subset, subsetSize, nums, n, index + 1);

    // Chọn phần tử tại vị trí index
    subset[subsetSize] = nums[index];
    generateSubsets(subset, subsetSize + 1, nums, n, index + 1);
}

int main() {
    int n;
    cout << "Nhap so luong phan tu trong tap hop: ";
    cin >> n;

    int nums[n];
    cout << "Nhap cac phan tu trong tap hop: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int subset[n]; // Mảng tạm lưu tập hợp con hiện tại
    cout << "Tat ca cac tap hop con la:\n";
    generateSubsets(subset, 0, nums, n, 0);

    return 0;
}

