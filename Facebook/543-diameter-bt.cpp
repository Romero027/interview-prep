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
    int maxD = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxD;
    }
    
    int maxDepth(TreeNode* root) {
        if( !root ) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        maxD = max(maxD, left + right);
        return max(left, right) + 1;
    }
};

