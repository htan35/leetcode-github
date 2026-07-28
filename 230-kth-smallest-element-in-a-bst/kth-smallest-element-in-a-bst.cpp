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
    void inorder(TreeNode* node, vector<int>&ino){
        if(node == NULL) return;
        inorder(node->left, ino);
        ino.push_back(node->val);
        inorder(node->right, ino);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ino;
        inorder(root,ino);

        // set<int>s;
        // for(int i=0; i<ino.size();i++){
        //     s.insert(ino[i]);
        // }
        
        return ino[k-1];
        
    }
};