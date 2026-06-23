class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q; // {node, parent}
        q.push({root, nullptr});

        while(!q.empty()) {
            int size = q.size();

            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;

            for(int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if(node->val == x) xParent = parent;
                if(node->val == y) yParent = parent;

                if(node->left)
                    q.push({node->left, node});

                if(node->right)
                    q.push({node->right, node});
            }

            // Found both at the same level
            if(xParent && yParent)
                return xParent != yParent;

            // Found exactly one at this level
            if(xParent || yParent)
                return false;
        }

        return false;
    }
};