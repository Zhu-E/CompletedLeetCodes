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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> nums;
        traverse(root, nums);
        if(nums.size()==1){
            return -1;
        }
        return *(++nums.begin());
    }
    void traverse(TreeNode* root, set<int>& nums){
        if(root==NULL){
            return;
        }
        nums.insert(root->val);
        traverse(root->left, nums);
        traverse(root->right, nums);
    }
};
