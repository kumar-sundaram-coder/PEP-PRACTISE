
//Leetcode 200
class Solution
{
public:
    int numIslands(vector<vector<char>> &board)
    {
        int count = 0;

        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[0].size(); c++)
            {
                if (board[r][c] == '1')
                {
                    count++;
                    dfs(r, c, board);
                }
            }
        }

        return count;
    }
    vector<vector<int>> dir_ = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    bool isValid(int r, int c, vector<vector<char>> &board)
    {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '0' || board[r][c] == '2')
            return false;
        return true;
    }

    int dfs(int sr, int sc, vector<vector<char>> &board)
    {
        int count = 0;
        board[sr][sc] = '2';

        for (int d = 0; d < dir_.size(); d++)
        {
            int r = sr + dir_[d][0];
            int c = sc + dir_[d][1];
            if (isValid(r, c, board))
            {
                count += dfs(r, c, board);
            }
        }
        return count;
    }
};