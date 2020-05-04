class Solution {
public:
    double solve(double x, long n) {
        if(n < 0) {
            return 1.0 / solve(x, -n);
        }
        else if(n == 0) {
            return 1.0;
        }
        else if(n == 1) {
            return x;
        }
        double ret = solve(x, n / 2);
        return ret*ret*solve(x, n % 2);
    }
    
    double myPow(double x, int n) {
        return solve(x, n);
    }
};