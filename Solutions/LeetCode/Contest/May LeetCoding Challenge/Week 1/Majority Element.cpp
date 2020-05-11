class Solution {
public:
    int majorityElement(vector<int>& A) {
        sort(A.begin(), A.end());
        int c = 1, ce = A[0];
        for(int  i = 1; i < A.size(); i++) {
            if(A[i] == ce) {
                c++;
            }
            if(c > A.size() / 2) {
                return ce;
            }
            
            if(A[i] != ce) {
                ce = A[i];
                c = 1;
            }
        }
        
        return ce;
    }
};