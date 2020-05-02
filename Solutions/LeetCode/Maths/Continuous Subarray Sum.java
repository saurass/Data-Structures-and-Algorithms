class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        m.put(0, -1);
        
        int sm = 0;
        for(int i = 0; i < n; i++) {
            sm += nums[i];
            if(k != 0)
                sm %= k;
            if(m.containsKey(sm)) {
                if(i - m.get(sm) > 1)
                    return true;
            } else {
                m.put(sm, i);
            }
        }
        
        return false;
        
    }
}