class Solution {
    public long gcd(long a, long b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    public long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
    public int nthUglyNumber(int N, int A, int B, int C) {
        long n = N;
        long a = A;
        long b = B;
        long c = C;
        
        long l = 1;
        long r = Integer.MAX_VALUE;
        while(l <= r) {
            long mid = l + (r - l) / 2;
            long tps = mid/a + mid/b + mid/c - mid/lcm(a,b) - mid/lcm(a,c) - mid/lcm(b,c) + mid/lcm(a,lcm(b,c));
            if(tps >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return (int)l;
    }
}