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
// class Solution {
// public:
//     void LL(TreeNode* node, TreeNode* &temp){
//         if(node ==  NULL) return;
//         //TreeNode* ll = new TreeNode(node->val);
//         //temp = ll;  
//         // temp ->right = LL(root->left);
//         // temp->right = LL(root->right);
//         temp->right = node;
//         temp->left = NULL;
//         temp = node;

//         LL(node->left, temp);
//         LL(node->right,temp);
//     }
//     void flatten(TreeNode* root) {
//         if(root == NULL) return;

//         TreeNode* head = new TreeNode(-1);
//         TreeNode* temp = head;
//         LL(root,temp);
        
//     }
// };
class Solution {
public:
    void solve(TreeNode* node, TreeNode*& temp) {
        if (!node) return;

        TreeNode* leftChild = node->left;
        TreeNode* rightChild = node->right;

        temp->right = node;
        temp->left = nullptr;
        temp = node; 

        solve(leftChild, temp);
        solve(rightChild, temp);
    }


    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode* dummy = new TreeNode(-1);
        TreeNode* temp = dummy;

        solve(root, temp);
       
    }
};