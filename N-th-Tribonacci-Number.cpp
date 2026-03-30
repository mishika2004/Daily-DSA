1class Solution {
2public:
3    vector<int> dp;
4    int solve(int n) {
5       if(n==0) return 0;
6       if(n==1 || n==2) return 1;
7        if(dp[n] !=-1) return dp[n];
8    
9       return dp[n]= solve(n-1)+solve(n-2)+solve(n-3);
10    }
11    int tribonacci(int n){
12        dp.resize(n+1,-1);
13        return solve(n);
14    }
15};