// 题目描述
// 874. 模拟行走机器人
// 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
// -2：向左转 90 度
// -1：向右转 90 度
// 1 <= x <= 9：向前移动 x 个单位长度
// 在网格上有一些格子被视为障碍物。
// 第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
// 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
// 返回从原点到机器人的最大欧式距离的平方。

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int iX = 0, iY = 0;
        int iMoveX = 0, iMoveY = 1;
        int iRst = 0;
        set<pair<int, int>> obstacleSet;
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] < 0)
            {
                swap(iMoveX, iMoveY);
                if (commands[i] == -1) iMoveY = -iMoveY;
                else iMoveX = -iMoveX;
            }
            else if (commands[i] > 0)
            {
                int iSteps = commands[i];
                while (iSteps-- > 0 && obstacleSet.find(make_pair(iX + iMoveX, iY + iMoveY)) == obstacleSet.end())
                    iX += iMoveX, iY += iMoveY;
            }
            iRst = max(iRst, iX * iX + iY * iY);
        }
        return iRst;
    }
};

// 使用数据结构处理障碍物数据，加快查询
// 注意是返回过程中的最大值，不是返回最终位置的值