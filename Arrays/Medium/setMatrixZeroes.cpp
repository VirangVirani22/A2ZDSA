//brute-force : O(n^3)

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    for(int k=0;k<n;k++) if(matrix[k][j]!=1) matrix[k][j]  = -1;
                    for(int k=0;k<m;k++) if(matrix[i][k]!=1)  matrix[i][k]  = -1;
                }
            }
        }
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j] = 1;
                }
            }
        }
        
    }
};

//better : O(N^2) space : O(N)
class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here
        int n = matrix.size(),m = matrix[0].size();
        int row[m],col[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    row[j] = 1;
                    col[i] = 1;
                }
            }
        }
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[j]==1 || col[i]==1){
                    matrix[i][j] = 1;
                }
            }
        }
        
    }
};

//optinmal : without space
class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here
        int n = matrix.size(),m = matrix[0].size();
        int row0 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(j!=0)
                    matrix[0][j] = 1;
                    else
                    row0 = 1;
                    matrix[i][0] = 1;
                }
            }
        }
       
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
              if(matrix[0][j]==1 || matrix[i][0]==1) matrix[i][j] = 1;  
            }
        }
        if(matrix[0][0]==1) for(int i=0;i<m;i++) matrix[0][i] =1 ;
        if((row0==1)) for(int i=0;i<n;i++) matrix[i][0] = 1;
        
    }
};
