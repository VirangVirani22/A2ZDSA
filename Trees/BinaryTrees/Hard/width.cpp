#include<bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,int> > q;
       q.push({root,0});
       long long ans = 0;
       while(!q.empty()){
        int s = q.size();
        long long l  = LONG_MIN, r  = 0;
        // cout<<s<<endl;
        for(int i=0;i<s;i++){
            auto node = q.front();
            q.pop();
            long long num = node.second;
            // cout<<node.first->val<<" "<<num<<endl;
            l = min(l,num);
            r = max(r,num);
            if(node.first->left) q.push({node.first->left,2*num+1});
            if(node.first->right) q.push({node.first->right,2*num+2});
        }
        if(s>1){
            // cout<<"pos "<<l<<" "<<r<<endl;
            ans = max(ans,r-l+1);
        }
       }
     return ans;
    }
   
};

//this will fail because of integer overflow

//using optimize approch for indexing
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
 #include<bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,long long> > q;
       q.push({root,0});
       long long ans = 0;
       while(!q.empty()){
        int s = q.size();
        long long l  = LONG_MIN, r  = 0;
        long long thislevelmin = q.front().second; // start every level from 0, for that delete min of that level from every index
        // cout<<s<<endl;
        for(int i=0;i<s;i++){
            auto node = q.front();
            q.pop();
            long long num = node.second;
            // cout<<node.first->val<<" "<<num<<endl;
            if(i==0)
                l = num - thislevelmin;
            if(i==s-1)
                r = num - thislevelmin;
            
            if(node.first->left) q.push({node.first->left,2*(num-thislevelmin)+1});
            if(node.first->right) q.push({node.first->right,2*(num-thislevelmin)+2});
        }
       
            ans = max(ans,r-l+1);
        
       }
     return ans;
    }
   
};