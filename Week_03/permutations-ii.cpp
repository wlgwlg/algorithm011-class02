// 题目描述
// 给定一个可包含重复数字的序列，返回所有不重复的全排列。

class Solution {
public:
    void dfs(int iCur, vector<int>& nums, vector<vector<int>>& rst)
    {
        if (iCur == nums.size() - 1)
        {
            rst.push_back(nums);
            return;
        }
        for (int i = iCur; i < nums.size(); ++i)
        {
            bool bFind = false;
            for (int j = iCur; j < i; ++j)
            {
                if (nums[i] == nums[j])
                {
                    bFind = true;
                    break;
                }
            }
            if (bFind) continue;
            swap(nums[i], nums[iCur]);
            dfs(iCur + 1, nums, rst);
            swap(nums[i], nums[iCur]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> rst;
        dfs(0, nums, rst);
        return rst;
    }
};

// 采用回溯递归方法处理
// 1. 停止条件：当前处理位置已到达数组末尾，记录结果；
// 2. 探入下一层：调整当前位置与遍历位置数据后，进入下一层递归，结束后再将被调整的数据恢复；
// 3. 剪枝处理：在遍历过程中剪枝，如果当前位置数据在前面的遍历中已处理过则不执行递归；