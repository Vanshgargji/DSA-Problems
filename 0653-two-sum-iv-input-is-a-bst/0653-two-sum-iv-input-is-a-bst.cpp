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
    void solve(TreeNode *root, int k, vector<int> &inorder){
        if(!root) return;

        solve(root->left, k, inorder);
        inorder.push_back(root->val);
        solve(root->right, k, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        solve(root, k, inorder);
        
        int size = inorder.size();
        int l = 0 , r = size - 1;

        while(l < r){
            if(inorder[l] + inorder[r] == k) return true;

            if(inorder[l] + inorder[r] > k) r--;
            else l++;
        }

        return false;
    }
};