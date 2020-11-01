class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    vector<int> visited(row * col, 0);
                    auto itr = word.begin();
                    if (backtrack(board, visited, word, i, j, itr))
                        return true;
                }
            }
        } 
        return false;
    }
    bool backtrack(const vector<vector<char>> &board, vector<int> &visited, 
                   const string &word, int row, int col, string::iterator &itr) {
        if (word.end() == itr)
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) 
            return false;
        bool haspath = false;
        if (!visited[row * board[0].size() + col] && board[row][col] == *itr) {
            ++itr;
            visited[row * board[0].size() + col] = 1;
            haspath = backtrack(board, visited, word, row - 1, col, itr) 
                || backtrack(board, visited, word, row + 1, col, itr)
                || backtrack(board, visited, word, row, col - 1, itr)
                || backtrack(board, visited, word, row, col + 1, itr);
            if (!haspath) {
                --itr;
                visited[row * board[0].size() + col] = 0;
            }
        }
        return haspath;
    }
};
