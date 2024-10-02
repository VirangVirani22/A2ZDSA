//basic : O(N^2)
class Solution {
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preind=0;
        return build(preorder,inorder,preind,0,inorder.size()-1);
    }
   
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &preind,int l,int r) {
        
        cout<<l<<" "<<r<<endl;
        if(l>r) return NULL;
        cout<<preind<<endl;
        
        int rootIndex = 0;
        for(int i=l;i<=r;i++){
            if(inorder[i]==preorder[preind]){
                rootIndex = i;
                break;
            }
        }
        TreeNode *node  = new TreeNode(inorder[rootIndex]);
        preind++;
        node->left = build(preorder,inorder,preind,l,rootIndex-1);
        node->right = build(preorder,inorder,preind,rootIndex+1,r);
        return node;


    }
};


//optimized : O(N) with space O(N)
class Solution {
public:
    map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder,int instart,int inend, vector<int>& preorder,int prestart,int preend){
        cout<<instart<<" "<<inend<<" "<<prestart<<" "<<preend<<endl;
        if(instart>inend || prestart>preend) return NULL;
        cout<<"executed"<<endl;
        TreeNode *node = new TreeNode(preorder[prestart]);
        int inind = mp[preorder[prestart]];
        int left = inind - instart;
        node->left = build(inorder,instart,inind-1,preorder,prestart+1,prestart+left);
        node->right = build(inorder,inind+1,inend,preorder,prestart+left+1,preend);
        return node;
    }
};