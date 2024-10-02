#include<bits/stdc++.h>
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    stack <TreeNode<int> * > st;
    vector <int> ans;
    st.push(root);
    while(!st.empty()){
        TreeNode<int> * node = st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);
    }
    return ans;
}