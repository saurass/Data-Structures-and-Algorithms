class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int> > D(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 or j == 0) {
                    D[i][j] = A[i][j];
                } else {
                    if(A[i][j] == 1)
                        D[i][j] = min(D[i - 1][j], min(D[i][j - 1], D[i - 1][j - 1])) + 1;
                    else
                        D[i][j] = 0;
                }
                
                ans += D[i][j];
            }
        }
        
        return ans;
    }
};