#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    queue <pair<TreeNode<int> *, int>  > q;
    q.push({root, 0});
    vector <int> ans;
    map <int,int> mp;
    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){
             TreeNode<int> * node = q.front().first;
             int width = q.front().second;
            //  cout<<width<<" "<<node->data<<endl;
            q.pop();
            if(mp.find(width)==mp.end()) mp[width] = node->data;
            if(node->left!=NULL) q.push({node->left,width-1});
            if(node->right!=NULL) q.push({node->right,width+1});

        }
    }
    for(auto x:mp) {
        // cout<<x.first<<" "<<x.second<<endl;
        ans.push_back(x.second);
    }
    return ans;
}
