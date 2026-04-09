1class Solution {
2public:
3    int minFallingPathSum(vector<vector<int>>& matrix) {
4        int n=matrix.size();
5        vector<vector<int>> dp(n, vector<int>(n));
6        for(int i=0;i<n;i++){
7            dp[n-1][i]=matrix[n-1][i];
8        }
9
10        for(int i=n-2; i>=0; i--){
11            for(int j=0;j<n;j++){
12                int down=dp[i+1][j];
13                int left = (j>0) ? dp[i+1][j-1] : INT_MAX;
14                int right = (j<n-1) ? dp[i+1][j+1] : INT_MAX;
15                dp[i][j]=matrix[i][j]+min({down,left,right});
16            }
17        }
18       // int n=matrix.size();
19        int ans=INT_MAX;
20        for(int i=0;i<n;i++){
21            ans=min(ans,dp[0][i]);
22           
23        }
24         return ans;
25    }
26};