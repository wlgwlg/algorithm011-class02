// 题目描述
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

class Solution {
public:
    void pickNum(vector<int>& pick, vector<int> nums, vector<vector<int>>& rst)
    {
        if (nums.size() == 0)
        {
            rst.push_back(pick);
            return;
        }
        for (auto itr = nums.begin(); itr != nums.end(); ++itr)
        {
            int iCur = *itr;
            pick.push_back(iCur);
            itr = nums.erase(itr);
            pickNum(pick, nums, rst);
            pick.pop_back();
            nums.insert(itr, iCur);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int> pick;
        pickNum(pick, nums, rst);
        return rst;
    }
};

// 采用递归方法处理
// 1. 停止条件：当前处理数组为空，记录结果；
// 2. 数据处理部分：遍历当前处理数组；
// 3. 探入下一层：移除当前游标数据后，进入下一层递归，结束后再插入原位置；