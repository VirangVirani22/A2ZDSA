//basic : O(N^2)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postind = postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1,postind);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int l,int r,int &postind){
        cout<<l<<" "<<r<<" "<<postind<<endl;
        if(l>r) return NULL;
        cout<<"e"<<endl;
        TreeNode *node = new TreeNode(postorder[postind]);
        int inind = 0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==postorder[postind]){
                inind = i;
                break;
            }
        }
        postind--;
        
        node->right = build(inorder,postorder,inind+1,r,postind);
        node->left = build(inorder,postorder,l,inind-1,postind);
        return node;
    }
};
//optimized : O(N) with space O(N)
class Solution {
public:
    map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       for(int i=0;i<postorder.size();i++){
        mp[inorder[i]] = i;
       }
       return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend){
        cout<<instart<<" "<<inend<<" "<<poststart<<" "<<postend<<endl;
        if(instart>inend || poststart>postend) return NULL;

        TreeNode *node = new TreeNode(postorder[postend]);
        int inind = mp[postorder[postend]];
        int left = inend - inind;
        node->right = build(inorder,inind+1,inend,postorder,postend-left,postend-1);
        node->left = build(inorder,instart,inind-1,postorder,poststart,postend-left-1);
        return node;

    }
};