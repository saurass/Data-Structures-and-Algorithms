class Solution {
    public int findComplement(int num) {
        int ans = 0;
        for(int i = 0; i < 32 && (num >> i) != 0; i++) {
            if(((num >> i) & 1) == 1) {
                // System.out.println("woof");
            } else {
                // System.out.println("here");
                ans = ((1 << i) | ans);
            }
        }
        
        return ans;
    }
}