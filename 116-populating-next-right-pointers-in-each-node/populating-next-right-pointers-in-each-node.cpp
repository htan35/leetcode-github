/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> q;
        
//         vector<vector<Node*>> ans;
//         if(root == NULL) return NULL;

//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             vector<Node*> level;
            
//             for(int i=0; i<size;i++){
//                 Node* node = q.front();
//                 q.pop();
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);

//                 level.push_back(node);
//             }
//             ans.push_back(level);
//         }

//         for(int i=0; i<ans.size();i++){
//             for(int j=0;j<ans[i].size();j++){
//                 if(j == ans[i].size() -1){
//                     ans[i][j]->next = NULL;
//                 }
//                 else{
//                     ans[i][j]->next = ans[i][j+1];
//                 }

//             }
//         }
//     return ans[0][0];
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;

        // Traverse down level by level
        while (curr->left) {
            Node* temp = curr;

            // Traverse horizontally across the current level
            while (temp) {
                // 1. Connect left child -> right child
                temp->left->next = temp->right;

                // 2. Connect right child -> adjacent left child (across subtrees)
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }

                // Move to next node in current level
                temp = temp->next;
            }

            // Move to the leftmost node of the next level
            curr = curr->left;
        }

        return root;
    }
};