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
private:
    unordered_map<TreeNode*, int> dpMap;
public:
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (dpMap.find(root) != dpMap.end()) {
            return dpMap[root];
        }
        int selected = root->val;
        if (root->left != nullptr) {
            selected += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            selected += rob(root->right->left) + rob(root->right->right);
        }
        int noSelected = rob(root->left) + rob(root->right);
        int prefer = max(selected, noSelected);
        dpMap.emplace(root, prefer);
        return prefer;
    }
};