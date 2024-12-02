//approch 1: contruct using inorder and preorder
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in = pre;
        sort(in.begin(),in.end());
        int preind=0;
        return build(0,pre.size()-1,pre,in,preind);
    }
    int findidx(vector<int>& in,int l,int r,int val){
        for(int i=l;i<=r;i++){
            if(in[i]==val){
                return i;
            }
        }
        return 0;
    }
    TreeNode* build(int l,int r,vector<int>& pre,vector<int>& in,int &preind){
        if(l>r) return NULL;
        TreeNode *node = new TreeNode(pre[preind]);
        int inind = findidx(in,l,r,pre[preind]);
        preind++;
        node->left =  build(l,inind-1,pre,in,preind);
        node->right = build(inind+1,r,pre,in,preind);
        return node;
    }

};

//sol 2: constuct in O(N)
class Solution {
public:
    map<int,int> mp;
    TreeNode* bstFromPreorder(vector<int>& pre) {
        mp.clear();
        vector<int> in = pre;
        sort(in.begin(),in.end());
        int n = in.size()-1;
        for(int i=0;i<=n;i++){
            // cout<<in[i]<<" ";
            mp[in[i]] = i;
        }
        // cout<<endl;
        // for(auto x: mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        return build(in,0,n,pre,0,n);
    }
    TreeNode* build(vector<int>& in,int instart,int inend,vector<int>& pre,int prestart,int preend){
        if((instart>inend) || (prestart>preend)) return NULL;
        int val = pre[prestart];
        TreeNode *node = new TreeNode(val);
        int inind  = mp[val];
        int left = inind - instart;
        node->left = build(in,instart,inind-1,pre,prestart+1,prestart+left);
        node->right = build(in,inind+1,inend,pre,prestart+left+1,preend);
        return node;
    }
};
//sol 3: using bound 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int preind=0;
        int n = pre.size();
        return  build(pre,INT_MAX,preind,n);
    }
    TreeNode* build(vector<int>& pre,int bound,int &preind,int n){
        if(preind==pre.size() || pre[preind]>bound) return NULL;

        TreeNode* node = new TreeNode(pre[preind++]);

        node->left = build(pre,node->val,preind,n);
        node->right = build(pre,bound,preind,n);
        return node;
    }
};

