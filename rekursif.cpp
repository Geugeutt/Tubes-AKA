#include "rekursif.hpp"
#include <vector>

using namespace std;

static long long solutions;
static vector<bool> usedCol, diag1, diag2;
static vector<int> board;

void backtrack(int row, int N) {
    if (row == N) {
        solutions++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!usedCol[col] &&
            !diag1[row + col] &&
            !diag2[row - col + (N - 1)]) {

            usedCol[col] =
            diag1[row + col] =
            diag2[row - col + (N - 1)] = true;

            board[row] = col;

            backtrack(row + 1, N);

            usedCol[col] =
            diag1[row + col] =
            diag2[row - col + (N - 1)] = false;
        }
    }
}

long long solveRecursive(int N) {
    usedCol.assign(N, false);
    diag1.assign(2*N - 1, false);
    diag2.assign(2*N - 1, false);
    board.assign(N, -1);

    solutions = 0;
    backtrack(0, N);
    return solutions;
}