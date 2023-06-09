#include <bits/stdc++.h>
using namespace std;
class Solution1 {
  public:
    void printSquare(int n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<"* ";
            cout<<endl;
        }
    }
};

class Solution2 {
  public:
    void printTriangle(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};

class Solution3 {
  public:
    void printTriangle(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<j+1<<" ";
            }
            cout<<endl;
        }
    }
};

class Solution4 {
  public:
    void printTriangle(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }
};

class Solution5 {
public:
	
	void printTriangle(int n) {
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<(n-i);j++)
	       {
	           cout<<"* ";
	       }
	       cout<<endl;
	   }
	}
};

class Solution6 {
public:
	
	void printTriangle(int n) {
	    for(int i=0;i<n;i++)
	    {
	        for(int j=1;j<n-i+1;j++){
	            cout<<j<<" ";
	        }
	        cout<<endl;
	    }
	}
};

class Solution7 {
  public:
    void printTriangle(int n) {
        // code here
        int cols = 2*n -1;
        int cnt  = 1;
        for(int i=0;i<n;i++)
        {
            int rem = cols - cnt;
            rem/=2;
            for(int j=0;j<rem;j++) cout<<" ";
            for(int j=0;j<cnt;j++) cout<<"*";
            // for(int j=0;j<rem;j++) cout<<" ";
            cout<<endl;
            cnt+=2;
        }
    }
};

class Solution8 {
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++) cout<<" ";
	        for(int j=0;j<((n-i)*2 - 1);j++) cout<<"*";
	        cout<<endl;
	    }
	}
};

class Solution9 {
  public:
    void printDiamond(int n) {
        // code here
        for(int i=1;i<=2*n;i++){
            if(i<=n){
                for(int j=1;j<=(n-i);j++) cout<<" ";
                for(int j=1;j<=i;j++) cout<<"* ";
            }else{
                for(int j=1;j<=(i-n-1);j++) cout<<" ";
                for(int j=1;j<=(n-(i-n)+1);j++) cout<<"* ";
            }
            cout<<endl;
        }
    }
};

class Solution10 {
public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++)
        {
           for(int j=0;j<i;j++) cout<<"* ";
           cout<<endl;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++) cout<<"* ";
            cout<<endl;
        }
    }
};

class Solution11 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++)
        {
            if(i%2==0){
                int k = 1;
                for(int j=0;j<=i;j++){
                    cout<<k<<" ";
                    k = 1 - k;
                }
            }else{
                int k = 0;
                for(int j=0;j<=i;j++){
                    cout<<k<<" ";
                    k = 1 - k;
                }
            }
            cout<<endl;
        }
    }
};

class Solution12 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<j<<" ";
            }
            for(int j=1;j<=(2*n-2*i);j++){
                cout<<"  ";
            }
            for(int j=i;j>=1;j--){
                cout<<j<<" ";
            }
            cout<<endl;
            
        }
    }
};

class Solution13 {
  public:
    void printTriangle(int n) {
        // code here
        int c=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<c++<<" ";
            }
            cout<<endl;
        }
    }
};

class Solution14 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<char('A'+j);
            }
            cout<<endl;
        }
    }
};

class Solution15 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-i);j++){
                cout<<char('A'+j);
            }
            cout<<endl;
        }
    }
};

class Solution16 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<char('A'+i);
            }
            cout<<endl;
        }
    }
};

class Solution17 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-i-1);j++){
                cout<<" ";
            }
            for(int j=0;j<=i;j++){
                cout<<char('A'+j);
            }
            for(int j=i-1;j>=0;j--){
                cout<<char('A'+j);
            }
            cout<<endl;
        }
    }
};

class Solution18 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<char('A'+(n-j-1))<<" ";
            }
            cout<<endl;
        }
    }
};

class Solution19 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            for(int j=0;j<2*i;j++){
                cout<<" ";
            }
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            for(int j=0;j<2*(n-i-1);j++){
                cout<<" ";
            }
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
            
        }
    }
};

class Solution20 {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            for(int j=0;j<2*(n-i-1);j++){
                cout<<" ";
            }
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
            
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            for(int j=0;j<2*i;j++){
                cout<<" ";
            }
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        
    }
};

class Solution21 {
  public:
    void printSquare(int n) {
        // code here
         // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==n-1 || j==n-1) cout<<"*";
                else cout<<" ";
               
            }
             cout<<endl;
            // if(i==0 || i==n-1){
            //     for(int j=0;j<n;j++) cout<<"*";
            // }else{
            //     cout<<"*";
            //     for(int j=0;j<n-2;j++) cout<<" ";
            //     cout<<"*";
            // }
            // cout<<endl;
        }
    }
};

class Solution22 {
  public:
    void printSquare(int n) {
        // code here
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<2*n-1;j++){
                int up = i;
                int left = j;
                int bottom = 2*n - 2 -i;
                int right = 2*n -2 - j;
                cout<<n-min(min(up,bottom),min(left,right))<<" ";
            }
            cout<<endl;
        }
    }
};