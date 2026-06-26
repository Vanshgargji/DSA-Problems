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
    unordered_map<TreeNode *, TreeNode *> parent;

    void inorder(TreeNode *root){
        if(!root) return;

        if(root->left) parent[root->left] = root;
        inorder(root->left);

        if(root->right) parent[root->right] = root;
        inorder(root->right);
    }

    void bfs(TreeNode *target, int k, vector<int> &result){
        set<int> visited;

        queue<TreeNode *> q;
        q.push(target);

        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();

            if(k == 0) break;

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

            k--;
        }

        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);

        vector<int> result;
        bfs(target, k, result);
        
        return result;
    }
};