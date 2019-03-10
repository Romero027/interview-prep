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
    bool isValidBST(TreeNode* root) {
        deque<TreeNode*> dq;
        if(root == NULL) return true;
        TreeNode* pre = nullptr;
        while(root != NULL || !dq.empty()){
            while(root != NULL){
                dq.push_back(root);
                root = root->left;
            }
            root = dq.back();
            dq.pop_back();
            if(pre!=nullptr&&pre->val>=root->val) return false;
            pre = root;
            root = root->right;
        }
        
        return true;
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};