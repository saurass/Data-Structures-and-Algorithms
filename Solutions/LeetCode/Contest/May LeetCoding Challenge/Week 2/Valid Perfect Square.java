class Solution {
    public boolean isPerfectSquare(int num) {
        for(long i = 1; i * i <= (long)num; i++) {
            if(num % i == 0 && i * i == (long)num)
                return true;
        }
        return false;
    }
}