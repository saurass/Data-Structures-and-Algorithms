class Solution {
    public int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    public boolean canMeasureWater(int x, int y, int z) {
        if(z > x + y)
            return false;
        return z == x || z == y || z == x + y || z % gcd(x, y) == 0;
    }
}