#include <bits/stdc++.h>
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector <int> in,pre,post;
    stack < pair<TreeNode*, int> > s;
    s.push({root,1});
    while(!s.empty()){
        TreeNode *node = s.top().first;
        int cnt = s.top().second;
        s.pop();
        if(cnt==1){
            pre.push_back(node->data);
            s.push({node,cnt+1});
            if(node->left!=NULL){
                s.push({node->left,1});
            }
        }else if(cnt==2){
             s.push({node,cnt+1});
            in.push_back(node->data);
            if(node->right!=NULL){
                s.push({node->right,1});
            }
        }else{
             post.push_back(node->data);
        }
    }
    vector <vector <int> >  ans;
    ans.push_back(in);
    ans.push_back(pre);
    
    ans.push_back(post);
    return ans;
}