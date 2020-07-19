// 题目描述
// 122. 买卖股票的最佳时机 II
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int iRst = 0, i = 0;
        while (++i < prices.size())
            if (prices[i] > prices[i - 1])
                iRst += prices[i] - prices[i - 1];
        return iRst;
    }
};

// 只要后一天比前一天价高，就执行一次交易