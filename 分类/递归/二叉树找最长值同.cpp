/*
����һ�����������ҵ����·�������·���е�ÿ���ڵ������ֵͬ�� 
����·�����Ծ���Ҳ���Բ��������ڵ㡣

ע�⣺�����ڵ�֮���·������������֮��ı�����ʾ��

ʾ�� 1:

����:

              5
             / \
            4   5
           / \   \
          1   1   5
���:

2
ʾ�� 2:

����:

              1
             / \
            4   5
           / \   \
          4   4   5
���:

2
ע��: �����Ķ�����������10000����㡣 ���ĸ߶Ȳ�����1000��

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
