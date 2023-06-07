#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    int rev = 0,og = n;
		    while(n>0){
		        int r = n%10;
		        rev = rev *10 + r;
		        n/=10;
		    }
		    if(rev==og) return "Yes";
		    return "No";
		}
};