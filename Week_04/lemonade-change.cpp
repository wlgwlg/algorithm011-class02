// 题目描述
// 860. 柠檬水找零
// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
// 顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
// 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
// 注意，一开始你手头没有任何零钱。
// 如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int iFive = 0;
        int iTen = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            int iChange = bills[i] - 5;
            if (bills[i] == 5)
            {
                iFive++;
            }
            else if (bills[i] == 10)
            {
                if (iFive <= 0) return false;
                iFive--, iTen++;
            }
            else if (bills[i] == 20)
            {
                if (iTen > 0 && iFive > 0) iFive--, iTen--;
                else if (iFive > 2) iFive -= 3;
                else return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

// 贪心算法处理
// 记录收到的钱，收到20时有10元优先找10元