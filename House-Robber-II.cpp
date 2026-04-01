1class Solution {
2public:
3
4    int solve(int i, int end, vector<int>& nums, vector<int>& dp) {
5
6        if(i > end) return 0;
7
8        if(dp[i] != -1) return dp[i];
9
10        int take = nums[i] + solve(i+2, end, nums, dp);
11        int notTake = solve(i+1, end, nums, dp);
12
13        return dp[i] = max(take, notTake);
14    }
15
16    int rob(vector<int>& nums) {
17
18        int n = nums.size();
19        if(n == 1) return nums[0];
20
21        vector<int> dp1(n, -1);
22        int case1 = solve(0, n-2, nums, dp1);
23
24        vector<int> dp2(n, -1);
25        int case2 = solve(1, n-1, nums, dp2);
26
27        return max(case1, case2);
28    }
29};