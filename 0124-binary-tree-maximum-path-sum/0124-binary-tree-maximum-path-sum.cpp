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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    // returns the max "downward" path sum starting at node (usable by parent)
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // ignore negative gains from children — treat as 0 (don't include them)
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        // best path THROUGH this node (as the "peak"), using both children
        int priceNewPath = node->val + leftGain + rightGain;
        maxSum = max(maxSum, priceNewPath);

        // return only one side to parent, since a path can't branch both ways upward
        return node->val + max(leftGain, rightGain);
    }
};