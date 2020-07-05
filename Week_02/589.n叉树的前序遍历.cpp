/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        ret.push_back(root->val);
        for (auto& c : root->children) {
            vector<int> pre = preorder(c);
            ret.insert(ret.end(), pre.begin(), pre.end());
        }
        return ret;
    }
};
// @lc code=end

