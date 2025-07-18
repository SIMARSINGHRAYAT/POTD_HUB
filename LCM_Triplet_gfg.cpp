class Solution {
  public:
    
    long long gcd(long long a, long long b){
        return b == 0 ? a : gcd(b,a%b);
    }
    
    long long lcm(long long a, long long b){
        return (a/gcd(a,b)) * b;
    }
    
    long long lcmOfThree(long long a, long long b, long long c){
        return lcm(a, lcm(b,c));
    }
    
    long long lcmTriplets(int n) {
        // code here
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 6;
        
        long long ans = 0;
        
        for(int i=n; i >= max(1, n-3); i--){
            for(int j = i - 1; j >= max(1, n -3); j--){
                for(int k = j-1; k >= max(1,n-3); k--){
                    ans = max(ans, lcmOfThree(i, j , k));
                }
            }
        }
        return ans;
    }
};
