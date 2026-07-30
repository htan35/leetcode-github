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

//     void check(TreeNode* root, int low, int high, int& maxi,int maxii){
//         if(root == NULL) return;
//         isbst(root, INT_MIN, INT_MAX, maxi, 0);
//         maxi = max(maxi, maxii);
//         check(root->left, INT_MIN, INT_MAX, maxi, maxii);
//         check(root->right, INT_MIN, INT_MAX, maxi, maxii);
//     }

//     bool isbst(TreeNode* node, int low, int high, int& maxi, int& maxii){
//         if(node == NULL) return true;


//         if(node->val <= low || node->val >= high){
//             maxii = 0;
//             return false;
//         }
//         else{
//             maxii += node->val;
//         }
        
//         return isbst(node->left, low, node->val, maxi, maxii) && isbst(node->right, node->val, high, maxi, maxii); 
//     }

//     int maxSumBST(TreeNode* root) {
//         if(root == NULL) return 0;
//         int maxii = 0;
//         int maxi = 0;

//         check(root, INT_MIN, INT_MAX, maxi, maxii);
//         return maxi;
        
//     }
// };

class Nodevalue {
public:
    int maxNode, minNode, sum;

    Nodevalue(int minNode, int maxNode, int sum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};

class Solution {
private:
    int maxSum = 0;
    Nodevalue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return Nodevalue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(currSum, maxSum);


            return Nodevalue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return Nodevalue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root){
        largestBSTSubtreeHelper(root);
        return maxSum;
        
    }
};

