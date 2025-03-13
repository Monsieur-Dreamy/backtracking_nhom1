//XẾP HẬU

#include <iostream>

using namespace std;

const int MAX = 20; // Giới hạn kích thước tối đa của bàn cờ

// Hàm kiểm tra xem có thể đặt hậu ở vị trí (row, col) không
bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    // Kiểm tra cột bên trên
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Kiểm tra đường chéo trên bên trái
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Kiểm tra đường chéo trên bên phải
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Hàm quay lui để giải bài toán N-Queens
bool solveNQueens(int board[MAX][MAX], int row, int n) {
    // Nếu đã đặt đủ N hậu, in ra và kết thúc
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return true; // Đặt `false` nếu muốn tìm tất cả các lời giải
    }

    bool foundSolution = false;

    // Duyệt qua các cột trên hàng hiện tại
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Đặt hậu vào vị trí (row, col)
            board[row][col] = 1;

            // Gọi đệ quy để đặt hậu ở hàng tiếp theo
            foundSolution |= solveNQueens(board, row + 1, n);

            // Quay lui: Bỏ hậu khỏi vị trí (row, col)
            board[row][col] = 0;
        }
    }

    return foundSolution;
}

int main() {
    int n;
    cout << "Nhap so luong quan hau (N): ";
    cin >> n;

    if (n > MAX) {
        cout << "Gia tri N vuot qua gioi han toi da (" << MAX << ")!" << endl;
        return 0;
    }

    int board[MAX][MAX] = {0}; // Tạo bàn cờ N x N, ban đầu gán tất cả ô là 0

    // Giải bài toán N-Queens
    if (!solveNQueens(board, 0, n)) {
        cout << "Khong co loi giai nao!" << endl;
    }

    return 0;
}
