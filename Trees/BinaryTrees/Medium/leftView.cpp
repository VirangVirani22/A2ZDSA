#include <bits/stdc++.h>
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    queue <BinaryTreeNode<int> * > q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int s = q.size();
        int f = false;
        for(int i=0;i<s;i++){
            auto node = q.front();
            q.pop();
            if(!f) {
                ans.push_back(node->data);
                f=true;
            }
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);

        }
    }
    return ans;
}
//solution 2
#include <bits/stdc++.h>
vector <int> ans;
void fun(BinaryTreeNode<int>* root,int level){
    if(root==NULL)  return;
    if(ans.size()==level) ans.push_back(root->data);
    fun(root->left,level+1);
     fun(root->right,level+1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    fun(root,0);
    return ans;
}


