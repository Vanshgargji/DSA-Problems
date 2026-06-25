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
    vector<int> preorderTraversal(TreeNode* root) {
        // TC O(n)        SC O(1)
        vector<int> preorder;
        TreeNode *cur = root;

        while(cur){
            preorder.push_back(cur->val);

            if(!cur->left){
                cur = cur->right;
            }
            else{
                TreeNode *prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    preorder.pop_back();
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
        return preorder;
        
    }
};