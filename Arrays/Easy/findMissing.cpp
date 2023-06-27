//bruteforce : o(N^2)

//better : using hashing

//optimal : using sum

int missingNumber(int a[], int n)
{
    // Your code goes here
    int sum = (n*(n+1))/2;
    //int asum=0;
    for(int i=0;i<n-1;i++) sum-=a[i];
    return sum;
}

//using xor

int missingNumber(int a[], int n)
{
    // Your code goes here
   int xr = n;
   for(int i=0;i<n-1;i++){
       xr ^= a[i];
       xr ^= (i+1);
   }
   return xr;
}