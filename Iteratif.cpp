#include "iteratif.hpp"
#include <vector>
#include <stack>

using namespace std;

long long solveIterative(int N) {
    vector<bool> usedCol(N, false);
    vector<bool> diag1(2*N - 1, false);
    vector<bool> diag2(2*N - 1, false);
    vector<int> board(N, -1);

    stack<State> st;
    long long solutions = 0;

    st.push({0, 0});

    while (!st.empty()) {
        State &cur = st.top();
        int row = cur.row;
        bool placed = false;

        for (int col = cur.col; col < N; col++) {
            //pengecekan if di sini yang paling sering dieksekusi
            if (!usedCol[col] && !diag1[row + col] && !diag2[row - col + (N - 1)]) {
                usedCol[col] = diag1[row + col] = diag2[row - col + (N - 1)] = true;

                board[row] = col;
                cur.col = col + 1;
                st.push({row + 1, 0});
                placed = true;
                break;
            }
        }

        if (!placed) {
            st.pop();
            //mundur kalo di baris itu tidak ditemukan posisi yang valid untuk menempatkan ratu
            if (!st.empty()) {
                int prevRow = st.top().row;
                int prevCol = board[prevRow];

                usedCol[prevCol] = diag1[prevRow + prevCol] = diag2[prevRow - prevCol + (N - 1)] = false;
            }

            if (row == N) {
                solutions++;
            }
        }
    }

    return solutions;
}