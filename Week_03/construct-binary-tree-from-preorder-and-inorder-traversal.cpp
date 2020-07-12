// 题目描述
// 根据一棵树的前序遍历与中序遍历构造二叉树。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildChildTree(vector<int>& preorder, vector<int>& inorder, int iBegin, int iEnd, int iMove) {
        if (iBegin > iEnd)
        {
            return NULL;
        }
        TreeNode* rst = new TreeNode(preorder[iBegin + iMove]);
        int iSlip = iBegin;
        for (; iSlip < preorder.size(); iSlip++)
        {
            if (inorder[iSlip] == preorder[iBegin + iMove]) break;
        }
        if (iSlip > iBegin)
        {
            rst->left = buildChildTree(preorder, inorder, iBegin, iSlip - 1, iMove + 1);
        }
        if (iSlip < iEnd)
        {
            rst->right = buildChildTree(preorder, inorder, iSlip + 1, iEnd, iMove);
        }
        return rst;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || preorder.size() != inorder.size())
        {
            return NULL;
        }
        return buildChildTree(preorder, inorder, 0, preorder.size() - 1, 0);
    }

};

// 采用分治递归方法处理
// 递归函数返回：以当前给定范围创建出的子树。
// 1. 停止条件：范围起始位置大于结束位置；
// 2. 数据处理部分：以前序遍历范围的第一个点创建树节点，查找到当前范围的分割位置；
// 3. 探入下一层：分别以分割位置的左右两段区间创建左右子树；
// 需要注意，创建左子树时，数据在前序与中序数组中的位置存在一定的偏差；