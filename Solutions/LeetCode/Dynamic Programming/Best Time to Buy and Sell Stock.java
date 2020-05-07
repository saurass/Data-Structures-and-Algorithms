class Solution {    
    public int maxProfit(int[] prices) {
        int ans = 0, minPrice = Integer.MAX_VALUE, n = prices.length;
        for(int i = 0; i < n; i++) {
            minPrice = Math.min(minPrice, prices[i]);
            ans = Math.max(ans, prices[i] - minPrice);
        }
        
        return ans;
    }
}