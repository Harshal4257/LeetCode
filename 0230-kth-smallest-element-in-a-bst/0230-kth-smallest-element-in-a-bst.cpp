/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int result = 0;
        inorder(root, k, cnt, result);
        return result;
    }
    void inorder(TreeNode* root, int& k, int& cnt, int& result) {
        if(!root) return;

        inorder(root->left, k, cnt, result);
        cnt++;
        if(cnt == k) {
            result =  root->val;
            return;
        }
        inorder(root->right, k, cnt, result);
    }
};