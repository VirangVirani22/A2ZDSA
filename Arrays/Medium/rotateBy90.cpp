//clockwise 

//bruteforce : using extra space write i,j for both matrix for idea
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        vector < vector <int> > m(n,vector <int>(n) );
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            m[j][n-1-i] = mat[i][j];
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            mat[i][j] = m[i][j];
        } 
       
    }
};

//optimal 
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
       
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            swap(mat[i][j],mat[j][i]); 
        } 
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        } 
       
    }
};


//anti-clock wise

//space
class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        vector <vector<int> > ans(n,vector <int> (n));
        for(int i=0;i<n;i++){
            for( int j=0;j<n;j++){
                ans[n-1-j][i] = matrix[i][j];
            } 
        }
        for(int i=0;i<n;i++){
            for( int j=0;j<n;j++){
                matrix[i][j] = ans[i][j];
            } 
        }
        
        
    } 
};

//optimal

class Solution
{   
    public:
    void rev(vector<vector<int> >& matrix,int i,int n){
        int a=0,b=n-1;
        while(  a<b){
            swap(  matrix[a][i],matrix[b][i]);
            a++;
            b--;
        }
    }
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 

        for(int i=0;i<n;i++){
            for( int j=i+1;j<n;j++){
                swap( matrix[i][j], matrix[j][i]);
            } 
        }
        for(int i=0;i<n;i++){
            rev(matrix,i,n);
        }
        
        
    } 
};