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
    bool check(TreeNode* r1, TreeNode* r2) {
        // Both nodes are NULL
        if (r1 == NULL && r2 == NULL)
            return true;

        // One is NULL and the other is not
        if (r1 == NULL || r2 == NULL)
            return false;

        // Values don't match
        if (r1->val != r2->val)
            return false;

        // Check mirror subtrees
        return check(r1->left, r2->right) &&
               check(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return check(root->left, root->right);
    }
};