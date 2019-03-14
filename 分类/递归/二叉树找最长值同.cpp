/*
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 
这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

*/ 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);              
    return 0;
}();

class Solution {
public:
    int re = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, 0);
        return re;
    }
    int dfs(TreeNode *node, int n) {
        if (node == nullptr)
			return 0;
		int left = dfs(node->left, node->val);
		int right = dfs(node->right, node->val);
		re = max(re, left + right);
		return node->val == n ? max(left, right) + 1 : 0;
    }
};2
