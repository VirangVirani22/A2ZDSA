#include<bits/stdc++.h>
unordered_map <BinaryTreeNode<int>* , BinaryTreeNode<int>*> par;
void assignParernt(BinaryTreeNode<int>* root){
    if(root->left){
        par[root->left] = root;
        assignParernt(root->left);
    }
    if (root->right) {
        par[root->right] = root;
        assignParernt(root->right);
    }
}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    assignParernt(root);
    // for(auto x: par){
    //     cout<<x.first->data<<" "<<x.second->data<<endl;
        
    // }
    vector<BinaryTreeNode<int>*> ans;
    int dis = 0;
    queue<BinaryTreeNode<int> * > q;
    map <BinaryTreeNode<int>*, int> vis;
    q.push(target);
    vis[target]  = 1;
    while(!q.empty()){
        int s = q.size();
        if(dis==K) break;
        for(int i=0;i<s;i++){
            auto node =q.front();
            q.pop();
            if(node->left && vis[node->left]==0){
                q.push(node->left);
                vis[node->left] = 1;
            }
              if(node->right && vis[node->right]==0){
                q.push(node->right);
                vis[node->right] = 1;
            }
            if(par[node]!=0 && vis[par[node]]==0){
                q.push(par[node]);
                vis[par[node]]= 1;
            }
        }
        dis++;
    }
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    return ans;

}