//with two stacks
// reverse of postorder = root,right,left
// similar to root,left,right preorder
#include <bits/stdc++.h>
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    stack <TreeNode *> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left!=NULL){
            s1.push(node->left);
        }
        if(node->right!=NULL){
            s1.push(node->right);
        }
        
    }
    vector <int> ans;
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;

}
//with one stack O(2N)
#include<bits/stdc++.h>
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    TreeNode *cur = root;
    vector <int> ans;
    stack<TreeNode *> s;
    while(cur!=NULL || !s.empty()){
        if(cur!=NULL){
            s.push(cur);
            cur = cur->left;
        }else{
            TreeNode *temp = s.top()->right;
            if(temp==NULL){
                temp = s.top();
                ans.push_back(temp->data);
                s.pop();
                while(!s.empty() && s.top()->right==temp){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);

                }

            }else{
                cur = temp;
            }
        }
        
    }
    return ans;
}