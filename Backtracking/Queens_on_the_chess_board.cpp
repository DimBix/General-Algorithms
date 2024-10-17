/*
    Calculate the number of ways n queens can be places on an n x n chess board so that no two queens attack each other.
    
    Time complexity: O(n!)
    Space complexity: O(n)
*/
#include <iostream>
#include <vector>

using namespace std;

class NQueens {
public:
    int totalSolutions = 0;

    void solveNQueens(int n) {
        vector<bool> cols(n, false); // Track columns
        vector<bool> diag1(2 * n, false); // Track main diagonals
        vector<bool> diag2(2 * n, false); // Track anti-diagonals
        backtrack(0, n, cols, diag1, diag2);
    }

    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            totalSolutions++; // Found a valid arrangement
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row - col + n] && !diag2[row + col]) {
                // Place queen
                cols[col] = true;
                diag1[row - col + n] = true;
                diag2[row + col] = true;

                // Recur to place queen in the next row
                backtrack(row + 1, n, cols, diag1, diag2);

                // Backtrack: remove queen
                cols[col] = false;
                diag1[row - col + n] = false;
                diag2[row + col] = false;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of queens (n): ";
    cin >> n;

    NQueens nQueens;
    nQueens.solveNQueens(n);
    cout << "Total solutions for " << n << " queens: " << nQueens.totalSolutions << endl;

    return 0;
}
