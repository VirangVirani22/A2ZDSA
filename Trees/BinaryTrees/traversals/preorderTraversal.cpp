#include <bits/stdc++.h>
vector <int> ans;
void preorder(TreeNode<int> * root){
    if(root!=NULL){
        ans.push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    preorder(root);
    return ans;

}