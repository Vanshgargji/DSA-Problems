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
    void solve(TreeNode* root, int &temp, int &result){
        if(!root) return;
        if(!root->left && !root->right){
            result += temp;
            return;
        }

        if(root->left){
            temp = temp * 10 + root->left->val;
            solve(root->left, temp, result);
            temp = temp / 10;
        } 
        
        if(root->right){
            temp = temp * 10 + root->right->val;
            solve(root->right, temp, result);
            temp = temp / 10;
        } 
        
    }

    int sumNumbers(TreeNode* root) {
        int result = 0;
        int temp;
        
        temp = root->val;
        solve(root, temp, result);
        
        return result;
    }
};