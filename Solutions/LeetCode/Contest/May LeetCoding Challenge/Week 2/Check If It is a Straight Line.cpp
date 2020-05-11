class Solution {
public:
    #define ld long double
    ld slope(vector<int> &A, vector<int> &B) {
        if((ld)B[0] - (ld)A[0] == 0) {
            return (ld)INT_MAX;
        }
        return ((ld)B[1] - (ld)A[1])/ ((ld)B[0] - (ld)A[0]);
    }
    bool checkStraightLine(vector<vector<int>>& A) {
        unordered_set<ld> s;
        for(int i = 0; i < A.size() - 1; i++) {
            s.insert(slope(A[i], A[i + 1]));
            if(s.size() > 1) {
                return false;
            }
        }
        return true;
    }
};