#include<bits/stdc++.h>
BinaryTreeNode<int>* target;
unordered_map <BinaryTreeNode<int>* , BinaryTreeNode<int>*> par;
void assignParernt(BinaryTreeNode<int>* root,int start){
    if(root->data==start){
        target=root;
    }
    if(root->left){
        par[root->left] = root;
        assignParernt(root->left,start);
    }
    if (root->right) {
        par[root->right] = root;
        assignParernt(root->right,start);
    }
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
     assignParernt(root,start);
      int dis = 0,ans=0;
    queue<BinaryTreeNode<int> * > q;
    map <BinaryTreeNode<int>*, int> vis;
    q.push(target);;
    vis[target]  = 1;
    while(!q.empty()){
        int s = q.size();
       ans=max(ans,dis);
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
    return ans;
}