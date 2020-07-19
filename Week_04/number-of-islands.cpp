// 题目描述
// 200. 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。

class Solution {
    void BFS(int x, int y, vector<vector<char>>& grid)
    {
        queue<std::pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty())
        {
            auto curPair = q.front();
            int curX = curPair.first;
            int curY = curPair.second;
            q.pop();
            if (grid[curX][curY] == '0') continue;
            grid[curX][curY] = '0';
            if (curX > 0) q.push(make_pair(curX - 1, curY));
            if (curX + 1 < grid.size()) q.push(make_pair(curX + 1, curY));
            if (curY > 0) q.push(make_pair(curX, curY - 1));
            if (curY + 1 < grid[curX].size()) q.push(make_pair(curX, curY + 1));
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int iRst = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] != '0')
                {
                    iRst++;
                    BFS(i, j, grid);
                }
            }
        }
        return iRst;
    }
};

// 遍历所有网格，遇到非0，计数+1，并搜索周边全部非0，全部设置为0