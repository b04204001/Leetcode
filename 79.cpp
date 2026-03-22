//優解
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // 1. 成功條件
        if (k == word.size()) return true;

        // 2. 邊界 or 不匹配
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[k]) {
            return false;
        }

        // 3. 標記（避免重複使用）
        char temp = board[i][j];
        board[i][j] = '#';

        // 4. 四方向 DFS
        bool found = dfs(board, word, i+1, j, k+1) ||
                     dfs(board, word, i-1, j, k+1) ||
                     dfs(board, word, i, j+1, k+1) ||
                     dfs(board, word, i, j-1, k+1);

        // 5. 回溯（復原）
        board[i][j] = temp;

        return found;
    }
};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // 從每個點當起點
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
