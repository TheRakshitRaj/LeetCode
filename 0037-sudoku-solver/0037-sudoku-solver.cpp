class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>>& sudoku, int val) {
        for (int i = 0; i < 9; i++) {
            if (sudoku[row][i] == val || sudoku[i][col] == val) {
                return false;
            }
            if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>>& sudoku) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (sudoku[row][col] == 0) {
                    for (int val = 1; val <= 9; val++) {
                        if (isSafe(row, col, sudoku, val)) {
                            sudoku[row][col] = val;
                            if (solve(sudoku)) return true;
                            sudoku[row][col] = 0; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> sudoku(9, vector<int>(9, 0));

        // Convert char board to int sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') sudoku[i][j] = 0;
                else sudoku[i][j] = board[i][j] - '0';
            }
        }

        // Solve
        solve(sudoku);

        // Convert back to char board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = sudoku[i][j] + '0';
            }
        }
    }
};
