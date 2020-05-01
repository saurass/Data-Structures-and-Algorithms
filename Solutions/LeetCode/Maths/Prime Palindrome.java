/*
https://leetcode.com/problems/prime-palindrome/
*/

class Solution {
    
    public boolean isPrime(int A) {
        if(A == 1)
            return false;
        for(int i = 2; i * i <= A; i++) {
            if(A % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    public int primePalindrome(int N) {
        if(N == 1) {
            return 2;
        }
        if(N >= 8 && N <= 11) {
            return 11;
        }
        
        // generate each possible palindrome and check if prime
        for(int i = 1; i < 2000000; i++) {
            String s1 = String.valueOf(i);
            StringBuilder s2 = new StringBuilder();
            s2.append(s1);
            s2 = s2.reverse();
            String s0 = s1 + s2.substring(1);
            int tpi = Integer.parseInt(s0);
            if(tpi >= N && isPrime(tpi)) {
                return tpi;
            }
        }
        return -1;
    }
}