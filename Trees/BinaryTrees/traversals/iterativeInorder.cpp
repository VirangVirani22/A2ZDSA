#include <bits/stdc++.h>
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector <int> ans;
    stack<TreeNode *> s;
    
    TreeNode *node = root;
    while(true){

      if (node != NULL) {
          s.push(node);
          node = node->left;
      } else {
        if (s.empty())  break;
        ans.push_back(s.top()->data);
        node = s.top()->right;
        s.pop();
      }
    }
    return ans;
    
}