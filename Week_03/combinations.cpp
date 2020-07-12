// 题目描述
// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

class Solution {
public:
    void pickNum(int iBegin, int iEnd, int k, vector<int>& pick, vector<vector<int>>& rst)
    {
        if (k == 0)
        {
            rst.push_back(pick);
            return;
        }
        if (iEnd - iBegin + 1 < k)
        {
            return;
        }
        for (int iPickCur = iBegin; iPickCur <= iEnd; ++iPickCur)
        {
            pick.push_back(iPickCur);
            pickNum(iPickCur + 1, iEnd, k - 1, pick, rst);
            pick.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rst;
        vector<int> pick;
        pickNum(1, n, k, pick, rst);
        return rst;
    }
};

// 采用回溯方法处理
// 1. 停止条件：剩余待处理的范围数据个数不足需求(减少递归次数)；
// 2. 数据处理部分：提取当前点或不提取；
// 3. 探入下一层：起始位置加1，进入下一层；
// 注意： 提取后判断下是否足够，若足够记录正确答案，且不再以提取后的数据进行递归；