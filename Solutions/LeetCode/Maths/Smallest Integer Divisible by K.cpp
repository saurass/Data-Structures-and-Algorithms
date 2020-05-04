class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<int> s;
        int u = 1;
        
        int i = 1;
        while(1) {
            if(u % k == 0) {
                return i;
            } else {
                int rmd = u % k;
                if(s.count(rmd) == 0) {
                    s.insert(rmd);
                    u = rmd * 10 + 1;
                } else {
                    return -1;
                }
            }
                
            i++;
        }
        
        return -1;
    }
};