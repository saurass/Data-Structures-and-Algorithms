/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        long l = 1, r = n;
        while(l <= r) {
            long mid = l + (r - l) / 2;
            if(isBadVersion((int)mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return (int)l;
    }
}