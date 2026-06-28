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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(root==NULL) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp){
                s += to_string(temp->val) + ',';
                q.push(temp->left);
                q.push(temp->right);
            }
            else{
                s += "#,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        string st;
        getline(ss,st,',');
        TreeNode* root = new TreeNode(stoi(st));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(!getline(ss,st,',')) break;
            if(st!="#"){
                temp->left = new TreeNode(stoi(st));
                q.push(temp->left);
            }
            if(!getline(ss,st,',')) break;
            if(st!="#"){
                temp->right = new TreeNode(stoi(st));
                q.push(temp->right);
            }
        }
        return root;
    }
};
