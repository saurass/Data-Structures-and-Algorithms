class Solution {
    public int findNthDigit(int n) {
        long tn =  (long)n;
        long i = 1;
        
        while(tn > 0) {
            if(tn - 9 * i * (int)Math.pow(10, i - 1) < 0)
                break;
            tn -= (i * 9 * (int)Math.pow(10, i - 1));
            i++;
        }
        
        long start = (int)Math.pow(10, i - 1);
        long desnum = start - 1 + tn / i;
        if(tn % i != 0)
            desnum++;
        long despos = tn % i;
        
        long desrpos = despos == 0 ? 0 : i - despos + 1;
        long ans = desnum % 10;
        
        while(desrpos-- > 0) {
            ans = desnum % 10;
            desnum /= 10;
        }
        
        return (int)ans;
        
    }
}