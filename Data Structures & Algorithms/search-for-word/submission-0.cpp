
class Solution {
public:
    set<pair<int,int>> path;

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dfs(board, word, n, m, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word,
             int n, int m, int r, int c, int index)
    {
        if(index == word.length())
        {
            return true;
        }

        if(r < 0 || c < 0 || r >= n || c >= m ||
           board[r][c] != word[index] || path.count({r,c}))
        {
            return false;
        }

        path.insert({r,c});

        bool res = dfs(board, word, n, m, r+1, c, index+1) ||
                   dfs(board, word, n, m, r-1, c, index+1) ||
                   dfs(board, word, n, m, r, c+1, index+1) ||
                   dfs(board, word, n, m, r, c-1, index+1);

        path.erase({r,c});

        return res;
    }
};
