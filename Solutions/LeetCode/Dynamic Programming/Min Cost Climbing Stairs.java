class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] play = cost;
        for(int i = 2; i < cost.length; i++) {
            play[i] += Math.min(cost[i - 1], cost[i - 2]);
        }
        return Math.min(play[cost.length - 1], play[cost.length - 2]);
    }
}