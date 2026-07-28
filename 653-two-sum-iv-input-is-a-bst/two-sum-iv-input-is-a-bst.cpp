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
    void inorder(TreeNode* node, vector<int>& ino){
        if(node == NULL) return;
        inorder(node->left,ino);
        ino.push_back(node->val);
        inorder(node->right, ino);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ino;
        inorder(root, ino);
        int l = 0;
        int r = ino.size()-1;

        while(l<r){
            if(ino[l]+ino[r] == k){
                return true;
            }
            else if(ino[l]+ino[r] < k){
                l++;
            }
            else{
                r--;
            }
        }
    return false;
    }
};