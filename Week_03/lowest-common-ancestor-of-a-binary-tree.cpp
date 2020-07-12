// 题目描述
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

class Solution {
public:
    int findNode(TreeNode* cur, TreeNode* p, TreeNode* q, TreeNode*& rst)
    {
        if (rst != NULL || cur == NULL)
        {
            return 0;
        }
        int iFindCur = 0;
        if (cur == p || cur == q)
        {
            iFindCur++;
        }
        iFindCur += findNode(cur->left, p, q, rst);
        iFindCur += findNode(cur->right, p, q, rst);
        if (rst == NULL && iFindCur == 2)
        {
            rst = cur;
        }
        return iFindCur;
    };

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* rst = NULL;
        findNode(root, p, q, rst);
        return rst;
    }
};

// 采用递归方法处理
// 递归函数返回：以当前结点为根的子树内包含要查找两个子节点的情况。
// 1. 停止条件：查找到结果结点，或当前结点为空结点；
// 2. 数据处理部分：判断当前结点，找到计数+1；
// 3. 探入下一层：分别查找左右子节点，返回值累加；
// 4. 判断当前子树是否查找到，若找到设置结果，此处注意判断是否已经找到；