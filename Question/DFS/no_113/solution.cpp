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
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        if (root == nullptr) {
            return res;
        }
        Init(sum);
        vector<int> vec;
        vec.push_back(root->val);
        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            res.push_back(vec);
            return res;
        }
        Dfs(root->left, vec, root->val);
        Dfs(root->right, vec, root->val);
        return res;
    }
private:
    vector<vector<int>> res;
    int mySum;
    
    void Init(int sum)
    {
        res.clear();
        mySum = sum;
    }
    
    void Dfs(TreeNode* node, vector<int> vec, int value)
    {
        if (node == nullptr) {
            return;
        }
        int curr = node->val + value;
        vec.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (curr == mySum) {
                res.push_back(vec);
                return;
            }
        } else {
            Dfs(node->left, vec, curr);
            Dfs(node->right, vec, curr);
        }
        return;
    }
};