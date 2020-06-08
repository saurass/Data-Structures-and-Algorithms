class Solution
{
public:
    int n;
    int dp[101][101][101];
    int solve(vector<vector<int>> &A, int lftA, int lftB, int pId)
    {
        if (lftA == 0 and lftB == 0)
        {
            return 0;
        }

        if (dp[lftA][lftB][pId] != -1)
            return dp[lftA][lftB][pId];

        int slA = INT_MAX, slB = INT_MAX;

        if (lftA > 0)
            slA = A[pId][0] + solve(A, lftA - 1, lftB, pId + 1);
        if (lftB > 0)
            slB = A[pId][1] + solve(A, lftA, lftB - 1, pId + 1);

        dp[lftA][lftB][pId] = min(slA, slB);
        return min(slA, slB);
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        n = costs.size() / 2;
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
                for (int k = 0; k <= 100; k++)
                    dp[i][j][k] = -1;
        }
        return solve(costs, n, n, 0);
    }
};