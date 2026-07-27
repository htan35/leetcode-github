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

    // bool checkL(TreeNode* node, int mini, int maxi){
    //     if(node == NULL) return true;


    //     if((node->left->val >= mini && node->left->val >= maxi) || (node->right->val >= maxi && node->right->val <=mini)) {
    //         return false;
    //     }
    //     else{
    //         mini = node->val;
    //     }
    //     return checkL(node->left, mini, maxi) && checkL(node->right, mini,maxi);

    // }
    // bool checkR(TreeNode* node, int mini , int maxi){
    //     if(node == NULL) return true;


    //     if((node->left->val >= mini && node->left->val <= maxi) || (node->right->val <= mini && node->right->val <=maxi)) {
    //         return false;
    //     }
    //     else{
    //         mini = node->val;
    //     }
    //     return checkR(node->left, mini, maxi) && checkR(node->right, mini,maxi);
        
    // }
    bool check(TreeNode* node, long long low, long long high){
        if(node == NULL) return true;

        if(node->val <= low || node->val >= high) return false;
    
        return check(node->left, low, node->val) && check(node->right, node->val, high); 
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        // int mini = INT_MIN;
        // int maxi = INT_MAX;

        // if(root->val < INT_MAX){
        //     maxi = root->val;
        // } 
        // else if(root->val > INT_MIN){
        //     mini = root->val;
        // }

        return check(root, LLONG_MIN, LLONG_MAX) && check(root, LLONG_MIN, LLONG_MAX); 
    }
};