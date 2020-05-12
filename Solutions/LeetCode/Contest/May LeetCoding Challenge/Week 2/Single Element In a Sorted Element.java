class Solution {
    boolean verify(int[] nums, int mid) {
        if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            return true;
        return false;
    }
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        int n = nums.length;
        while(l < r) {
            int mid = l + (r - l) / 2;
            // System.out.println(mid);
            if(verify(nums, mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return nums[l];
    }
}