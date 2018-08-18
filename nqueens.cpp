using Board = vector<string>;

#define Q 'Q'
#define NQ '.'

bool is_safe(const Board& board, int row, int col) {
    int n_rows = board.size();
    int n_cols = board[0].size();
    // Check this row on left
    for(int j = 0; j < col; j++) {
        if(board[row][j] == Q) {
            return false;
        }
    }
    // Check upper diagonal on left side
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == Q) {
            return false;
        }
    }
    // Check lower diagonal on left side
    for(int i = row, j = col; i < n_rows && j >= 0; i++, j--) {
        if(board[i][j] == Q) {
            return false;
        }
    }

    return true;
}

void rec(Board& board, int col, vector<Board>& result) {
    int n_rows = board.size();
    int n_cols = board[0].size();
    if(col == n_cols) {
        result.push_back(board);
        return;
    }

    for(int i = 0; i < n_rows; i++) {
        if(!is_safe(board, i, col)) {
            continue;
        }

        board[i][col] = Q;
        rec(board, col + 1, result);
        board[i][col] = NQ;
    }
}

vector<Board> solve_n_queens(int n) {
    Board board(n, string(n, NQ));
    vector<Board> result;
    rec(board, 0, result);
    
    return result;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    return solve_n_queens(A);    
}
