//solution 1: store nodes with x and y in set and sort accordingly
vector <pair<int, pair<int,int> > >  pairs;
   void fun(TreeNode<int> *root,int x,int y){
       if(root==NULL) return;
    //    cout<<x<<" "<<y<<" "<<root->data<<endl;
       pairs.push_back({root->data,{x,y}});
       fun(root->left,x-1,y+1);
       fun(root->right,x+1,y+1);
       
   }
   static bool srt(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
       if(a.second.first==b.second.first && a.second.second==b.second.second) return a.first<b.first;
       else if(a.second.first==b.second.first) return a.second.second<b.second.second;
       return a.second.first<b.second.first;
   }
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	// Write your code here.
    fun(root,0,0);
    sort(pairs.begin(),pairs.end(),srt);
    vector <int> ans;
    for(auto x:pairs)
    {
        // cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
        ans.push_back(x.first);
    }
    
    return ans;
}


//solution 2 : store in map

class Solution {
public:  
    map <int,vector < pair <int,int> > > mp;
    void fun(TreeNode *root,int row,int col)
    {
        if(root==NULL) return;
       // cout<<root->val<<" ";
        mp[col].push_back({row,root->val});
        fun(root->left,row+1,col-1);
        fun(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //cout<<root->val<<" ";
        fun(root,0,0);
        vector <vector <int> > ans(mp.size());
        int i=0;
        for(auto it:mp)
        {
            map <int,vector <int> > temp;
            for(auto x:it.second)
            {
               // cout<<x<<" ";
                temp[x.first].push_back(x.second);
                
            }
            for(auto x:temp)
            {
                sort(x.second.begin(),x.second.end());
                for(auto y:x.second)
                {
                    ans[i].push_back(y);
                }
            }
           
            i++;
        }
        return ans;
    }
};


