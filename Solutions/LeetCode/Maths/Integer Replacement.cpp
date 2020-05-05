class Solution {
public:
    long long int vld(long long int n) {
        long long int ans = 0;
        while(n != 1) {
            ans++;
            if(n % 2 == 0) {
                n /= 2;
            } else {
                return ans + min(vld(n - 1), vld(n + 1));
            }
        }
        
        return ans;
    }
    
    int integerReplacement(int n) {
        return (int)vld((long long int)n);
        
    }
};