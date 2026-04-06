1class Solution {
2public:
3    int minCostClimbingStairs(vector<int>& cost) {
4        int n=cost.size();
5        vector<int> dp(n+2);
6        dp[n]=0;
7        dp[n+1]=0;
8        for(int i=n-1;i>=0;i--){
9            dp[i]=cost[i]+min(dp[i+1], dp[i+2]);
10        }
11        return min(dp[0],dp[1]);
12    }
13};