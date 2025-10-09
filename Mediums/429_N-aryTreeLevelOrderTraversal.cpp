/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return vector<vector<int>>();
        }
        queue<Node*> q; 
        q.push(root);
        vector<vector<int>> ans;
        vector<int> cur;
        q.push(NULL);
        while(1<q.size()){
            if(q.front()==NULL){
                ans.push_back(cur);
                cur=vector<int>();
                q.pop();
                q.push(NULL);
            }
            else{
                cur.push_back(q.front()->val);
                for(auto next : q.front()->children){
                    q.push(next);
                }
                q.pop();
            }
        }
        ans.push_back(cur);
        return ans;
    }
};
