1class Solution {
2public:
3
4    int minFallingPathSum(vector<vector<int>>& grid) {
5        int n=grid.size();
6        for(int i=n-2;i>=0;i--){
7            for(int j=0;j<n;j++){
8                int mini = INT_MAX;
9
10                for(int k=0;k<n;k++){
11                    if(k==j) continue;
12                    mini = min(mini, grid[i+1][k]);
13                }
14                grid[i][j]+=mini;
15            }
16        }
17        int ans=INT_MAX;
18        for(int j=0;j<n;j++){
19            ans=min(ans,grid[0][j]);
20        }
21        return ans;
22    }
23};