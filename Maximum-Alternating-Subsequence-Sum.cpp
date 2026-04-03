1class Solution {
2public:
3    long long solve(int i, bool isEven, vector<int>& nums,vector<vector<long long>>& dp){
4       if(i<0) return 0 ;
5       if(dp[i][isEven]!=-1) return dp[i][isEven];
6        long long notTake=solve(i-1,isEven,nums,dp);
7        long long take;
8
9        if(isEven){
10            take=nums[i]+solve(i-1,false,nums,dp);
11        }
12        else{
13            take=-nums[i]+solve(i-1,true,nums,dp);
14        }
15        return dp[i][isEven]=max(take,notTake);
16    }
17    long long maxAlternatingSum(vector<int>& nums) {
18        long long n=nums.size();
19        vector<vector<long long>> dp(n, vector<long long>(2,-1));
20        return solve(n-1,true,nums,dp);
21    }
22};