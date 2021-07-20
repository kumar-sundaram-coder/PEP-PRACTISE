#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for using max(a,b)
#include <climits>   // for using INT_MIN

// 200. Number of Islands
class Solution
{
public:
    int m, n;
    vector<vector<int>> dirA{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int r, int c, vector<vector<char>> &board)
    {
        //mark as visited
        board[r][c] = '$';

        for (int d = 0; d < 4; d++)
        {
            int x = r + dirA[d][0];
            int y = c + dirA[d][1];

            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == '1')
            {
                dfs(x, y, board);
            }
        }
    }

    int numIslands(vector<vector<char>> &board)
    {
        if (board.size() == 0 || board[0].size() == 0)
        {
            return 0;
        }
        m = board.size();
        n = board[0].size();

        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '1')
                {
                    count++;
                    dfs(i, j, board);
                }
            }
        }

        return count;
    }
};

