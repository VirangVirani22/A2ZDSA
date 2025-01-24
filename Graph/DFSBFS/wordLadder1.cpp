//approch 1 
class Solution {
public:
    int countdiff(string a,string b){
        int cnt = 0;
        int n  = a.length();
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])
                cnt++;
        }
        return cnt;
    }
    int ladderLength(string b, string e, vector<string>& words) {
        vector <int> vis(words.size(),0);
        int n = words.size();
        queue <pair<string,int> > q;
        q.push({b,1});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x.first==e){
                return x.second;
            }
            for(int i=0;i<n;i++){
                if(vis[i]==0 && countdiff(words[i],x.first)==1){
                    q.push({words[i],x.second+1});
                    vis[i] = 1;
                }
            }
        }
        return 0;
    }
};

//approch 2
class Solution {
public:
    int ladderLength(string b, string e, vector<string>& words) {
        unordered_set <string> st(words.begin(),words.end());
        st.erase(b);
        int n = words.size();
        queue <pair<string,int> > q;
        q.push({b,1});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x.first==e){
                return x.second;
            }
            int l = x.first.length();
            string word = x.first;
            for(int i=0;i<l;i++){
                char og = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i] = c;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,x.second+1});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};