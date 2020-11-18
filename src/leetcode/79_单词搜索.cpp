class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0])
                    if (backtrack(board, i, j, word, 0))
                        return true;
            }
        }
        return false;
    }

private:
    string temp;

    bool backtrack(vector<vector<char>> &board, int i, int j, string word, int cur) {
        if (cur == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (word[cur] != board[i][j])
            return false;
        char t = board[i][j];
        board[i][j] = '0'; // visited
        bool res = backtrack(board, i + 1, j, word, cur + 1) || 
                   backtrack(board, i - 1, j, word, cur + 1) ||
                   backtrack(board, i, j + 1, word, cur + 1) ||
                   backtrack(board, i, j - 1, word, cur + 1);
        board[i][j] = t;
        return res;
    }
};
