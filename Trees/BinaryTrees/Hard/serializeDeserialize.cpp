#include <bits/stdc++.h>
 #include <sstream>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        // ans+=to_string(root->val);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node!=NULL){
                    ans+=to_string(node->val);
                    ans+=',';
                    q.push(node->left);
                    q.push(node->right);
                }
                else{
                    ans+="#,";
                }
            }
        }
        cout<<ans;
        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str!="#"){
                node->left = new TreeNode(stoi(str));
                 q.push(node->left);
            }
            getline(s, str, ',');
            if(str!="#"){
                node->right = new TreeNode(stoi(str));

            
                q.push(node->right);
            }


        }
        return root;
    }
};