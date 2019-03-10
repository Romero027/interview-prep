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
    int kthSmallest(TreeNode* root, int k) {
        deque<TreeNode*> s;
        if(root == nullptr) return -1;
        while(root!=nullptr||!s.empty()){
            while(root!=nullptr){
                s.push_back(root);
                root = root->left;
            }
            root = s.back();
            s.pop_back();
            if(--k==0) return root->val;
            root = root->right;
        }
        return root->val;
    }
};