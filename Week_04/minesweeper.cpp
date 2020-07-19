// 题目描述
// 529. 扫雷游戏
// 让我们一起来玩扫雷游戏！
// 给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
// 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
// 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
// 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
// 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
// 如果在此次点击中，若无更多方块可被揭露，则返回面板。

class Solution {
    int iRow = 0;
    int iColumn = 0;
    int GetBoundaryMCount(vector<vector<char>>& board, int iX, int iY)
    {
        int iRst = 0;
        if (iX > 0 && iY > 0 && board[iX - 1][iY - 1] == 'M') iRst++;
        if (iX > 0 && board[iX - 1][iY] == 'M') iRst++;
        if (iX > 0 && iY < iColumn - 1 && board[iX - 1][iY + 1] == 'M') iRst++;
        if (iY > 0 && board[iX][iY - 1] == 'M') iRst++;
        if (iY < iColumn - 1 && board[iX][iY + 1] == 'M') iRst++;
        if (iX < iRow - 1 && iY > 0 && board[iX + 1][iY - 1] == 'M') iRst++;
        if (iX < iRow - 1 && board[iX + 1][iY] == 'M') iRst++;
        if (iX < iRow - 1 && iY < iColumn - 1 && board[iX + 1][iY + 1] == 'M') iRst++;
        return iRst;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        iRow = board.size();
        iColumn = board[0].size();
        int iX = click[0];
        int iY = click[1];
        if (board[iX][iY] == 'M')
        {
            board[iX][iY] = 'X';
        }
        else if (board[iX][iY] == 'E')
        {
            queue<std::pair<int, int>> q;
            q.push(make_pair(iX, iY));
            while (!q.empty())
            {
                auto cur = q.front();
                iX = cur.first;
                iY = cur.second;
                q.pop();
                if (board[iX][iY] != 'E') continue;
                int iCountCur = GetBoundaryMCount(board, iX, iY);
                if (iCountCur > 0)
                {
                    board[iX][iY] = '0' + iCountCur;
                    continue;
                }
                board[iX][iY] = 'B';
                if (iX > 0 && iY > 0 && board[iX - 1][iY - 1] == 'E') q.push(make_pair(iX - 1, iY - 1));
                if (iX > 0 && board[iX - 1][iY] == 'E') q.push(make_pair(iX - 1, iY));
                if (iX > 0 && iY < iColumn - 1 && board[iX - 1][iY + 1] == 'E') q.push(make_pair(iX - 1, iY + 1));
                if (iY > 0 && board[iX][iY - 1] == 'E') q.push(make_pair(iX, iY - 1));
                if (iY < iColumn - 1 && board[iX][iY + 1] == 'E') q.push(make_pair(iX, iY + 1));
                if (iX < iRow - 1 && iY > 0 && board[iX + 1][iY - 1] == 'E') q.push(make_pair(iX + 1, iY - 1));
                if (iX < iRow - 1 && board[iX + 1][iY] == 'E') q.push(make_pair(iX + 1, iY));
                if (iX < iRow - 1 && iY < iColumn - 1 && board[iX + 1][iY + 1] == 'E') q.push(make_pair(iX + 1, iY + 1));
            }
        }
        return board;
    }
};

// 当前网格是炸弹，直接标记
// 当前网格未点击且不是炸断，广度优先遍历：查找当前网格周边炸弹数，大于0标记当前为个数，否则标记为B，遍历周边8个网格，为E的入队。
