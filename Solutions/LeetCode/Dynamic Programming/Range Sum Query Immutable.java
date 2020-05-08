class NumArray {
    int[] dp;
    int flag = 0;
    public NumArray(int[] nums) {
        if(nums.length == 0) {
            flag = 1;
        } else {
            dp = new int[nums.length];
            dp[0] = nums[0];
            for(int i = 1; i < nums.length; i++) {
                dp[i] += dp[i - 1] + nums[i];
            }
        }
    }
    
    public int sumRange(int i, int j) {
        if(flag == 1)
            return 0;
        if(i - 1 >= 0)
            return dp[j] - dp[i - 1];
        return dp[j];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */