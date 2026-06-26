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
    unordered_map<TreeNode *, TreeNode *> parent;
    TreeNode *target = NULL;

    void inorder(TreeNode *root, int start){
        if(!root) return;

        if(root->val == start) target = root;

        if(root->left) parent[root->left] = root;
        inorder(root->left, start);

        if(root->right) parent[root->right] = root;
        inorder(root->right, start);
    }

    void bfs(TreeNode *target, int &time){
        queue<TreeNode *> q;
        q.push(target);

        set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();

            while(n--){
                TreeNode *node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left->val)){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }

                if(node->right && !visited.count(node->right->val)){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }

                if(parent[node] && !visited.count(parent[node]->val)){
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
            }

            time++;
        }
        
    }

    int amountOfTime(TreeNode* root, int start) {
        inorder(root, start);

        int time = 0;
        bfs(target, time);

        return time - 1;
    }
};