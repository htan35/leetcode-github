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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long mini = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < sz; i++) {
                unsigned long long cur = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = cur;
                if (i == sz - 1) last = cur;

                if (node->left)
                    q.push({node->left, 2 * cur + 1});

                if (node->right)
                    q.push({node->right, 2 * cur + 2});
            }

            ans = max(ans, (long long)(last - first + 1));
        }

        return (int)ans;
    }
};